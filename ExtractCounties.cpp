/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  example of fast processing of osm using c++/xerces
  takes an osm file as parameter

  compile : 

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

// constant strings 
static XMLCh szID[]={ chLatin_i, chLatin_d, chNull }; // ID
static XMLCh szK[]={ chLatin_k,  chNull }; // K (key)
static XMLCh szV[]={ chLatin_v,  chNull }; // V (key)
static XMLCh szLON[]={ chLatin_l, chLatin_o, chLatin_n, chNull }; // lon
static XMLCh szLAT[]={ chLatin_l, chLatin_a, chLatin_t, chNull }; // lat


// attribute names are matched differently...
static XMLCh szNAME[]={ chLatin_n, chLatin_a, chLatin_m, chLatin_e, chNull }; // name

#include "OSMAttributes.h"

class Point 
{
  string sKey;
  double dLat;
  double dLon;

public:
  const string & key ()
  {
    return sKey;
  }

  const double & lat () const
  {
    return dLat;
  }

  const double & lon () const
  {
    return dLon;
  }


  void parse(const XMLCh * xLAT, const XMLCh * xLON)
  {
    char * sLAT  = XMLString::transcode(xLAT);
    char * sLON  = XMLString::transcode(xLON);
    // key = "LAT|LON";
    std::ostringstream buffer;
    buffer << sLAT << "|" << sLON;
    sKey = string (buffer.str());    

    dLat=atof(sLAT);
    dLon=atof(sLON);
    // char * pend=sLAT+strlen(sLAT);
    // lat = strtod(sLAT, &pend ); 
    // pend=sLON+strlen(sLON);
    // lon = strtod(sLON, &pend ); 

  }
  
  Point() 
    :
    dLat(0),
    dLon(0)
  {}

  Point(const Attributes& attrs) // extract the data from the attributes
    :dLat(0),
     dLon(0)
  {
    const XMLCh * xLAT= 	attrs.getValue (szLAT);
    const XMLCh * xLON= 	attrs.getValue (szLON);
    parse(xLAT,xLON);
  }
  friend ostream& operator<< (ostream& o, const  Point& p);

  bool operator== ( const  Point& p) const
  {
    return sKey==p.sKey;
  }

  bool operator< ( const  Point& p) const
  {
    return sKey<p.sKey;
  }
  
};

class BBox
{
public:
  struct SPoint
  {
    double lat;
    double  lon;

    SPoint()
      : lat(0),
	lon(0)
    {

    }

    void checkmin(const Point & p)
    {
      if (lat==0)
	{
	  lat=p.lat();
	  lon=p.lon();
	}
      else
	{
	  if ( lat<p.lat())
	    {
	      lat=p.lat();
	    }
	  if ( lon<p.lon())
	    {
	      lon=p.lon();
	    }
	}
    }

    void checkmax(const Point & p)
    {
      // is the p bigger than we are?
      if (lat==0)
	{
	  lat=p.lat();
	  lon=p.lon();
	}
      else
	{
	  if ( lat>p.lat())
	    {
	      lat=p.lat();
	    }
	  if ( lon>p.lon())
	    {
	      lon=p.lon();
	    }
	}
    }

    void reset()
    {
      lat=lon=0;
      //cerr << "reset" << endl;
    }

    friend ostream& operator<< (ostream& o, const  SPoint& p);  

  } min, max;

  friend ostream& operator<< (ostream& o, const  BBox& p);  

  void add(const Point & p)
  {
    min.checkmin(p);
    max.checkmax(p);
    //    cerr << "add:"<< p << endl;

  }

  void reset()
  {
    min.reset();
    max.reset();
  }

};

ostream& operator<< (ostream& os, const  BBox& b)
{
  os << " Min:"<< b.min ;
  os << " Max:"<< b.max ;
}

ostream& operator<< (ostream& os, const  BBox::SPoint& p)
{
  os << " Lat:";
  os.precision ( 16 );
  os << p.lat;
  os << " Lon:"; 
  os.precision ( 16 );
  os << p.lon ;
  return os ;
}

