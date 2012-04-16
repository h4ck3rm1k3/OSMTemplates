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

class PointExtended
{
protected:
  string sKey;
  int nid;
  double dLat;
  double dLon;
  int    ninWay; // used by ways
  int    ninWayChecksum; // used by ways, sum of ids for uniqueness
  int    hasDuplicates;// has other nodes that are duplicates
  int    nisDuplicateOf;// the if of the first node we found.

public:

  PointExtended(const Attributes& attrs) // extract the data from the attributes
    :dLat(0),
     dLon(0),
     nid(0),
     ninWay(0), // used by ways
     hasDuplicates(0),// has other nodes that are duplicates
     nisDuplicateOf(0),
     ninWayChecksum(0)
  {
    const XMLCh * xLAT= 	attrs.getValue (OSM::szLAT);
    const XMLCh * xLON= 	attrs.getValue (OSM::szLON);
    parse(xLAT,xLON);
  }


  PointExtended() 
    :
    dLat(0),
    dLon(0),
     nid(0),
    ninWay(0), // used by ways
    hasDuplicates(0),// has other nodes that are duplicates
    nisDuplicateOf(0),
    ninWayChecksum(0)
  {}


  void setID(int id)
  {
    nid =id;
  }

  int ID()
  {
    return nid;
  }

  void WayRef(int wayid)
  {
    ninWay++; // used by ways
    if (ninWayChecksum ==0)
      {
	// we store only the first way and emit it as well
	ninWayChecksum = wayid; // make a checksum
      }
  }

  int inWayChecksum()
  {
    return ninWayChecksum; // make a checksum
  }

  int inWay()
  {
    return ninWay; // make a checksum
  }


  void Duplicate()
  {
    hasDuplicates++;// has other nodes that are duplicates
    //report(cerr);
  }

  void DuplicateOf(int other)
  {

    nisDuplicateOf=other;

    //report(cerr);
  }

  void report(ostream &os)
  {
    os <<  "Point " 
       << " id='"<< nid << "'"
       << " dLat "<< dLat
       << " dLon "<< dLon
       << " key "<< sKey
       << " ninWay "<< ninWay
       << " hasDuplicates "<< hasDuplicates
       << " nisDuplicateOf "<< nisDuplicateOf
       << " ninWayChecksum "<< ninWayChecksum
       << endl;      
  }

  void emit(ostream &os)
  {
    os <<  "<node " 
       << " id='"<< nid << "'"

       << " lat='"<< dLat << "'"
       << " lon='"<< dLon << "'"
       << " version='1' > " << endl;

    //       << " xid='"<< nid << "'"
    os << "<tag k=\'xid\' v='" << nid << "'/>" << endl;
    os << "<tag k=\'ninWay\' v='" << ninWay << "'/>" << endl;
    os << "<tag k=\'hasDuplicates\' v='" << hasDuplicates << "'/>" << endl;
    os << "<tag k=\'nisDuplicateOf\' v='" << nisDuplicateOf << "'/>" << endl;
    os << "<tag k=\'ninWayChecksum\' v='" << ninWayChecksum << "'/>" << endl;

    os <<  "</node >"   << endl;
      
  }

  int isDuplicateOf()
  {
    return nisDuplicateOf;
  }

  const string & key ()
  {
    return sKey;
  }
  
  inline const double & lat () const
  {
    return dLat;
  }

  inline const double & lon () const
  {
    return dLon;
  }


  void parse(const XMLCh * xLAT, const XMLCh * xLON)
  {
    char * sLAT  = XMLString::transcode(xLAT);
    char * sLON  = XMLString::transcode(xLON);


    // key = "LAT|LON";
    std::ostringstream buffer;
    buffer << sLAT << "|" << sLON;
    sKey = string (buffer.str());    

    dLat=atof(sLAT);
    dLon=atof(sLON);

    XMLString::release(&sLAT);  // dont forget forget to delete !
    XMLString::release(&sLON);  // dont forget forget to delete !

    // char * pend=sLAT+strlen(sLAT);
    // lat = strtod(sLAT, &pend ); 
    // pend=sLON+strlen(sLON);
    // lon = strtod(sLON, &pend ); 

  }
  

  friend ostream& operator<< (ostream& o, const  PointExtended& p);

  bool operator== ( const  PointExtended& p) const
  {
    return (sKey==p.sKey);
    //return (dLat==p.dLat) && (dLon==p.dLon);
  }

  bool operator< ( const  PointExtended& p) const
  {
    return (sKey<p.sKey);
    //    return (dLat<p.dLat) && (dLon<p.dLon);

  }

  // check if the point is smaller
    void checkMin(const PointExtended & p)
    {
      if (dLat==0)
	{
	  dLat=p.dLat;
	  dLon=p.dLon;
	}
      else
	{
	  if ( dLat>p.dLat) //if this is smaller than tha
	    {
	      dLat=p.dLat;
	    }
	  if ( dLon>p.dLon)
	    {
	      dLon=p.dLon;
	    }
	}
    }

    void checkMax(const PointExtended & p)
    {
      // is the p bigger than we are?
      if (dLat==0)
	{
	  dLat=p.dLat;
	  dLon=p.dLon;
	}
      else
	{
	  if ( dLat<p.dLat)
	    {
	      dLat=p.dLat;
	    }
	  if ( dLon<p.dLon)
	    {
	      dLon=p.dLon;
	    }
	}
    }

    void reset()
    {
      dLat=dLon=0;
      //cerr << "reset" << endl;
    }

  // is the number of ways and checksum the same 
  bool InSameRel(const  PointExtended& p) const
  {
    return (
	    (nid!=p.nid) 
	    &&
	    (ninWay==p.ninWay) 
	    &&
	    (ninWayChecksum == p.ninWayChecksum)
	    );
  }

  
};

inline ostream& operator<< (ostream& os, const  PointExtended& p)
{
  os << " Lat:";
  os.precision ( 16 );
  os << p.dLat;
  os << " Lon:"; 
  os.precision ( 16 );
  os << p.lon() ;
  return os ;
}
