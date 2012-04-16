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
#include <vector>

template<class TWorld>
class NodeProcessorShared : public Processor<TWorld>
{
  //  typedef TWorld::TMapNodeCount::iterator TMapNodeCountIterator;
  typename TWorld::TMapNodeCount::iterator   nc_iterator;
  typename TWorld::TMapNodeCount::value_type nc_value_type;

  typename TWorld::TMapCoordID::iterator     id_iterator;
  typename TWorld::TMapCoordID::value_type   id_value_type;


public:
  vector <int> nds;
  int in_way;
  NodeProcessorShared( TWorld & rWorld)
    :Processor<TWorld> (rWorld),
     in_way(0)
  {}

  char getCurrentType(){return 'N';}

  void Member(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {

  }
 	

  void ProcessTag(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
      //
    if (!in_way)
      {
	return;// skip
      }
      const XMLCh * xKey= 	attrs.getValue (OSM::szK);
      const XMLCh * xVal= 	attrs.getValue (OSM::szV);
      
	switch (xKey[0])
	  {
	  case chLatin_n	:
	    //name	    
	    if (xKey[1]==OSM::szNAME[1])//a
	      if (xKey[2]==OSM::szNAME[2])//m
		if (xKey[3]==OSM::szNAME[3])//e
		  {
		    
		    string val = Processor<TWorld>::getAttrStr(attrs,OSM::szV);
		    Processor<TWorld>::current_name=val;

		    // now we check the county backwards. 
		    if (val.rfind("County") != string::npos  )
		      {
			//name
			//			cout << "type:" << current_type << " current_id :" <<  current_id << " name: " << val;
			Processor<TWorld>::current_interesting=1;
			Processor<TWorld>::setName(val);
		      }
		    //County
// <tag k="attribution" v="USGS 2001 County Boundary"/>
// <tag k="border_type" v="county"/>
// <tag k="boundary" v="administrative"/>

		  }

	    break;

	  case chLatin_b	:
	    if (XMLString::equals(xKey,OSM::szBOUNDARY))   {
	      //szBOUNDARY  //szADMINISTRATIVE
	      Processor<TWorld>::current_interesting=1;
	    }
	    else if (XMLString::equals(xKey,OSM::szBORDER_TYPE))   {
	      //szCOUNTY
	      Processor<TWorld>::current_interesting=1;
	    }
	    break;

	  case chLatin_a	:
	     if (XMLString::equals(xKey,OSM::szADMIN_LEVEL))   {
	       // 6
	       Processor<TWorld>::current_interesting=1;
	    }
	    else if (XMLString::equals(xKey,OSM::szATTRIBUTION))   {
	      //	      szUSGS_2001_COUNTY_BOUNDARY
	      //current_interesting=1;
	    }
	    break;

	  case chLatin_s	:
	     if (XMLString::equals(xKey,OSM::szSOURCE))   {


	       if (XMLString::equals(xVal,OSM::szCOUNTY_IMPORT_V0_1))   {
		 //		 xVal
		 Processor<TWorld>::current_interesting=1;
	       }
	       else
		 if (XMLString::equals(xVal,OSM::szCOUNTY_IMPORT_V0_1_20080508235458))   {
		   Processor<TWorld>::current_interesting=1;
		   
		 }

	       else
		 if (XMLString::equals(xVal,OSM::szTIGER_IMPORT_DCH_V0_6_20070828))   {
		   //Processor<TWorld>::current_interesting=1;
		   
		 }
	       
		 else if (XMLString::equals(xVal,OSM::szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235449))   {		 Processor<TWorld>::current_interesting=1;	 }
		 else if (XMLString::equals(xVal,OSM::szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235452))   {		 Processor<TWorld>::current_interesting=1;	 }
		 else if (XMLString::equals(xVal,OSM::szUNKNOWN_ATTRIBUTION_COUNTY_IMPORT_V0_1_20080508235456))   {		 Processor<TWorld>::current_interesting=1;	 }


		 else
		   {
		     //tiger_import_dch_v0.6_20070828

		     string val = Processor<TWorld>::getAttrStr(attrs,OSM::szV);
		     cerr << "Unknown attribution " << val <<endl;
		   }
	     }
	     break;
	     
	  }
  }


  void ProcessND(int ref)
  {
    int cid =Processor<TWorld>::current_id;

    typename TWorld::TMapIDCoord::iterator i = Processor<TWorld>::world.node_id_coord.lower_bound(ref);
    if ((i != Processor<TWorld>::world.node_id_coord.end() ) && ( i->first == ref))
      {
	i->second.WayRef(cid);

	int oid = i->second.isDuplicateOf();
	
	if (oid)
	  {
	    typename TWorld::TMapIDCoord::iterator j= Processor<TWorld>::world.node_id_coord.find(oid);
	    if (j !=  Processor<TWorld>::world.node_id_coord.end())
	      {
		cerr << "found a node" << ref << "that was a duplicate point of "  << oid << endl;
		j->second.WayRef(cid);
		cerr << "DUP ID " <<j->first << "\t";
		//		j->second.emit(cerr);
	      }
	    else
	      {
		cerr << "ERROR! found a node" << ref << "that was a duplicate point of "  << oid << endl;
		cerr << "ID " <<i->first << "\t";
		//		i->second.emit(cerr);

	      }
	  }
	else
	  {
	    // there is no other point with that address
	    //	    cerr << "not duplicate "  << i->first  << " ref " << ref << " old " << oid << endl;
	  }
      }
    else
      {
	  cerr << "MISSING: " << ref << endl;
      }    

  }

  void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    //    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
    int ref = Processor<TWorld>::getAttrInt(attrs,OSM::szREF);   
    if (ref <0)
      {
	//	ref = ref * -1;
      }
    int cid =Processor<TWorld>::current_id;
    if (ref)
      {
	//	cerr << "adding " << ref << " to way "  << cid << endl;
	nds.push_back(ref);
      }
    else
      {
	cerr << "ERROR NULL " << ref << " to way "  << cid << endl;      
      }
    
  }

