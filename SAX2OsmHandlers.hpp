#pragma once
/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

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

#include "Processor.hpp"

template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
class SAX2OsmHandlers : public DefaultHandler
{
public:
  TWorld     &       world; // data collected so 
  TNodeProc           node; // the current node
  TWayProc             way; // the current way
  TRelProc             rel; // the current rel
  Processor<TWorld> * pCur; // the current processor

public:
  
  SAX2OsmHandlers(TWorld     &  rWorld)
    : way(world),
      rel(world),
      node(world),
      world(rWorld),
      pCur(0)
  {
  }

  ~SAX2OsmHandlers()
  {
  }

  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    if (localnameXML[0] == OSM::szNODE[0]) /* node*/      {
      if (localnameXML[1] == OSM::szNODE[1]) /* node */  {
	if (XMLString::equals(localnameXML,OSM::szNODE)) /* node*/  {
	  pCur=&node;
	  node.startNodeElement(uri,localnameXML,qname, attrs);
	}
	else
	  {
	    char * val  = XMLString::transcode(localnameXML);
	    string ret(val); // hack it!
	    XMLString::release(&val);  // dont forget forget to delete !
	    cerr << "ERRO:Unknown name:" << ret << "\n";
	  }
      }// end of no
      else
	if (localnameXML[1] == OSM::szND[1]) // way/nd
	  {
	    way.startND(uri,localnameXML,qname, attrs);
	  }
	else
	  {
	    cerr << "Unknown Node Name:" << localnameXML<< "\n";
	  }	
    }// end of n
    else if (localnameXML[0] == OSM::szWAY[0])   {
      if (XMLString::equals(localnameXML,OSM::szWAY)) /* way*/  {
	pCur=&way;
	way.startWayElement(uri,localnameXML,qname, attrs);
      }
      else {
	cerr << "not way localname" << localnameXML << "\n";
      }    
    }
    else if (localnameXML[0] ==OSM::szTAG[0])   {
      if (XMLString::equals(localnameXML,OSM::szTAG))   {
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
      else
	{
	  cerr << "ERRO:Unknown name4:\n";
	}	  
    }
    else
      if ( localnameXML[0]== OSM::szRELATION[0])
	{
	  if ( localnameXML[1]== OSM::szRELATION[1])
	    if ( localnameXML[2]== OSM::szRELATION[2])
	      {
		pCur=&rel;
		rel.startRelElement(uri,localnameXML,qname,attrs);
	      }
	    else{
	      cerr << "ERRO:Unknown name1:\n";
	    }
	  else{
	    cerr << "ERRO:Unknown name2:\n";
	  }	  
	} 
      else if ( localnameXML[0]== OSM::szMEMBER[0]) // m
	{
	  if ( localnameXML[1]== OSM::szMEMBER[1]) // e
	    if ( localnameXML[2]== OSM::szMEMBER[2]) // m
	      if ( localnameXML[3]== OSM::szMEMBER[3]) // b
		if ( localnameXML[4]== OSM::szMEMBER[4]) // e
		  if ( localnameXML[5]== OSM::szMEMBER[5]) // r
		    {
		      rel.Member(uri,localnameXML,qname,attrs);
		    }
	}   
      else if ( localnameXML[0]== OSM::szBOUND[0]) // b 
	{
	  if ( localnameXML[1]== OSM::szBOUND[1]) // o 
	    if ( localnameXML[2]== OSM::szBOUND[2]) // u
	      if ( localnameXML[3]== OSM::szBOUND[3]) // n
		if ( localnameXML[4]== OSM::szBOUND[4]) //d
		  {
		    //way.startElement(uri,localnameXML,qname,attrs);
		    world.Bound(uri,localnameXML,qname,attrs);
		  }
	}
      else if ( localnameXML[0]== OSM::szOSM[0]) // o
	{
	  if ( localnameXML[1]== OSM::szOSM[1]) // s
	    if ( localnameXML[2]== OSM::szOSM[2]) // m
	      {		
	      }
	}   
      else
	{
	  char * val  = XMLString::transcode(localnameXML);
	  string ret(val); // hack it!
	  XMLString::release(&val);  // dont forget forget to delete !
	  cerr << "ERRO:Unknown name:" << ret << "\n";  
	}
  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if(pCur)
      {
	pCur->endElement( uri, localName, qname );
      }
  }

  void characters(const XMLCh* const chars, const XMLSize_t length) { }
  void ignorableWhitespace(const XMLCh* const chars, const XMLSize_t length){}

  void startDocument()
  {
    world.startDocument();
  }

  void endDocument ()
  {
    world.endDocument();
  } 
  
  // -----------------------------------------------------------------------
  //  Handlers for the SAX ErrorHandler interface
  // -----------------------------------------------------------------------
  void warning(const SAXParseException& exc){}
  void error(const SAXParseException& exc){}
  void fatalError(const SAXParseException& exc){}
  void resetErrors(){}
  
};
