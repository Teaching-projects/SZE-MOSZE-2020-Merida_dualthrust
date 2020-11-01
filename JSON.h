/**
 * @file JSON.h
 * @author lapatkrisz
 * @class JSON
 * 
 * @brief JSON namespace
 * 
 * @version 1.0
 * @date 2020-10-11
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


class JSON {
public:
    //constructors
    JSON(const std::map<std::string, std::string>&);
    
    std::map<std::string, std::string> content;
    
    template <typename T>
    T get(std::string key){
        return std::any_cast<T>(content[key]);
    }

    int count(std::string);
    /**
     * @brief Method for checking if a given input is a number or not
     * @param[in] string
     * @return true, if we get numbers correctly
     * @return false, if the input's size is 0 or it isn't number
     */
    bool isNumber(const std::string&);
    /**
     * @brief Method for splitting a string by specific characters
     * @param[in] string, char
     * @return Output vector which contains strings
     */
    static std::vector<std::string> split(const std::string&, char);
    static std::vector<std::string> splitRowsJSON(const std::string&);
    static std::string removeJSONSpaces(std::string);

    static JSON parseString(const std::string&);
    static JSON parseStream(std::ifstream&);
    static JSON parseFromFile(const std::string&);

    /**
     * @brief Delete every existing Character object given as input
     * @param[in] Character vector
     */
    void deleteCharacters(const std::vector<Monster*>&);
    std::vector<std::string> getJsonData(const std::string&);

    class ParseException : std::exception
	{
		public:
		ParseException(){}
	};
};

#endif