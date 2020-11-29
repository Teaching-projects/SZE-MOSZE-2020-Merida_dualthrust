#include "JSON.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <type_traits>
#include <fstream>
#include <sstream>
#include <type_traits>


JSON::JSON(const std::map<std::string, std::any>& incoming_content):content(incoming_content)
{

}

//Method for splitting a string by specific characters - similar to other programming languages' string.split methods
//Used for conveniently handling the input JSON files
std::vector<std::string> JSON::split(const std::string& s, char splitChar) 
{
	std::vector<std::string> output;
	std::string current_value;
	
	for (unsigned int i = 0; i < s.length(); i++) 
	{

		if (s[i] == splitChar || i == s.length() - 1) 
		{

			if (i == s.length() - 1) 
			{
				current_value += s[i];
			}

			output.push_back(current_value);
			current_value = "";
		}
		else 
		{
			current_value += s[i];
		}
	}

	return output;
}

std::vector<std::string> JSON::splitRowsJSON(const std::string& s)
{
	std::vector<std::string> output;
	std::string current_value;

	bool list_open=false;

	for (unsigned int i = 0; i < s.length()-1; i++)
	{
		std::string remaining = s.substr(i+1, s.length());
		remaining.erase(remove_if(remaining.begin(), remaining.end(), isspace), remaining.end());

		if (s[i]=='['){ list_open=true;}
		if (s[i]==']'){ list_open=false;}

		if ((s[i] == ',' && remaining[0]=='"' && !list_open) || (i == s.length() - 2 && !list_open))
		{
			current_value += s[i];
			output.push_back(current_value);
			current_value = "";
		}
		else
		{
			current_value += s[i];
		}
	}

	return output;
}

std::string JSON::removeJSONSpaces(std::string value) 
{
	std::string spaceless = value;
	spaceless.erase(remove_if(spaceless.begin(), spaceless.end(), isspace), spaceless.end());

	if (spaceless[0] == '"') 
	{
		value = value.substr(value.find('"'), value.size());
	}
	else 
	{
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
	}

	return value;
}

//Delete every existing Character object given as input
void JSON::deleteCharacters(const std::vector<Monster*>& characters) 
{

	for (Monster* c : characters) 
    {
		delete c;
	}
}

std::list<std::variant<std::string, int, double, float>> JSON::listFromValues(std::string rawList){
	std::list<std::variant<std::string, int, double, float>> output;
	std::vector<std::string> s = split(rawList,',');

	for(unsigned int i=0;i<s.size();i++){
		std::string processed_string = removeJSONSpaces(s[i]);
		processed_string.erase(remove(processed_string.begin(), processed_string.end(), '['), processed_string.end());
		processed_string.erase(remove(processed_string.begin(), processed_string.end(), ']'), processed_string.end());
		processed_string.erase(remove(processed_string.begin(), processed_string.end(), ','), processed_string.end());
		processed_string.erase(remove(processed_string.begin(), processed_string.end(), '"'), processed_string.end());

		if(processed_string!=""){
			output.push_back(processed_string);
		}
	}
	return output;
}

JSON JSON::parseString(std::string const &json_string)
{
	std::map<std::string, std::any> parsedMap;
	std::vector<std::string> rows = splitRowsJSON(json_string);

	//Check if the file contains '{' and '}' delimiters
	std::string spaceless = json_string;
	spaceless.erase(remove_if(spaceless.begin(), spaceless.end(), isspace), spaceless.end());
	if(spaceless[0] != '{' || spaceless[spaceless.length()-1]!='}'){
		throw ParseException();
	}

	for (auto& row : rows) // access by reference to avoid copying
	{
		//Delete '{' and '}' from the raw string
		row.erase(remove(row.begin(), row.end(), '{'), row.end());
		row.erase(remove(row.begin(), row.end(), '}'), row.end());

		spaceless = row;
		spaceless.erase(remove_if(spaceless.begin(), spaceless.end(), isspace), spaceless.end());

		//Delete linebreaks
		row.erase(std::remove(row.begin(), row.end(), '\n'), row.end());
		row = row.substr(row.find('"'), row.size());

		std::string key;
		std::string value;

		try 
		{
			key = removeJSONSpaces(split(split(row, '"')[1], '"')[0]);
			value = removeJSONSpaces(split(row, ':')[1]);
		}
		catch (const std::exception& ex) {
			throw ParseException();
		}

		////If the value is a string, we remove the " characters
		if (value[0] == '"') 
		{
			value = value.substr(1, value.length());
			value = value.substr(0, value.rfind('"'));
			parsedMap.insert({ key,value });
		}
		else 
		{
			parsedMap.insert({ key, value });
		}

	}

	return JSON(parsedMap);
}

JSON JSON::parseStream(std::ifstream &f) {
	if (f.good())
	{
		//We read the whole file into a string variable using ifstream and stringstream, then pass it to the parseString method
		std::stringstream s;
		s << f.rdbuf();
		std::string fileContents = s.str();
		f.close();
		return parseString(fileContents);
	}
	else
	{
		std::map<std::string, std::any> empty_content;
		return JSON(empty_content);
	}
}

JSON JSON::parseFromFile(const std::string& path)
{
	std::ifstream f(path);
	//We check if the file given as input exists
	if (f.good())
	{
		return parseStream(f);
	}
	else
	{
		std::map<std::string, std::any> empty_content;
		return JSON(empty_content);
	}
}

int JSON::count(std::string key)
{
	return this->content.count(key);
}