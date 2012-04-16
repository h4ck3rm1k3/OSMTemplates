/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  example of fast processing of osm using c++/xerces
  takes an osm file as parameter

  compile : gcc CheckDuplicates.cpp -l xerces-c && ./a.out lint.osm

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
static XMLCh szLON[]={ chLatin_l, chLatin_o, chLatin_n, chNull }; // lon
static XMLCh szLAT[]={ chLatin_l, chLatin_a, chLatin_t, chNull }; // lat

class SAX2OsmHandlers : public DefaultHandler
{
public:
  
  SAX2OsmHandlers()
    :current_way(0)
  {
  }
  ~SAX2OsmHandlers()
  {
  }

  typedef map<int, int> TMapNodeCount;
  typedef map<std::string, int> TMapCoordID; // LAT + LONG -> id

  TMapNodeCount node_ids;// have we seen this id?
  TMapCoordID   node_coords;// map the lat and long to an id
  int current_way;

  static int getId(const Attributes& attrs)
  {
    /// Process the ID
    const XMLCh * xID= 	attrs.getValue (szID);
    char * sid  = XMLString::transcode(xID);
    int id = atoi(sid);
    return id;
  }

  // -----------------------------------------------------------------------
  //  Handlers for the SAX ContentHandler interface
  // -----------------------------------------------------------------------
  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    char* localname = XMLString::transcode(localnameXML);

    if (localname[0] == 'n') // node
      {
	if (localname[1] == 'o') // node
	  {
	    if (strcmp(localname,"node")==0) // node
	      {
		/// Process the ID
		const XMLCh * xID= 	attrs.getValue (szID);

		if (xID)
		  {
		    char * sid  = XMLString::transcode(xID);
		    int id = atoi(sid);
		    TMapNodeCount::iterator i = node_ids.lower_bound(id);

		    if ((i != node_ids.end() ) && ( i->first == id))
		      {	       
			if (i->second ==1)
			  {
			    // only report it once
			    cerr << "error: duplicate nodes ID:" << i->first  << endl;
			  }
			i->second++;
		      }
		    else
		      {
			node_ids.insert(i, TMapNodeCount::value_type(id, 1));

			const XMLCh * xLAT= 	attrs.getValue (szLAT);
			const XMLCh * xLON= 	attrs.getValue (szLON);
			
			char * sLAT  = XMLString::transcode(xLAT);
			char * sLON  = XMLString::transcode(xLON);


			// key = "LAT|LON";
			std::ostringstream buffer;
			buffer << sLAT << "|" << sLON;
			string key(buffer.str());

			TMapCoordID::iterator c = node_coords.lower_bound(key);

			if (c != node_coords.end() && ( c->first == key))
			  {
			    // is the id different? report it.
			    if(c->second != id)
			      {
				cerr << "Duplicate Coordinate new:"<< id << " oldid:"<< c->second << " error :" << key  << endl;
			      }
			  }
			else
			  {
			    // add the node
			    //			    cerr << "Adding Coordinate :"<< id << ":"<< key << endl;
			    node_coords.insert(c, TMapCoordID::value_type(key, id));
			  }
		      }		    
		  }
	      }
	    else
	      {
		cerr << "ERRO:Unkown name:" << localname<< "\n";
	      }
	    
	  }
	else
	  if (localname[1] == 'd') // nd
	    {
	      
	    }
	  else
	  {
	    cerr << "Unknown Node Name:" << localname<< "\n";
	  }
      }
    else if (localname[0] == 'w')   {
      if (strcmp(localname,"way")==0)   {
	//	    cerr << "localname" << ;
	int id = getId(attrs);

      }
      else{
	cerr << "not way localname" << localname << "\n";
      }
	    
    }
    else
      {
	      
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
      cerr << "parsing:"<<xmlFile;
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