ostream& operator<< (ostream& os, const  Point& p)
{
  os << p.sKey << " Lat:";
  os.precision ( 16 );
  os << p.lat();
  os << " Lon:"; 
  os.precision ( 16 );
  os << p.lon() << endl;
  return os ;
}


class World
{
public:
  typedef map<int, int>         TMapNodeCount; // id -> count
  typedef map<Point, int> TMapCoordID; // LAT + LONG -> id


  typedef Point TCoordData;
  typedef map<int,TCoordData>  TMapIDCoord; // id -> LAT + LONG 

  // static data shared bet
  TMapNodeCount node_ids;// have we seen this id?
  TMapCoordID   node_coords;// map the lat and long to an id
  TMapIDCoord   node_id_coord;

};

class Processor
{
protected:  
  char report_duplicates;
  char output_missing;
  char output_way;
  char  report_end;

  int current_id; //way, node or relation
  //  char current_type; //way, node or relation w,n,r
  string current_name; // the name we collected
  char current_interesting;// is it interestings

  World & world; // common data 
public:
  Processor (World & rWorld)
    : world(rWorld),
      report_duplicates(0),
      output_missing(0),
      output_way(0),
      report_end(0)
  {

  };

  static int getId(const Attributes& attrs)
  {
    /// Process the ID

    //	//	getAttrInt(attrs
    const XMLCh * xID= 	attrs.getValue (szID);
    char * sid  = XMLString::transcode(xID);
    int id = atoi(sid);
    return id;
  }

  // we
  // fieldtype :INT getAttribute
  //  static int getAttrInt(const Attributes& attrs)
  static int getAttrInt(const Attributes& attrs, const XMLCh * szName)
  {
    const XMLCh * xID= 	attrs.getValue (szName);
    char * val  = XMLString::transcode(xID);

    if (val)
      {
	return atoi(val);
      }
    else
      {
	return 0;
      }

  }

  static string getAttrStr(const Attributes& attrs, const XMLCh * szName)
  {
    const XMLCh * xID= 	attrs.getValue (szName);
    char * val  = XMLString::transcode(xID);
    if (val)
      {
	return string(val);
      }
    else
      {
	return string("");
      }

  }

  void setName(const string & val)
  {
    current_name=val;
  }
  
  void ProcessTag(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
      //
      const XMLCh * xKey= 	attrs.getValue (szK);
      string val = getAttrStr(attrs,szV);
      
	switch (xKey[0])
	  {
	  case chLatin_n	:
	    //name	    
	    if (xKey[1]==szNAME[1])//a
	      if (xKey[2]==szNAME[2])//m
		if (xKey[3]==szNAME[3])//e
		  {

		    current_name=val;

		    // now we check the county backwards. 
		    if (val.rfind("County") != string::npos  )
		      {
			//name
			//			cout << "type:" << current_type << " current_id :" <<  current_id << " name: " << val;
			current_interesting=1;
			setName(val);
		      }
		    //County
// <tag k="attribution" v="USGS 2001 County Boundary"/>
// <tag k="border_type" v="county"/>
// <tag k="boundary" v="administrative"/>


		  }

	    break;

	  }
}

  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    current_id = getId(attrs); // the relation id
    current_interesting=0;   
  }

static   bool xmlcmp(const XMLCh *const a,const XMLCh *const b)
  {
    const XMLCh * pa=a;
    const XMLCh * pb=b;

    while (
	   (pa && pb) 
	   &&
	   (*pa == *pb)
	   )
      {
	if(*pa == chNull) 
	  return 1 ;// matches
	
	pa++;
	pb++;
      }
    return 0;
  }

  virtual void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if (report_end)
      {
	cout << "not interesting type:" << getCurrentType() << " current_id :" <<  current_id << " name: " << current_name;
	cout << endl;
      }

    current_name="";

  }
  
  //current_type = 'r'; // relation
  virtual char getCurrentType()=0;

};

