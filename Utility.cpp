#include "Utility.h"
#include <iostream>
#include <cctype>
#include <fstream>

//Method for checking if a given input is a number or not
bool Utility::isNumber(std::string input) 
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
std::vector<std::string> Utility::split(std::string s, char splitChar) 
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