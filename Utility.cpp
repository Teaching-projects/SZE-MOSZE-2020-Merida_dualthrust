#include "Utility.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <sstream>

//Method for getting data from a JSON file
std::vector<std::string> Utility::getJsonData(const std::string& path)
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
        std::string HP = split(Utility::split(fileContents, ',')[1], ':')[1]; //We get the HP value from the file - we split the string between the second ',' character and ':' character, and parse it into an integer
        std::string DMG = split(Utility::split(fileContents, ':')[3], '}')[0]; //We get the DMG value from the file - we split the string between the third ':' character and '}' character, and parse it into an integer

        return std::vector<std::string> {name, HP, DMG};
    }
    else
    {
        //If the input file doesn't exist, we return null
        return std::vector<std::string>{};
    }
}

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