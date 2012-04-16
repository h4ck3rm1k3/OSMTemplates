/* 
   taken from 
   http://www.luckyspin.org/?p=28

   build:g++ getpart.cpp  -lcurl -o getpart

   test : getpart http://downloads.cloudmade.com/north_america/united_states/new_jersey/new_jersey.osm.bz2

 */  

#include <string>  
#include <stdio.h>  
#include <stdlib.h>  
#include <iostream>  
#include <sstream>  
#include "curl/curl.h"  
   
using namespace std;  
   
// Write any errors in here  
static char errorBuffer[CURL_ERROR_SIZE];  
   
// Write all expected data in here  
static string buffer;  
   
// This is the writer call back function used by curl  
static int writer(char *data, size_t size, size_t nmemb,  
		  std::string *buffer)  
{  
  // What we will return  
  int result = 0;  
   
  // Is there anything in the buffer?  
  if (buffer != NULL)  
    {  
      // Append the data to the buffer  
      buffer->append(data, size * nmemb);  
   
      // How much did we write?  
      result = size * nmemb;  
    }  
   
  return result;  
}  
   
// You know what this does..  
void usage()  
{  
  cout << "curltest: \n" << endl;  
  cout << "  Usage:  curltest url\n" << endl;  
}   
   
/* 
 * The old favorite 
 */  
int main(int argc, char* argv[])  
{  
  if (argc > 1)  
    {  
      string url(argv[1]);  
   
      cout << "Retrieving " << url << endl;  
   
      // Our curl objects  
      CURL *curl;  
      CURLcode result;  
   
      // Create our curl handle  
      curl = curl_easy_init();  
   
      if (curl)  
	{  
	  // Now set up all of the curl options  
	  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);  
	  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);  
	  curl_easy_setopt(curl, CURLOPT_HEADER, 0);  
	  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);  
	  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);  
	  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);  
	  //   CURLOPT_HTTPHEADER

	  int startpos =0;
	  int endpos   =10000;
	  std::ostringstream tmpbuffer;
	  tmpbuffer << "Range: bytes=" << startpos << "-" << endpos -1;
	  string rangeattr = string (tmpbuffer.str());    

	  // 'Range' => sprintf("bytes=%s-%s",
	  // 				 $startpos ,
	  // 				 $endpos - 1
	  // 	  )

	  struct curl_slist *headers=NULL; /* init to NULL is important */
	  headers = curl_slist_append(headers, rangeattr.c_str());
  	  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);



	  // Attempt to retrieve the remote page  
	  result = curl_easy_perform(curl);  

	  curl_slist_free_all(headers); /* free the header list */ 
   
	  // Always cleanup  
	  curl_easy_cleanup(curl);  
   
	  // Did we succeed?  
	  if (result == CURLE_OK)  
	    {  
	      cout << "Buffer:" << buffer << "\n";  
	      exit(0);  
	    }  
	  else  
	    {  
	      cout << "Error: [" << result << "] - " << errorBuffer;  
	      exit(-1);  
	    }  
	}  
    }  
}  
