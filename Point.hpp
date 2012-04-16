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

class Point 
{
  //  string sKey;
  double dLat;
  double dLon;

public:
  // const string & key ()
  // {
  //   return sKey;
  // }

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
    // std::ostringstream buffer;
    // buffer << sLAT << "|" << sLON;
    // sKey = string (buffer.str());    

    dLat=atof(sLAT);
    dLon=atof(sLON);

    XMLString::release(&sLAT);  // dont forget forget to delete !
    XMLString::release(&sLON);  // dont forget forget to delete !

    // char * pend=sLAT+strlen(sLAT);
    // lat = strtod(sLAT, &pend ); 
    // pend=sLON+strlen(sLON);
    // lon = strtod(sLON, &pend ); 

  }
  
  Point() 
    :
    dLat(0),
    dLon(0)
  {}

  Point(const Attributes& attrs) // extract the data from the attributes
    :dLat(0),
     dLon(0)
  {
    const XMLCh * xLAT= 	attrs.getValue (OSM::szLAT);
    const XMLCh * xLON= 	attrs.getValue (OSM::szLON);
    parse(xLAT,xLON);
  }
  friend ostream& operator<< (ostream& o, const  Point& p);

  bool operator== ( const  Point& p) const
  {
    return (dLat==p.dLat) && (dLon==p.dLon);
  }

  bool operator< ( const  Point& p) const
  {
    return (dLat<p.dLat) && (dLon<p.dLon);

  }

  // check if the point is smaller
    void checkMin(const Point & p)
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

    void checkMax(const Point & p)
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
  
};

inline ostream& operator<< (ostream& os, const  Point& p)
{
  os << " Lat:";
  os.precision ( 16 );
  os << p.dLat;
  os << " Lon:"; 
  os.precision ( 16 );
  os << p.lon() ;
  return os ;
}
