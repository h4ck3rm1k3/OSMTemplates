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

template<class TWorld>
class WayProcessor : public Processor<TWorld>
{
public:

  WayProcessor( TWorld & rWorld)
    :Processor<TWorld> (rWorld)
  {}
  
  char getCurrentType(){return 'W';}

  void startWayElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    Processor<TWorld>::startElement(uri,localnameXML, qname, attrs);    
  }

  void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    Processor<TWorld>::endElement(  uri,localName, qname );
  }
  

  void startND(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
  }

};
