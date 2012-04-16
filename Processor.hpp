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

template <class TWorld> class Processor
{
protected:  
  char report_duplicates;
  char output_missing;
  char output_way;
  char  report_end;

  int item_count; //way, node or relation
  int current_id; //way, node or relation

  //  char current_type; //way, node or relation w,n,r
  string current_name; // the name we collected
  char current_interesting;// is it interestings

  TWorld & world; // common data 
public:
  Processor (TWorld & rWorld)
    : world(rWorld),
      report_duplicates(0),
      output_missing(0),
      output_way(0),
      report_end(0),
      item_count(0)
  {

  };

  static int getId(const Attributes& attrs)
  {
    /// Process the ID

    //	//	getAttrInt(attrs
    //const XMLCh * xID= 	
    //    char * sid  = XMLString::transcode(xID);
    //int id = atoi(sid);
    //XMLString::release(&sid);  // dont forget forget to delete !
    return XMLString::parseInt(attrs.getValue (OSM::szID));

  }

  // we
  // fieldtype :INT getAttribute
  //  static int getAttrInt(const Attributes& attrs)
  static int getAttrInt(const Attributes& attrs, const XMLCh * szName)
  {
    const XMLCh * xID= 	attrs.getValue (szName);

    if (xID)
      {
	//	char * val  = XMLString::transcode(xID);
	//int ret= atoi(val);
	//XMLString::release(&val);  // dont forget forget to delete !
	return XMLString::parseInt(xID);

      }
    else
      {
	return 0;
      }

  }

  // get a decimal
  static float getAttrFloat(const Attributes& attrs, const XMLCh * szName)
  {
    const XMLCh * xID= 	attrs.getValue (szName);

    if (xID)
      {
	XMLFloat f(xID);
	
	return f.getValue();
      }
    else
      {
	return 0.0;
      }

  }


  static string getAttrStr(const Attributes& attrs, const XMLCh * szName)
  {
    const XMLCh * xID= 	attrs.getValue (szName);

    if (xID)
      {
	char * val  = XMLString::transcode(xID);
	string ret(val); // hack it!
	XMLString::release(&val);  // dont forget forget to delete !
	return ret;
      }
    else
      {
	return string("");
      }

  }

  void setName(const string & val)
  {
    //    cerr << "Found Name "<< val <<endl;
    current_name=val;
  }
  
  virtual void ProcessTag(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
      //
    const XMLCh * xKey= 	attrs.getValue (OSM::szK);
    string val = getAttrStr(attrs,OSM::szV);
      //string name = getAttrStr(attrs,szK);
      //      cout << "got a " << name<< "=" << val << endl;
	switch (xKey[0])
	  {
	  case chLatin_n	:
	    //name	    
	    if (xKey[1]==OSM::szNAME[1])//a
	      if (xKey[2]==OSM::szNAME[2])//m
		if (xKey[3]==OSM::szNAME[3])//e
		  {

		    //		    current_name=val;

		    // now we check the county backwards. 
		    //		    if (val.rfind("County") != string::npos  )
		      {
			//name
			//			cout << "type:" << current_type << " current_id :" <<  current_id << " name: " << val;

			setName(val);
		      }
		    //County


		  }

	    break;

	  }
}

  void startElement(const XMLCh* const uri, const XMLCh* const localnameXML, const XMLCh* const qname, const Attributes& attrs)
  {
    current_id = getId(attrs); // the relation id
    if (current_id <0)
      {
	//	current_id=current_id*-1; // flip them for josm! 
      }
    if (world.max_id < current_id)
      {
	world.max_id =current_id;
      }
    current_interesting=0;   
    current_name=string("");   
    
    if((item_count++ % 1000000 )==0)
      {
	cerr << "Status:" << getCurrentType() << " count :" <<  item_count << endl;	
      }

  }
  virtual void endElement( const XMLCh * const uri,const XMLCh * const localName,const XMLCh * const qname )
  {
    if (report_end)
      {
	cout << "not interesting type:" << getCurrentType() << " current_id :" <<  current_id << " name: " << current_name;
	cout << endl;
      }

    //    current_name="";

  }
  
  //current_type = 'r'; // relation
  virtual char getCurrentType()=0;

};
