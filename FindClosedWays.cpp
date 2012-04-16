/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html
  
  This program looks for closed ways. 

  1. any way that ends where it begins.
  2. any way that is self intersecting.
  3. any way that is larger than some size
  4. split out into different files based on some attributes

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  
*/
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/sax2/SAX2XMLReader.hpp>
#include <xercesc/sax2/XMLReaderFactory.hpp>
#include <map>

#if defined(XERCES_NEW_IOSTREAMS)

#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#else
#include <sstream.h>
#include <fstream.h>
#include <iostream.h>
#include <set.h>
#endif
#include <xercesc/util/OutOfMemoryException.hpp>
#include <xercesc/util/XMLFloat.hpp>

// Other include files, declarations, and non-Xerces-C++ initializations.
XERCES_CPP_NAMESPACE_USE

using namespace std;

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>

XERCES_CPP_NAMESPACE_USE

#include "OSMAttributes.h"
#include "Point.hpp"
#include "BBox.hpp"
#include "World.hpp"

#include "Processor.hpp"
#include "NodeProcessor.hpp"
#include "WayProcessor.hpp"
#include "RelProcessor.hpp"
#include "Point.hpp"
#include "PointExtended.hpp"

#include "SAX2OsmHandlers.hpp"
#include "OSMProcessor.hpp"
#include "Tagged.hpp"

int x;
class TaggedPointExtended : public PointExtended, public Tagged
{
public:
  TaggedPointExtended(const Attributes& attrs) 
    :
    Tagged(),
    PointExtended(attrs) // extract the data from the attributes
  {
  }

  TaggedPointExtended(): 
  PointExtended() ,
    Tagged()
  {}

  void emit(ostream &os)
  {
    os <<  "<node " 
       << " id='"<< nid << "'"

       << " lat='"<< dLat << "'"
       << " lon='"<< dLon << "'"
       << " version='1' > " << endl;

    //       << " xid='"<< nid << "'"
    os << "<tag k=\'tmp:xid\' v='" << nid << "'/>" << endl;
    os << "<tag k=\'tmp:ninWay\' v='" << ninWay << "'/>" << endl;
    os << "<tag k=\'tmp:hasDuplicates\' v='" << hasDuplicates << "'/>" << endl;
    os << "<tag k=\'tmp:nisDuplicateOf\' v='" << nisDuplicateOf << "'/>" << endl;
    os << "<tag k=\'tmp:ninWayChecksum\' v='" << ninWayChecksum << "'/>" << endl;

    emittags(os);

    os <<  "</node >"   << endl;
      
  }

};

class TagWorld
{
public:

  typedef TaggedPointExtended TPoint; // the type of point object
  typedef map<TPoint, int> TMapCoordID; // LAT + LONG -> id  
  typedef map<int,TPoint>  TMapIDCoord; // id -> LAT + LONG 
  TMapCoordID   node_coords;// map the lat and long to an id
  TMapIDCoord   node_id_coord;

  typedef map<int, int>  TWayNodeCount; // Number of nodes per way... for a report
  typedef map<string, int>  TTagCount; // name -> count

  typedef map<string, TTagCount>  TTagValues; // the tag values for some attributes. 
  typedef map<int, int>         TMapNodeCount; // id -> count

  int max_id;
  TMapNodeCount node_ids;// have we seen this id?
  TTagCount tags;// how many tags we have
  TTagCount tags_wanted;// how many tags we have
  TTagValues tags_values;// how many tags we have

  int way_length_filter_min; // the length of the way 
  int way_length_filter_max; // the length of the way 
  int way_closed_filter; // the length of the way 

  TWayNodeCount way_node_count;
  ofstream osmoutput;

  TMapIDCoord::iterator  current_node;
  Tagged current_way; // we just store the attributes for the current way.

  void startDocument()  {  
    max_id=0;

    // split by this attribute
    tags_wanted["ELEV"]=1;



    osmoutput << "<?xml version='1.0' encoding='UTF-8'?>" <<endl;
    osmoutput << "<osm version='0.6' generator='OSMTemplates'>"<< endl;
    
  };

