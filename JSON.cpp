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

//Method for getting data from a JSON file
std::vector<std::string> JSON::getJsonData(const std::string& path)
{
    std::ifstream f(path);

    //We check if the file given as input exists
    if (f.good())
    {
        //We read the whole file into a string variable using ifstream and stringstream
        //We do this because since we'll use the split method anyway, a counter variable holding which row we're currently reading is not needed
        //This saves us a few addition and divide operations here
        std::stringstream s;
        s << f.rdbuf();
        std::string fileContents = s.str();
        f.close();

        //We save the values we need - this could be inlined into the Character constructor call, but the code is clearer this way
        std::string name		= split(fileContents, '"')[3]; //We get the name from the file
        std::string healthPoint			= split(JSON::split(fileContents, ',')[1], ':')[1]; //We get the healthPoint value from the file - we split the string between the second ',' character and ':' character, and parse it into an integer
        std::string DMG			= split(JSON::split(fileContents, ',')[2], ':')[1]; //We get the DMG value from the file - we split the string between the third ',' character and ':' character, and parse it into an integer
        std::string cooldown	= split(JSON::split(fileContents, ':')[4], '}')[0]; //We get the cooldown value from the file - we split the string between the fourth ':' character and '}' character, and parse it into an integer

        return std::vector<std::string> {name, healthPoint, DMG, cooldown};
    }
    else
    {
        //If the input file doesn't exist, we return null
        return std::vector<std::string>{};
    }
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

	for (unsigned int i = 0; i < s.length()-1; i++)
	{
		std::string remaining = s.substr(i+1, s.length());
		remaining.erase(remove_if(remaining.begin(), remaining.end(), isspace), remaining.end());

		if ((s[i] == ',' && remaining[0]=='"') || i == s.length() - 2)
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

JSON JSON::parseString(std::string const &json_string)
{
	std::map<std::string, std::any> parsedMap;
	std::vector<std::string> rows = splitRowsJSON(json_string);

	for (auto& row : rows) // access by reference to avoid copying
	{
		//Delete '{' and '}' from the raw string
		row.erase(remove(row.begin(), row.end(), '{'), row.end());
		row.erase(remove(row.begin(), row.end(), '}'), row.end());

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
		catch (const std::exception& ex) {}

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