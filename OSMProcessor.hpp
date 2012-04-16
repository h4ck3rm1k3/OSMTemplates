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

#include "SAX2OsmHandlers.hpp"

typedef int test123;

template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
SAX2XMLReader*  TOSMProcessorParseStart()
{  
  try {
    XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
      // Do your failure processing here
      return 0;
    }

    // Do your actual work with Xerces-C++ here.
    SAX2XMLReader* parser = XMLReaderFactory::createXMLReader();

    return parser;
}


template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
void  TOSMProcessorParseEnd(SAX2XMLReader* parser)
{  
    delete parser;
    XMLPlatformUtils::Terminate();
}

template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
void TOSMProcessorParseProcess(SAX2XMLReader* parser,TWorld & rWorld,const char*                  xmlFile)
{  
  if (xmlFile ==0)
    {
      cerr << "No filename!" << endl;
      return;
    }

  SAX2OsmHandlers<TWorld,TNodeProc,TWayProc,TRelProc> handler(rWorld);
    parser->setContentHandler(&handler);
    parser->setErrorHandler(&handler);  
    parser->parse(xmlFile);    
}


/**
   process one file
*/
template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
void TOSMProcessorParse(const char*  xmlFile)
{  

  SAX2XMLReader* parser = TOSMProcessorParseStart<TWorld,TNodeProc,TWayProc,TRelProc>();    
  TWorld aWorld;
  TOSMProcessorParseProcess<TWorld,TNodeProc,TWayProc,TRelProc>(parser,aWorld,xmlFile);
  TOSMProcessorParseEnd<TWorld,TNodeProc,TWayProc,TRelProc>(parser);
}

template <class TWorld,class TNodeProc,class TWayProc,class TRelProc>
void TOSMProcessorProc(const char*  xmlFile,  TWorld & rWorld)
{  
  SAX2XMLReader* parser = TOSMProcessorParseStart<TWorld,TNodeProc,TWayProc,TRelProc>();    
  TOSMProcessorParseProcess<TWorld,TNodeProc,TWayProc,TRelProc>(parser,rWorld,xmlFile);
  TOSMProcessorParseEnd<TWorld,TNodeProc,TWayProc,TRelProc>(parser);
}