class NodeProcessor : public Processor
{
public:
  NodeProcessor( World & rWorld)
    :Processor (rWorld)
  {}
  char getCurrentType(){return 'N';}


  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor::startElement(uri,localnameXML, qname, attrs);
    
    //current_type = 'n'; // node
    World::TMapNodeCount::iterator i = world.node_ids.lower_bound(current_id);
    
    if ((i != world.node_ids.end() ) && ( i->first == current_id))
      {	       
	if (i->second ==1)
	  {
	    // only report it once
	    if (report_duplicates)
	      cerr << "error: duplicate nodes ID:" << i->first  << endl;
	  }
	i->second++;
      }
    else
      {
	world.node_ids.insert(i, World::TMapNodeCount::value_type(current_id, 1));
	
	
	Point point(attrs);;
	World::TMapCoordID::iterator c = world.node_coords.lower_bound(point);
	
	if (c != world.node_coords.end() && ( c->first == point))
	  {
	    // is the id different? report it.
	    if(c->second != current_id)
	      {
		if (report_duplicates)
		  cerr << "Duplicate Coordinate new:"<< current_id << " oldid:"<< c->second << " error :" << point  << endl ;
	      }
	  }
	else
	  {
	    // add the node
	    //			    cerr << "Adding Coordinate :"<< id << ":"<< key << endl;
	    world.node_coords.insert(c, World::TMapCoordID::value_type(point, current_id));
	    
	    
	    // look it up
	    world.node_id_coord[current_id]=point;
	    
	  }		    
      }
  }
};

class RelProcessor : public Processor
{
public:
  RelProcessor( World & rWorld)
    :Processor (rWorld)
  {}
char getCurrentType(){return 'R';}
};


class WayProcessor : public Processor
{
public:
  // the bounding box of the current object
  // the number of nds in the current way
  int ndcount;
  char output_way;
  char output_refs;
  char report_other_ways;
  BBox box;

  WayProcessor( World & rWorld)
    :Processor (rWorld),
     output_way(0),
     ndcount(0),
     output_refs(0),
     report_other_ways(0)
  {}
  
  char getCurrentType(){return 'W';}

  void start(int id)
  {
    ndcount=0;
    if (output_way)
      cout << "way: " << current_id << endl;
  }

  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor::startElement(uri,localnameXML, qname, attrs);
      //	    cerr << "localname" << ;
    current_id = getId(attrs);
      //	current_type = 'w'; // way
      
      // now we want the counties
      //	string name = getAttrStr(attrs,szNAME);
      //	string admin_level = getAttrStr(attrs,OSM::szADMIN_LEVEL);      
      // name << ", admin_level:"<< admin_level
      start(current_id);   

  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if (current_interesting)
      {
	//    cout << "end element";
	if (xmlcmp(localName,OSM::szWAY))
	  {
	    cout << "type:" << getCurrentType() << " current_id :" <<  current_id << " name: " << current_name;
	    if (ndcount)
	      {
		cout << " ndcount:" << ndcount;
		cout << " box :" << box;

		ndcount=0;
		box.reset();
		current_interesting=0;
	      }
	    cout << endl;	    	    
	  }
	else
	  {
	    if (report_other_ways)
	      {
		cout << "ERRORnot interesting type:WAY" << " current_id :" <<  current_id << " name: " << current_name;
		cout << endl;
	      }
	  }	
      }


  }
  

  void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    // WE SHOULD MOVE this into the Way::Nd::Process function
    // attribute ref
    int ref = getAttrInt(attrs,OSM::szREF);   
    World::TMapIDCoord::iterator i = world.node_id_coord.lower_bound(ref);
    if ((i != world.node_id_coord.end() ) && ( i->first == ref))
      {
	add_nd(i->first,i->second);
      }
    else
      {
	if (output_missing)
	  cerr << "MISSING: " << ref << endl;
      }    
  }

  void add_nd(int ref,const World::TCoordData & data)
  {
    ndcount++;
    box.add(data);
    // if(ndcount==1)
    //   {
    // 	cout << "ref: " << ref << " -> " << data << endl ;
    //   }
    if (output_refs)
      {
	cout << "ref: " << ref << " -> " << data << endl ;
      }
  }
};

