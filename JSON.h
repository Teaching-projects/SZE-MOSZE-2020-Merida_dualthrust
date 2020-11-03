/**
 * @file JSON.h
 * @author lapatkrisz
 * @class JSON
 * 
 * @brief JSON namespace
 * 
 * @version 1.0
 * @date 2020-10-11
 * 
 */
#ifndef JSON_HEADER
#define JSON_HEADER
#include <exception>
#include <string>
#include <vector>
#include "Monster.h"
#include <map>
#include <any>
#include <fstream>
#include <sstream>
#include <iostream>

class JSON {
public:
    /**
     * @brief Constructor for JSON object.
     * 
     */
    JSON(const std::map<std::string, std::any>&);
        
    template <typename T>
    T get(std::string key){
        std::string value =  std::any_cast<std::string>(content[key]);
        std::any converted;
        if (std::is_same<T, int>::value){
            converted=(std::stoi(value));
        }else if(std::is_same<T, float>::value){
            converted=(std::stof(value));
        }else if(std::is_same<T, std::string>::value){
            converted=value;
        }
        
        return std::any_cast<T>(converted);
    }

    int count(std::string);
    /**
     * @brief Method for checking if a given input is a number or not.
     * @param[in] string
     * @return true, if we get numbers correctly
     * @return false, if the input's size is 0 or it isn't number
     * 
     */
    bool isNumber(const std::string&);

    /**
     * @brief Utility method for handling strings, works similarly to other programming languages' split method.
     * 
     * @return std::vector<std::string> 
     * 
     */
    static std::vector<std::string> split(const std::string&, char);
    /**
     * @brief Specific splitting method for JSON files, responsible for finding the JSON rows in a given JSON string.
     * 
     * @return std::vector<std::string> 
     * 
     */
    static std::vector<std::string> splitRowsJSON(const std::string&);
    /**
     * @brief Specific whitespace remover method for JSON files, responsible for removing whitespaces from a given JSON string.
     * 
     * @return std::string 
     * 
     */
    static std::string removeJSONSpaces(std::string);

    /**
     * @brief JSON parser method. Takes a filepath as input and returns an object of the JSON class.
     * 
     * @return JSON 
     * 
     */
    static JSON parseString(const std::string&);
    /**
     * @brief JSON parser method, takes an ifstream as an input and returns an object of the JSON class.
     * 
     * @return JSON 
     * 
     */
    static JSON parseStream(std::ifstream&);
    /**
     * @brief JSON parser method, takes a string as an input and returns an object of the JSON class.
     * 
     * @return JSON 
     * 
     */
    static JSON parseFromFile(const std::string&);

    /**
     * @brief Delete every existing Character object given as input.
     * @param[in] Character vector
     * 
     */
    void deleteCharacters(const std::vector<Monster*>&);
    std::vector<std::string> getJsonData(const std::string&);

    class ParseException : std::exception
	{
		public:
		ParseException(){}
	};

    protected:
        std::map<std::string, std::any> content;
};

#endif