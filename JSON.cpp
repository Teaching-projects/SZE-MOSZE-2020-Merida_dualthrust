#include "JSON.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <type_traits>
#include <fstream>
#include <sstream>
#include <type_traits>


JSON::JSON(const std::map<std::string, std::any>& incoming_content):content(incoming_content){    }

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
        std::string name = split(fileContents, '"')[3]; //We get the name from the file
        std::string HP = split(JSON::split(fileContents, ',')[1], ':')[1]; //We get the HP value from the file - we split the string between the second ',' character and ':' character, and parse it into an integer
        std::string DMG = split(JSON::split(fileContents, ',')[2], ':')[1]; //We get the DMG value from the file - we split the string between the third ',' character and ':' character, and parse it into an integer
        std::string ACD = split(JSON::split(fileContents, ':')[4], '}')[0]; //We get the ACD value from the file - we split the string between the fourth ':' character and '}' character, and parse it into an integer

        return std::vector<std::string> {name, HP, DMG, ACD};
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

//Delete every existing Character object given as input
void JSON::deleteCharacters(const std::vector<Monster*>& characters) 
{
	for (Monster* c : characters) 
    {
		delete c;
	}
}

JSON JSON::parseString(std::string &json_string)
{
	std::map<std::string, std::any> parsedMap;
	std::vector<std::string> rows = split(json_string, ',');

	for (auto& row : rows) // access by reference to avoid copying
	{
		//Delete '{' and '}' from the raw string
		row.erase(remove(row.begin(), row.end(), '{'), row.end());
		row.erase(remove(row.begin(), row.end(), '}'), row.end());

		std::string key;
		std::string value;

		try {
			key = split(split(row, '"')[1], '"')[0];
			value = split(row, ':')[1];
		}
		catch (const std::exception& ex) {}

		//Delete spaces from the value
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
		//If the value is a string, we remove the " characters
		if (value[0] == '"') {
			value = value.substr(1, value.length() - 2);
			parsedMap.insert({ key,value});
		}
		else{
			//If the value isn't a string, we parse it into a float
			try {
				parsedMap.insert({ key, std::stof(value) });
			}catch(const std::exception& ex){
				std::map<std::string, std::any> empty_content;
				return JSON(empty_content);
			}
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
	}else{
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
	}else{
		std::map<std::string, std::any> empty_content;
		return JSON(empty_content);
	}
}

int JSON::count(std::string key){
	return this->content.count(key);
}
