// This Version of RemSQL does not support BINARY, VARBINARY, CHAR " MySQL STRING DATATYPES"

#include <iostream>
#include <string>

using namespace std;

bool checkVARCHAR(string str){
	if(str.size() <= 255)
		return true;

	return false;
} 

bool checkTINYTEXT(string str){
	if(str.size() <= 255)
		return true;
	return false;
}

bool checkTEXT(){
	if(str.size() <= 65535)
		return true;
	return false;	
}

bool checkMEDIUMTEXT(){
	if(str.size() <= 16777215)
		return true;
	return false;
}

bool checkLONGTEXT(){
	if(str.size() <= 4294967295)
		return true;
	return false;	
}