  void startRelElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
  }

  void startWayElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    in_way++;
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    

  }


  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    //    if (Processor<TWorld>::current_interesting)
      {
	vector<int>::iterator i=nds.begin();
	while (i!=nds.end())
	  {
	    ProcessND(*i);;
	    i++;
	  }
      }
    nds.clear();// delete it
  }

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

	PointExtended point(attrs);;
	point.setID(cid);

	// add the point
	Processor<TWorld>::world.node_id_coord[Processor<TWorld>::current_id]=point;

	//store a reverse index so that we can mark duplicates.
	//	  if (Processor<TWorld>::report_duplicates)
	  {
	    typename TWorld::TMapCoordID::iterator c = Processor<TWorld>::world.node_coords.lower_bound(point);	    // lookup the point
	    if (c != Processor<TWorld>::world.node_coords.end() && ( c->first == point)) // check it
	      {
		// is the id different? report it.
		int cid=Processor<TWorld>::current_id;
		if(c->second != Processor<TWorld>::current_id)// we found another point, another id
		  {
		    // now store this point as a duplicate of the other, but how many duplicates can we have? many.
		    // if we find another way that references this point, but with another id, we need to know. We will mark each node as having duplicates pointing to it. But each duplicate node will point to the first one. 
		    // otherwise we cannot merge them.
		    cerr << cid << " is a duplicate of " <<  c->second << endl;

		    //		    Processor<TWorld>::world.node_id_coord[cid].DuplicateOf(c->second);  
		    typename TWorld::TMapIDCoord::iterator e =   Processor<TWorld>::world.node_id_coord.find(cid);
		    if (e != Processor<TWorld>::world.node_id_coord.end())
		      {
			e->second.DuplicateOf(c->second);  
		      }

		    //Processor<TWorld>::world.node_id_coord[c->second].		    
		    typename TWorld::TMapIDCoord::iterator d =   Processor<TWorld>::world.node_id_coord.find(c->second);
		    if (d != Processor<TWorld>::world.node_id_coord.end())
		      {
			d->second.Duplicate();
		      }
		      //Processor<TWorld>::world.node_id_coord[c->second].report(cerr);// report on the original object as well

		  }
		else
		  {
		    // has the same id, we found it.
		  }
	      }
	    else
	      {
		typename TWorld::TMapCoordID::value_type val(point, cid);
		Processor<TWorld>::world.node_coords.insert(c, val);	   	  	    

	      }		    
	  }

      }
    
  }
};
