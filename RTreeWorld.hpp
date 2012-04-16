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

	// typename _bound_type,													\
	// typename _leaf_type,													\
	// std::size_t _dimensions,												\
	// std::size_t _min_child_items,											\
	// std::size_t _max_child_items,											\

typedef RTree<double, int, 2, 32, 64, MemoryTreeBackend> 	Tree;
typedef Tree::BoundingBox			BoundingBox;

class RTreeWorld
{
public:
  typedef map<int, int>         TMapNodeCount; // id -> count
  typedef map<Point, int> TMapCoordID; // LAT + LONG -> id


  typedef Point TCoordData;
  typedef map<int,TCoordData>  TMapIDCoord; // id -> LAT + LONG 

  Tree tree;

  // static data shared bet
  TMapNodeCount node_ids;// have we seen this id?
  TMapCoordID   node_coords;// map the lat and long to an id
  TMapIDCoord   node_id_coord;

  void startDocument()
  {
    // todo : add your initializers here
  };

  void endDocument()
  {
    Report();
  };

// from  rtreetest:  Copyright (c) 2008 Dustin Spicuzza <dustin@virtualroadside.com>
  void PrintStats(Tree &tree)
  {
    std::cout << "Tree stats:\n\tDim\t: " << tree.GetDimensions()
	      << "\n\titems\t: " << tree.GetItemCount() 
	      << "\n\theight\t: " << tree.GetHeight()
	      << "\n";
  }
  
  // from  rtreetest:  Copyright (c) 2008 Dustin Spicuzza <dustin@virtualroadside.com>
  std::size_t WalkAll(Tree &tree)
  {
    Tree::Iterator * iter = tree.Begin();
    
    if (!iter || iter->end())
      {
	if (iter) delete iter;
	assert(0 && "Error");
	return 0;
      }
    
    std::size_t count = 0;
    
    do 
      {
	//Tree::LeafItem &item = iter->current();
	//printf("Item: %d\n", item.key);
	count += 1;
	
      } while (iter->next());
    
    assert(count == tree.GetItemCount());
    printf("Count: %d\n", count);
    
    delete iter;
    
    return count;
  }
  
  void Report()
  {
    WalkAll(tree);    
    PrintStats(tree);
  }

};
