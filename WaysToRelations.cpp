/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  Converts Ways to relations

  1. all points shared by the same set of ways in a row go into a new way. (add ref to old way)
  2. new relation for each way that is a region (counties for my example)
  3. add the new way to relations
  4. remove duplicate nodes as well. each duplicate node is resolved to the old node.

  compile : See Makefile

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
#else
#include <sstream.h>
#include <fstream.h>
#include <iostream.h>
#endif
#include <xercesc/util/OutOfMemoryException.hpp>

// Other include files, declarations, and non-Xerces-C++ initializations.
XERCES_CPP_NAMESPACE_USE

using namespace std;

#include <xercesc/sax2/Attributes.hpp>
#include <xercesc/sax2/DefaultHandler.hpp>

XERCES_CPP_NAMESPACE_USE

#include "OSMAttributes.h"
#include "PointExtended.hpp"
#include "BBox.hpp"
#include "WorldExtended.hpp"
#include "Processor.hpp"
#include "NodeProcessor.hpp"
#include "WayProcessor.hpp"
#include "RelProcessor.hpp"
#include "SAX2OsmHandlers.hpp"
#include "OSMProcessor.hpp"
#include "NodeProcessorShared.hpp"


typedef  WorldExtended  TWorld;

class WayProcessorSplit : public Processor<WorldExtended>
{
  WorldExtended::TPoint * pLast; // just store the last point seen.
public :
  WayProcessorSplit(WorldExtended& w)
    :Processor<WorldExtended>(w),
     pLast(0),
     newSegment(0),
     GlobalId(0), // start adding nodes after the highest one
     FinalNode(0)
  {

  }
  int newSegment;
  int GlobalId;
  int FinalNode;
  int FirstNode;//
  int NodeCount;//
  char getCurrentType( ){ return 'X';}

  void ProcessND(TWorld::TMapIDCoord::iterator i, int xref)
  {
    int ref=xref;
    NodeCount++;

    int oid = i->second.isDuplicateOf();
    if (oid)
      { 
	ref = oid; // use the first id found
      }
    
    if (pLast)      { // we have a previous object in this way
      if (pLast->InSameRel(i->second))
	{	    
	  
	  cout << "<nd ref=\'"<< ref << "\' />"
	       << "<!-- inside same segment";
	  
	  cout << "-->"		      
	       << endl;			
	}
      else	  
	{
	  
	  newSegment++;
	  cout << "<nd ref=\'"<< ref << "\' />"; // add a final leg to previous segment!
	  cout << "</way>" << endl; // end the previous segment
	  GlobalI--; // count down new ids for the ways
	  cout << "<way id=\'"<< GlobalId << "\' version='1' >" << endl;
	  cout << "<tag k=\'SPLIT\' v='DifferentRel'/>" << endl;
	  cout << "<tag k=\'segment\' v='" << newSegment << "'/>" << endl;
	  cout << "<tag k=\'xid\' v='" << GlobalId << "'/>" << endl;

	  cout << "<nd ref=\'"<< ref << "\' />"
	       << "<!-- start of new segment -->"<< endl;
	  
	}
	
    }	    
    else	       // the first part in the way
      {
	GlobalId--;
	newSegment++;
	cout << "<way id=\'"<< GlobalId << "\' version='1'>" << "<!-- First Node in a way -->"<< endl;
	cout << "<tag k=\'xid\' v='" << GlobalId << "'/>" << endl;
	cout << "<nd ref=\'"<< ref << "\'/>" << endl;			

      }

    pLast= &i->second; // store a pointer to the last one seen.

  }
  

  void EmitFinalND()
  {
   
  }

  void EmitFirstND()
  {
    TWorld::TMapIDCoord::iterator i = Processor<TWorld>::world.node_id_coord.lower_bound(FirstNode);
    if ((i != Processor<TWorld>::world.node_id_coord.end() ) && ( i->first == FirstNode))
      {
	cout << "<nd ref=\'"<< FirstNode << "\' />"
	     << "<!-- FirstNode node";
	cout << "-->"		      
	     << endl;			
	
      }

  }

  void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    int ref = Processor<TWorld>::getAttrInt(attrs,OSM::szREF);   
    if (ref <0)
      {
	//	ref = ref * -1;
      }
    int cid =Processor<TWorld>::current_id;    
    TWorld::TMapIDCoord::iterator i = Processor<TWorld>::world.node_id_coord.lower_bound(ref);
    if ((i != Processor<TWorld>::world.node_id_coord.end() ) && ( i->first == ref))
      {
	if(i->second.inWayChecksum() != cid)
	  {
	    // each point is only emitted once!
	    ProcessND( i, ref);
	  }	
	else	  
	  {
	    ProcessND( i, ref);
	  }
      }
    else
      {
      }
  }

  void startWayElement (const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
    int cid =Processor<TWorld>::current_id;
    newSegment=0; // each way, we start counting the segments separatly.
    pLast=0;
    FirstNode=1;
    NodeCount=0;
  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if (localName[0] == OSM::szWAY[0])   {
      // add in the final node to the way list.. if it was left out.
      if (	  newSegment )// we might have duplicate ways with no output!
	{
	  EmitFinalND();
	  cout << "</way>" << endl;
	}
    }
  }

  void startRelElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {

    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
    int cid =Processor<TWorld>::current_id;
    //    cerr << "rel: " << cid << endl;
  } 
  void startNodeElement (const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
    int cid =Processor<TWorld>::current_id;
    //    cerr << "node: " << cid << endl;
    TWorld::TMapIDCoord::iterator e =   Processor<TWorld>::world.node_id_coord.find(cid);
    if (e != Processor<TWorld>::world.node_id_coord.end())
      {
	if(!e->second.isDuplicateOf())
	  {
	    e->second.emit(cout);  
	  }
      }

  } 
  void Member (const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
  } 

};

int main(int argc, char* argv[])
{

  if (argc == 2)
    {
      const char *xmlFile = argv[1];
      TWorld theWorld;
      cerr << "going to read :"<<xmlFile << endl;
      cout << "<?xml version=\'1.0\' encoding=\'UTF-8\'?>" << endl;
      cout << "<osm version=\"0.6\" generator=\"Osmosis 0.30.3\">" << endl;


      TOSMProcessorProc
      	<
      TWorld,         // the world data
      	NodeProcessorShared<TWorld>, // 
      	NodeProcessorShared<TWorld>, // custom way processor
      	NodeProcessorShared<TWorld> // rel processor
      	>(xmlFile,theWorld);

      TOSMProcessorProc
	<
      TWorld,         // the world data
	WayProcessorSplit, // 
	WayProcessorSplit, // custom way processor
	WayProcessorSplit // rel processor
	>(xmlFile,theWorld);


      cout << "</osm>" << endl;
    }
  else
    {
      cerr << "argc:"<<argc;
    }

  // Other terminations and cleanup.
  return 0;
}
