/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  builds a tagreport

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
#include <xercesc/util/XMLFloat.hpp>
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
#include "Point.hpp"
#include "BBox.hpp"
#include "World.hpp"
#include "Processor.hpp"
typedef int test5;
#include "NodeProcessor.hpp"
typedef int test4;
#include "WayProcessor.hpp"
typedef int test3;
#include "RelProcessor.hpp"
typedef int test2;
#include "SAX2OsmHandlers.hpp"
typedef int test1;
#include "OSMProcessor.hpp"
//#include "BBoxRtreeWayProcessor.hpp"
//#include "NodeProcessorLookup.hpp"

class TagWorld
{
public:
  typedef map<string, int>  TTagCount; // name -> count

  typedef map<string, TTagCount>  TTagValues; // the tag values for some attributes. 

  int max_id;
  TTagCount tags;// how many tags we have
  TTagCount tags_wanted;// how many tags we have
  TTagValues tags_values;// how many tags we have
  void startDocument()  {  
    max_id=0;
    /*
tag	is_in	 662
tag	is_in:country	 659
tag	is_in:country_code	 659
tag	is_in:iso_3166_2	 659
tag	is_in:state	 659
tag	is_in:state_code	 659
tag	highway	 2
tag	network	 70
tag	ref	 49

tag	addr:state	 11
tag	admin_level	 2460
tag	attribution	 4652
tag	border_type	 489
tag	boundary	 2537
tag	collection	 17
tag	colour	 3
tag	created_by	 3708
tag	crossing	 2
tag	crossing_ref	 2
tag	description	 3
tag	hour_off	 1
tag	hour_on	 1
tag	landuse	 3
tag	left:county	 5
tag	left:township	 1
tag	leisure	 1
tag	line	 1
tag	maritime	 1
tag	maxheight	 1
tag	maxheight:feet	 1
tag	military	 1
tag	modifier	 2
tag	name	 842
tag	name:de	 1
tag	name:en	 1
tag	name:fr	 1
tag	name:ru	 1
tag	nist:fips_code	 61
tag	nist:state_fips	 61
tag	note	 1
tag	operator	 8
tag	place	 660
tag	place_name	 11
tag	railway	 2
tag	restriction	 7
tag	right:county	 7
tag	right:state	 3
tag	route	 92
tag	shop	 1
tag	source	 8394
tag	state	 1
tag	state_id	 2
tag	surface	 1
tag	symbol	 32
tag	tiger:CLASSFP	 659
tag	tiger:CPI	 659
tag	tiger:FUNCSTAT	 659
tag	tiger:LSAD	 659
tag	tiger:MTFCC	 659
tag	tiger:NAME	 659
tag	tiger:NAMELSAD	 659
tag	tiger:PCICBSA	 659
tag	tiger:PCINECTA	 659
tag	tiger:PLACEFP	 659
tag	tiger:PLACENS	 659
tag	tiger:PLCIDFP	 659
tag	tiger:STATEFP	 659
tag	tiger:county	 24
tag	tiger:reviewed	 12
tag	tiger:tlid	 48
tag	tiger:upload_uuid	 24
tag	type	 3490
tag	url	 21
tag	waterway	 5
tag	wikipedia	 668
tag	wikipedia:en	 2

*/

    tags_wanted["is_in"]=1;
    tags_wanted["is_in:country"]=1;
    tags_wanted["is_in:country_code"]=1;
    tags_wanted["is_in:iso_3166_2"]=1;
    tags_wanted["is_in:state"]=1;
    tags_wanted["is_in:state_code"]=1;
    tags_wanted["highway"]=1;
    tags_wanted["network"]=1;
    tags_wanted["ref"]=1;
    
  };
  
  void endDocument()  
  {
    
    cerr << "End of doc" << endl;
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


  };
  void Bound(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {}
};

class TagProcessor : public Processor<TagWorld>
{

public:
  TagProcessor(TagWorld & rW) 
    :Processor<TagWorld>(rW)
  {

  }

  void startRelElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
  }

  void startWayElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
  }

  void startNodeElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TagWorld>::startElement(uri,localnameXML, qname, attrs);    
  }

  char getCurrentType(){return 'T';}

  // void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  // {
  //   Processor<TagWorld>::
    
  // }

  // void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  // {
  // }
  
  void ProcessTag(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    //const XMLCh * xKey= 	attrs.getValue (OSM::szK);
    string name = getAttrStr(attrs,OSM::szK);
    string val = getAttrStr(attrs,OSM::szV);

    world.tags[name]++;

    if (world.tags_wanted[name])
      {
	world.tags_values[name][val]++;
      }

  }

   void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
   {
   }
  void Member(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {}

};

typedef  TagWorld  TWorld;

int main(int argc, char* argv[])
{

  if (argc == 2)
    {
      const char *xmlFile = argv[1];
      cerr << "going to parse:"<<xmlFile << endl;

      TWorld theWorld;

      cerr << "going to read :"<<xmlFile << endl;

      TOSMProcessorProc<TWorld,         // the world data
	TagProcessor, // way processor
	TagProcessor, // custom way processor
	TagProcessor // rel processor
	>(xmlFile,theWorld);

    }
  else
    {
      cerr << "argc:"<<argc;
    }

  // Other terminations and cleanup.
  return 0;
}
