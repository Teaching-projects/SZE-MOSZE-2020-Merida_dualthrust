/**
 * @file Utility.h
 * @author lapatkrisz
 * @class Utility
 * 
 * @brief Utility namespace
 * 
 * @version 1.0
 * @date 2020-10-11
 */
#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include <string>
#include <vector>
#include "Monster.h"
#include <map>
#include <any>
#include <fstream>
#include <sstream>

namespace Utility {
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
    std::vector<std::string> split(const std::string&, char);

    std::map<std::string, std::any> parseString(std::string);
    std::map<std::string, std::any> parseStream(std::ifstream&);
    std::map<std::string, std::any> parseFile(const std::string&);

    /**
     * @brief Delete every existing Character object given as input
     * @param[in] Character vector
     */
    void deleteCharacters(const std::vector<Monster*>&);
    std::vector<std::string> getJsonData(const std::string&);
};

#endif