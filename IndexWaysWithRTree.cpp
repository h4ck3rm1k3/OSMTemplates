/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  Builds a rtreeindex of the ways bounding boxes

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
#include "BBoxRtreeWayProcessor.hpp"
#include "NodeProcessorLookup.hpp"

//BBoxRtreeWayProcessor.hpp



typedef  RTreeWorld  TWorld;

int main(int argc, char* argv[])
{

  //  ExtractWayOSMProcessor proc;

  if (argc == 3)
    {
      const char *xmlFile = argv[1];
      const char *xmlFile2 = argv[2];

      cerr << "going to parse:"<<xmlFile << endl;
      cerr << "going to splitt:"<<xmlFile2 << endl;

      TWorld theWorld;

      cerr << "going to read :"<<xmlFile << endl;

      TOSMProcessorProc
	<
      TWorld,         // the world data
	NodeProcessor<TWorld>, // way processor
	BBOXRTreeWayProcessor, // custom way processor
	RelProcessor<TWorld> // rel processor
	>(xmlFile,theWorld);


      cerr << "going to read :"<<xmlFile2 << endl;


      TOSMProcessorProc	<
      TWorld,         // the world data
	NodeProcessorLookup, // way processor
	WayProcessor<TWorld>, // custom way processor
	RelProcessor<TWorld> // rel processor
	>(xmlFile2,theWorld);
    }
  else
    {
      cerr << "argc:"<<argc;
    }

  // Other terminations and cleanup.
  return 0;
}
