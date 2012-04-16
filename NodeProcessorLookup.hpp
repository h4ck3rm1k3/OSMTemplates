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

class NodeProcessorLookup : public Processor<RTreeWorld>
{
public:
  NodeProcessorLookup( RTreeWorld & rWorld)
    :Processor<RTreeWorld> (rWorld)
  {}

  char getCurrentType(){return 'N';}

  BoundingBox bounds(Point p)
  {
    BoundingBox bb;
    
    // 0 is the lat axis
    bb.edges[0].first  = p.lat();
    bb.edges[0].second  = p.lat();
    
    // 1 is the lon axist
    bb.edges[1].first = p.lon();
    bb.edges[1].second = p.lon();
        
    return bb;
  }

  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<RTreeWorld>::startElement(uri,localnameXML, qname, attrs);       
    int cid= Processor<RTreeWorld>::current_id;
    Point point(attrs);

    // lookup the region (s)
    BoundingBox bound = bounds( point );
    
    Tree::OverlappingIterator * io = world.tree.FindOverlapping(bound);
    int count = 0;
    if (!io)
      {
	fprintf(stderr, "Error retrieving iterator: code %d\n", world.tree.GetErrorCode());
	return ;
      }
    
    //    std::cout << "Searching in " << bound.ToString() << std::endl;
    while (!io->end())
      {
	count += 1;
	std::cout << cid << point << "\tin:\t" << io->current().key.ToString() << std::endl;
	io->next();
      }
    
    //    std::cout << "Visited " << count << " nodes." << std::endl;
    
    delete io;

  }
};