class SAX2OsmHandlers : public DefaultHandler
{
public:
  
  SAX2OsmHandlers()
    : way(world),
      rel(world),
      node(world),
      pCur(0)
  {
  }

  ~SAX2OsmHandlers()
  {
  }

  /// 
  World          world;// data collected so 
  WayProcessor   way;// the current way
  RelProcessor   rel;// the current rel
  NodeProcessor node;// the current node
  Processor   * pCur; // the current processor

  // -----------------------------------------------------------------------
  //  Handlers for the SAX ContentHandler interface
  // -----------------------------------------------------------------------
  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {


    char* localname = XMLString::transcode(localnameXML);

    if (localname[0] == 'n') /* node*/      {
      if (localname[1] == 'o') /* node */  {
	if (strcmp(localname,"node")==0) /* node*/  {
	  pCur=&node;
	  node.startElement(uri,localnameXML,qname, attrs);
	}
	else
	  {
	    cerr << "ERRO:Unkown name:" << localname<< "\n";
	  }
      }// end of no
      else
	if (localname[1] == 'd') // way/nd
	  {
	    //----- process the node ref of the way
	    way.startND(uri,localnameXML,qname, attrs);
	  }
	else
	  {
	    cerr << "Unknown Node Name:" << localname<< "\n";
	  }	
    }// end of n
    else if (localname[0] == 'w')   {
      if (strcmp(localname,"way")==0)   {      
	pCur=&way;
	way.startElement(uri,localnameXML,qname, attrs);
      }
      else {
	cerr << "not way localname" << localname << "\n";
      }    
    }
    else if (localname[0] == 't')   {
      if (strcmp(localname,"tag")==0)   {
	if(pCur)
	  {
	    // call a virtual dispatch based on what type of object
	    pCur->ProcessTag(uri,localnameXML,qname, attrs);
	  }
	else
	  {
	    cerr << "Unexpected name\n";
	  }
      }
    }
    else
      if ( localnameXML[0]== OSM::szRELATION[0])
	{
	  if ( localnameXML[1]== OSM::szRELATION[1])
	    if ( localnameXML[2]== OSM::szRELATION[2])
	      {
		pCur=&way;
		way.startElement(uri,localnameXML,qname,attrs);
	      }
	}
      else
	{
	  
	}
  }


  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  //  void 	endElement (const XMLCh *const name)
  {

    if(pCur)
      {
	pCur->endElement( uri, localName, qname );
      }
  }

  void characters(const XMLCh* const chars, const XMLSize_t length)
  {
  }

  void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length){}
  void startDocument(){}
  
  
  // -----------------------------------------------------------------------
  //  Handlers for the SAX ErrorHandler interface
  // -----------------------------------------------------------------------
  void warning(const SAXParseException& exc){}
  void error(const SAXParseException& exc){}
  void fatalError(const SAXParseException& exc){}
  void resetErrors(){}
  
};


int main(int argc, char* argv[])
{
  try {
    XMLPlatformUtils::Initialize();
  }
  catch (const XMLException& toCatch) {
    // Do your failure processing here
    return 1;
  }

  // Do your actual work with Xerces-C++ here.
  SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

  SAX2OsmHandlers handler;
  parser->setContentHandler(&handler);
  parser->setErrorHandler(&handler);

  const char*                  xmlFile      = 0;
  if (argc == 2)
    {
      xmlFile = argv[1];
      cerr << "parsing:"<<xmlFile << endl;
      parser->parse(xmlFile);
    }
  else
    {
      cerr << "argc:"<<argc;
    }
  XMLPlatformUtils::Terminate();

  // Other terminations and cleanup.
  return 0;
}
