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


class BBOXWayProcessor : public WayProcessor<World>
{
public:
  // the bounding box of the current object
  // the number of nds in the current way
  int ndcount;
  char output_way;
  char output_refs;
  char report_other_ways;
  BBox box;

  BBOXWayProcessor( World & rWorld)
    :WayProcessor<World> (rWorld),
     output_way(0),
     ndcount(0),
     output_refs(0),
     report_other_ways(0)
  {}
  



  void startWayElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<World>::startElement(uri,localnameXML, qname, attrs);
      //	    cerr << "localname" << ;
    current_id = getId(attrs);
      //	current_type = 'w'; // way
      
      // now we want the counties
      //	string name = getAttrStr(attrs,szNAME);
      //	string admin_level = getAttrStr(attrs,OSM::szADMIN_LEVEL);      
      // name << ", admin_level:"<< admin_level
    //start(current_id);   
    ndcount=0;
    if (output_way)
      cout << "way: " << current_id << endl;
    
      current_interesting=1;// all ways are interesting

  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if (current_interesting)
      {
	//    cout << "end element";
	if (XMLString::equals(localName,OSM::szWAY))
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

  void add_nd(int ref,const World::TPoint & data)
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
