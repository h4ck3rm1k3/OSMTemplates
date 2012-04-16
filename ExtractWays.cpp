/*
  copyright 2009 
  "James Michael Dupont (H4ck3rm1k3)"  <jamesmikedupont@gmail.com>
  http://www.fsf.org/licensing/licenses/agpl-3.0.html

  example of fast processing of osm using c++/xerces
  takes an osm file as parameter


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
#include "NodeProcessor.hpp"
#include "WayProcessor.hpp"
#include "RelProcessor.hpp"
#include "SAX2OsmHandlers.hpp"
#include "OSMProcessor.hpp"
#include "BBoxWayProcessor.hpp"


int main(int argc, char* argv[])
{

  //  ExtractWayOSMProcessor proc;

  if (argc == 2)
    {
      const char *xmlFile = argv[1];
      cerr << "parsing:"<<xmlFile << endl;
      TOSMProcessorParse
	<
      World,         // the world data
	NodeProcessor<World>, // way processor
	BBOXWayProcessor, // custom way processor
	RelProcessor<World> // rel processor
	>(xmlFile);
    }
  else
    {
      cerr << "argc:"<<argc;
    }

  // Other terminations and cleanup.
  return 0;
}