  void ReportWayCount()
  {
    TWayNodeCount::iterator iter = way_node_count.begin();
    
    cout << "WAY COUNTs\n";

    while( iter != way_node_count.end() ) 
      {
	cout << "WAY COUNT\t" << iter->first << "\t " << iter->second << endl;
	iter++;
      }    
  }

  void endDocument()  
  {
    cerr << "End of doc" << endl;

    ReportWayCount();

    TTagCount::iterator iter = tags.begin();
    
    while( iter != tags.end() ) 
      {
	cout << "tag\t" << iter->first << "\t " << iter->second << endl;

	TTagCount::iterator iter2 = tags_values[iter->first].begin();
	while( iter2 != tags_values[iter->first].end() ) 
	  {
	    cout << "VALUE\t" << iter->first << "\t" << iter2->first << "\t " << iter2->second << endl;
	    iter2++;
	  }
	iter++;
      }    
    osmoutput << "</osm>"<< endl;
    osmoutput.close();

  };

  void Bound(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {}

};

class TagProcessor : public Processor<TagWorld>
{
  int nodes_in_way;
  int way_closed;
  double elevation;

  typedef set<int>  TWayNodes; //what nodes have we found in the current way

  TWayNodes current_nodes;
  int current_way_id;
  int current_node_id;



  typedef enum current_type
    {
      NT_NONE,
      NT_NODE,
      NT_WAY,
      NT_ND,
      NT_REL,
      NT_TAG
    } t_current_node_type;
  t_current_node_type previous_node_type; 
  t_current_node_type current_node_type; 
public:
  TagProcessor(TagWorld & rW) 
    :Processor<TagWorld>(rW),
     nodes_in_way(0),
     way_closed(0),
     elevation(0.0),
     current_way_id(0),
     current_node_id(0)

  {
  }


  void startRelElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
    current_node_type= NT_REL;
  }


  void startNodeElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
    current_node_id =getId(attrs);

    current_node_type= NT_NODE;

    TagWorld::TMapNodeCount::iterator i = Processor<TagWorld>::world.node_ids.lower_bound(current_node_id);
    
