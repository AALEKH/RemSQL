// Fortunately this supports all kind of DataTypes
// Try to Add these support as early as possible

#include <iostream>
#include <string>
#include <sstream>
#include <regex>

// Interesting : http://stackoverflow.com/questions/1505582/determining-32-vs-64-bit-in-c


using namespace std;

bool checkYear(int year){
	if (year.fail()) // Check if the supplied value is integer
			return false;
	if (year/1000 > 0 && year/1 <= 9) // Check for No. of digits to be 4 Digit
		return false;
	if (year < 1970) // Check if Date Year is greater than 1970 (Unix TimeStamp Condition)
		return false;		
	return true;	
}
