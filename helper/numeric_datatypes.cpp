// This Version of RemSQL does not support BIT, BOOLEAN, DECIMAL, DEC, DOUBLE PRECISION, REAL " MySQL NUMERIC DATATYPES"
// Try to Add these support as early as possible

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isFloat( string myString ) {
    std::istringstream iss(myString);
    float f;
    iss >> noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail(); 
}

// Create a function that returns unsigned returns 1, signed return 2

// For TINYINT DataType
bool checkTINYINT(int value, int check){
	switch(check){
		case 1: //for unsigned
			if(value >= -128 && value < 128)
				return true;
			break;
		case 2: //for signed
			if(value < 256 && value >= 0)
				return true;
			break;
		default
			return false;	
	}
}

// For SMALLINT DataType
bool checkSMALLINT(int value, int check){
	switch(check){
		case 1: //for unsigned
			if(value >= -32768 && value < 32768)
				return true;
			break;
		case 2: //for signed
			if(value < 65536 && value >= 0)
				return true;
			break;
		default
			return false;	
	}
}

// FOR MEDIUMINT DataType
bool checkMEDIUMINT(int value, int check){
	switch(check){
		case 1: //for unsigned
			if(value >= -8388608 && value < 8388608)
				return true;
			break;
		case 2: //for signed
			if(value < 16777216 && value >= 0)
				return true;
			break;
		default
			return false;	
	}
}

// For INTEGER DataType
bool checkINTEGER(int value, int check){
	switch(check){
		case 1: //for unsigned
			if(value >= -2147483648 && value < 2147483648)
				return true;
			break;
		case 2: //for signed
			if(value < 4294967296 && value >= 0)
				return true;
			break;
		default
			return false;	
	}	
}

// For BIGINT DataType
bool checkBIGINT(int value, int check){
	// -9223372036854775808 
	switch(check){
		case 1: //for unsigned
			if(value >= -9223372036854775808 && value < 9223372036854775808)
				return true;
			break;
		case 2: //for signed
			if(value < 18446744073709551616 && value >= 0)
				return true;
			break;
		default
			return false;	
	}
}

// For Float DataType
bool checkFloat(float flt){
	return isFloat(to_string(flt));
}

// For Double DataType
bool checkDouble(const char* str)
{
    char* endptr = 0;
    strtod(str, &endptr);

    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}