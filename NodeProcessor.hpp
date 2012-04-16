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

template<class TWorld>
class NodeProcessor : public Processor<TWorld>
{
  //  typedef TWorld::TMapNodeCount::iterator TMapNodeCountIterator;
  typename TWorld::TMapNodeCount::iterator   nc_iterator;
  typename TWorld::TMapNodeCount::value_type nc_value_type;

  typename TWorld::TMapCoordID::iterator     id_iterator;
  typename TWorld::TMapCoordID::value_type   id_value_type;


public:
  NodeProcessor( TWorld & rWorld)
    :Processor<TWorld> (rWorld)
  {}

  char getCurrentType(){return 'N';}


  void startNodeElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);
    
    
    typename TWorld::TMapNodeCount::iterator i = Processor<TWorld>::world.node_ids.lower_bound(Processor<TWorld>::current_id);
    
    if ((i != Processor<TWorld>::world.node_ids.end() ) && ( i->first == Processor<TWorld>::current_id))
      {	       
	if (i->second ==1)
	  {
	    // only report it once
	    if ( Processor<TWorld>::report_duplicates)
	      cerr << "error: duplicate nodes ID:" << i->first  << endl;
	  }
	i->second++;
      }
    else
      {

	int cid= Processor<TWorld>::current_id;
	typename TWorld::TMapNodeCount::value_type valt(cid, 1);
	Processor<TWorld>::world.node_ids.insert(i, valt);
	
	typename TWorld::TPoint point(attrs);;
	// add the point
	Processor<TWorld>::world.node_id_coord[Processor<TWorld>::current_id]=point;

	// only store a reverse index if we really need it, it is not efficent
	/*
	if (Processor<TWorld>::report_duplicates)
	  {
	    id_iterator c = Processor<TWorld>::world.node_coords.lower_bound(point);	    
	    if (c != Processor<TWorld>::world.node_coords.end() && ( c->first == point))
	      {
		// is the id different? report it.
		if(c->second != Processor<TWorld>::current_id)
		  {
		    if (Processor<TWorld>::report_duplicates)
		      cerr << "Duplicate Coordinate new:"<< Processor<TWorld>::current_id << " oldid:"<< c->second << " error :" << point  << endl ;
		  }
	      }
	    else
	      {
		// add the node
		//			    cerr << "Adding Coordinate :"<< id << ":"<< key << endl;
		Processor<TWorld>::world.node_coords.insert(c, id_value_type(point, Processor<TWorld>::current_id));	   	  	    
	      }		    
	      }
	
	*/
	
      }
    
  }
};
