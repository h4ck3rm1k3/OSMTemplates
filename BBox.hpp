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

#include "Point.hpp"

class BBox
{
public:
  Point min, max;

  friend ostream& operator<< (ostream& o, const  BBox& p);  

  void add(const Point & p)
  {
    min.checkMin(p);
    max.checkMax(p);
    //    cerr << "add:"<< p << endl;

  }

  void reset()
  {
    min.reset();
    max.reset();
  }

};

inline ostream& operator<< (ostream& os, const  BBox& b)
{
  os << " Min:"<< b.min ;
  os << " Max:"<< b.max ;
}