    if ((i != Processor<TagWorld>::world.node_ids.end() ) && ( i->first == current_node_id))
      {	       
	if (i->second ==1)
	  {
	    // only report it once
	    if ( Processor<TagWorld>::report_duplicates)
	      cerr << "error: duplicate nodes ID:" << i->first  << endl;
	  }
	i->second++;
      }
    else
      {

	TagWorld::TMapNodeCount::value_type valt(current_node_id, 1);
	Processor<TagWorld>::world.node_ids.insert(i, valt);
	TaggedPointExtended point(attrs);;
	point.setID(current_node_id);

	// add the point
	Processor<TagWorld>::world.node_id_coord[Processor<TagWorld>::current_id]=point;

	Processor<TagWorld>::world.current_node =Processor<TagWorld>::world.node_id_coord.lower_bound(Processor<TagWorld>::current_id);
    ////
    
	TagWorld::TMapCoordID::iterator c = Processor<TagWorld>::world.node_coords.lower_bound(point);	    // lookup the point
	if (c != Processor<TagWorld>::world.node_coords.end() && ( c->first == point)) // check it
	  {
	    // is the id different? report it.
	    int current_node_id=Processor<TagWorld>::current_id;
	    if(c->second != Processor<TagWorld>::current_id)// we found another point, another id
	      {
		// now store this point as a duplicate of the other, but how many duplicates can we have? many.
		// if we find another way that references this point, but with another id, we need to know. We will mark each node as having duplicates pointing to it. But each duplicate node will point to the first one. 
		// otherwise we cannot merge them.
		//cerr << current_node_id << " is a duplicate of " <<  c->second << endl;
		
		
		TagWorld::TMapIDCoord::iterator e =   Processor<TagWorld>::world.node_id_coord.find(current_node_id);
		if (e != Processor<TagWorld>::world.node_id_coord.end())
		  {
		    e->second.DuplicateOf(c->second);  
		  }
				
		TagWorld::TMapIDCoord::iterator d =   Processor<TagWorld>::world.node_id_coord.find(c->second);
		if (d != Processor<TagWorld>::world.node_id_coord.end())
		  {
		    d->second.Duplicate();
		  }		

	  }
	else
	  {
	    // has the same id, we found it.
	  }
      }
    else
      {
	 TagWorld::TMapCoordID::value_type val(point, current_node_id);
	Processor<TagWorld>::world.node_coords.insert(c, val);	   	  	    
	
      }		    
      }
  }

  void startWayElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
    current_node_type= NT_WAY;
    current_way_id = getId(attrs);

    //cerr << "Current way id:" << current_way_id << endl;

    current_nodes.clear();
    nodes_in_way=0;
    way_closed=0;
    elevation=0.0;

    Processor<TagWorld>::world.current_node= Processor<TagWorld>::world.node_id_coord.end(); // dont need this

  }

  void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
     // processing the way infomation.
     // did we see this node yet?
     // what is the count of the nodes
     int ref = getAttrInt(attrs,OSM::szREF);     
     current_node_type= NT_ND; 

     int modified_ref=ref; // we save the node and overwrite it if we find a new one
 
     TagWorld::TMapIDCoord::iterator i = Processor<TagWorld>::world.node_id_coord.lower_bound(ref);
     if ((i != Processor<TagWorld>::world.node_id_coord.end() ) && ( i->first == ref))
      {
	i->second.WayRef(current_way_id);

	modified_ref = i->second.isDuplicateOf();
	
	if (modified_ref)
	  {
	    TagWorld::TMapIDCoord::iterator j= Processor<TagWorld>::world.node_id_coord.find(modified_ref);
	    if (j !=  Processor<TagWorld>::world.node_id_coord.end())
	      {
		//cerr << "found a node" << ref << "that was a duplicate point of "  << modified_ref << endl;
		j->second.WayRef(current_way_id);
		//cerr << "DUP ID " <<j->first << "\t";
		//		j->second.emit(cerr);
	      }
	    else
	      {
		modified_ref=ref;
		///cerr << "ERROR! found a node" << ref << "that was a duplicate point of "  << modified_ref << endl;
		//		cerr << "ID " <<i->first << "\t";
		//		i->second.emit(cerr);

	      }
	  }
	else
	  {
	    modified_ref=ref;
	    // there is no other point with that address
	    //	    cerr << "not duplicate "  << i->first  << " ref " << ref << " old " << modified_ref << endl;
	  }
      }
    else
      {
	  cerr << "MISSING: " << ref << endl;
      }    

     // now we add the node to the current way list
     if (current_nodes.find(modified_ref) == current_nodes.end())
       {
	 current_nodes.insert(modified_ref);
       }
     else
       {
	 ///cerr << "Duplicate node in way " << modified_ref << endl;
	 way_closed++;
       }

     nodes_in_way++;
   }

  void ProcessTag(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    const XMLCh * xID= 	attrs.getValue (OSM::szK);

    // save the previous type 
    previous_node_type = current_node_type;
    current_node_type=NT_TAG;

    if (!xID)
      {
	cerr << "NO DATA!";
	return; //skip errors
      }

    string val = getAttrStr(attrs,OSM::szV);
    char * nameval  = XMLString::transcode(xID);
    string name(nameval); // hack it!
    XMLString::release(&nameval);  // dont forget forget to delete !
    
    if (Processor<TagWorld>::world.current_node!= Processor<TagWorld>::world.node_id_coord.end())
      {
	Processor<TagWorld>::world.current_node->second.add(name,val);
      }
    else
      {
	Processor<TagWorld>::world.current_way.add(name,val);
      }
          
    if (XMLString::compareIStringASCII(xID, OSM::szELEV) == 0) 
      {		
	elevation=getAttrFloat(attrs,OSM::szV);
      }
    else
      {


	world.tags[name]++;
	
	if (world.tags_wanted[name])
	  {
	    world.tags_values[name][val]++;
	  }
      }
  }

  void emitWay()
  {
    if(current_way_id)
      {
	TWayNodes::iterator itr;
	for (itr = current_nodes.begin(); itr != current_nodes.end(); itr++)
	  {
	TagWorld::TMapIDCoord::iterator i = Processor<TagWorld>::world.node_id_coord.lower_bound(*itr);
	if ((i != Processor<TagWorld>::world.node_id_coord.end() ) && ( i->first == *itr))
	  {
	    i->second.emit( Processor<TagWorld>::world.osmoutput);
	  }
	else
	  {
	    cerr << "ERROR!" << endl;
	  } 
      }

	Processor<TagWorld>::world.osmoutput << "<way id=\'"<< current_way_id << "\' >\n";
	Processor<TagWorld>::world.osmoutput << "<tag k=\'tmp:way_closed\' v='" << way_closed << "'/>" << endl;
	Processor<TagWorld>::world.osmoutput << "<tag k=\'tmp:nodes_in_way\' v='" << nodes_in_way << "'/>" << endl;


    for (itr = current_nodes.begin(); itr != current_nodes.end(); itr++)
      {
	Processor<TagWorld>::world.osmoutput << "<nd ref=\'"<< *itr << "\' />\n";
      }

    Processor<TagWorld>::world.current_way.emittags(Processor<TagWorld>::world.osmoutput);

    Processor<TagWorld>::world.osmoutput << "</way>\n";
      }
  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    Processor<TagWorld>::endElement(  uri,localName, qname );
    if (current_node_type== NT_WAY)
      {
	/// now we check the 
	int simple= nodes_in_way;    // stats on how many nodes we have in this way
	      
	if (( (way_closed > 1) == Processor<TagWorld>::world.way_closed_filter) || (Processor<TagWorld>::world.way_closed_filter == 3))
	  {
	    world.way_node_count[simple]++;
	    way_closed=0;
	    
	    //	    cerr << "way " << current_way_id << " has  nodes " << nodes_in_way << endl;

	    // now we can emit the way if it is interesting.

	    if (
		(nodes_in_way > Processor<TagWorld>::world.way_length_filter_min)
		&&
		(nodes_in_way < Processor<TagWorld>::world.way_length_filter_max)
		)
	      {
		emitWay();
	      }
	    else
	      {
		//		cerr << "way filtered by length: "<< current_way_id << endl;
	      }	
	  }
	else
	  {
	    //	    cerr << "way filtered by close/open: "<< current_way_id << endl;
	  }
	
	current_node_id=0;
	current_way_id=0;
      }
    else if (current_node_type== NT_NODE)
      {
	current_node_id=0;
	
	current_node_type=NT_NONE;
      }
    else if (current_node_type== NT_ND)
      {	
	current_node_type= NT_WAY;
      }
    else if (current_node_type== NT_TAG)
      {	
	current_node_type= previous_node_type;
      }
    else
      {
	//	cerr << "Unknown current_node_type " << current_node_type << endl;
      }
  }


  char getCurrentType(){return 'T';}

  void Member(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {}

};



int main(int argc, char* argv[])
{

  if (argc == 6)
    {
      const char *xmlFile = argv[1];

      cerr << "going to parse:"<<xmlFile << endl;

      TagWorld theWorld;

      // 
      theWorld.way_length_filter_min = atoi(argv[2]); 
      theWorld.way_length_filter_max = atoi(argv[3]); 
      theWorld.way_closed_filter = atoi(argv[4]); 

      cerr << "going to read :"<<xmlFile << endl;
      cerr << "going to write :"<<argv[5] << endl;


      theWorld.osmoutput.open (argv[5]);
      if (!theWorld.osmoutput)
	{
	  cerr << "Could not open output file " << argv[3] << endl;
	  exit(3);
	}


      TOSMProcessorProc<TagWorld,         // the world data
	TagProcessor, // way processor
	TagProcessor, // 
	TagProcessor // rel processor
	>(xmlFile,theWorld);

    }
  else
    {
      cerr << "arguments are inputfile minimumlength maximumlength closed(1/0) outputfile, you passed "<<argc << " arguments";
    }

  // Other terminations and cleanup.
  return 0;
}
