#include "Utility.h"
#include <iostream>
#include <cctype>
#include <algorithm>
#include <type_traits>

//Method for checking if a given input is a number or not
bool Utility::isNumber(const std::string& input) 
{
    if (input.size() == 0) return false;
    for (char c : input) 
	{
        if (!isdigit(c)) 
		{
            return false;
        }
    }
    return true;
}

//Method for splitting a string by specific characters - similar to other programming languages' string.split methods
//Used for conveniently handling the input JSON files
std::vector<std::string> Utility::split(const std::string& s, char splitChar) 
{
	std::vector<std::string> output;
	std::string current_value;
	
	for (int i = 0; i < s.length(); i++) 
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
void Utility::deleteCharacters(const std::vector<Character*>& characters) {
	for (Character* c : characters) {
		delete c;
	}
}

std::map<std::string, std::any> Utility::parseString(std::string json_string)
{
	std::map<std::string, std::any> parsedMap;
	std::vector<std::string> rows = split(json_string, ',');

	for (auto& row : rows) // access by reference to avoid copying
	{
		//Delete '{' and '}' from the raw string
		row.erase(remove(row.begin(), row.end(), '{'), row.end());
		row.erase(remove(row.begin(), row.end(), '}'), row.end());

		std::string key = split(split(row, '"')[1], '"')[0];
		std::string value = split(row, ':')[1];
		//Delete spaces from the value - we can assume the values are correct, as stated in the task description
		value.erase(remove_if(value.begin(), value.end(), isspace), value.end());

		//If the value is a string, we remove the " characters
		if (value[0] == '"') {
			value = value.substr(1, value.length() - 2);
			parsedMap.insert({ key,value});
		}
		else{
			try {
				parsedMap.insert({ key, std::stof(value) });
			}catch(int ex){}
		}

	}
   
	return parsedMap;
}

std::map<std::string, std::any> Utility::parseStream(std::ifstream &f) {
	if (f.good())
	{
		//We read the whole file into a string variable using ifstream and stringstream
		//We do this because since we'll use the split method anyway, a counter variable holding which row we're currently reading is not needed
		//This saves us a few addition and divide operations here
		std::stringstream s;
		s << f.rdbuf();
		std::string fileContents = s.str();
		f.close();

		return parseString(fileContents);
	}
	else
	{
		//If the input file doesn't exist, we return an empty map
		std::map<std::string, std::any> emptyMap;
		return 	emptyMap;
	}
}

std::map<std::string, std::any> Utility::parseFile(const std::string& path)
{
	std::ifstream f(path);
	//We check if the file given as input exists
	if (f.good())
	{
		return parseStream(f);
	}
	else
	{
		//If the input file doesn't exist, we return an empty map
		std::map<std::string, std::any> emptyMap;
		return 	emptyMap;
	}
}