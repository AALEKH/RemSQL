#include <iostream>
#include <string>
// For JSON Parsing stuff, see this: https://github.com/nlohmann/json, quite the best for C++
#include "json/src/json.hpp"
#include <string>
#include <sstream>

using namespace std;

string getStringRelation(int primary_key, string value){

	nlohmann::json j;
	j["primary_key"] = primary_key;
	j["value"] = value;
	return j.dump();
}