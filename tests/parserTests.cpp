#include "../Utility.cpp"

#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(Utility::parseFile("../units/Tolvaj.json"));
}

TEST(parserTests, TypeParseCheck) {
    std::map<std::string, std::any> parsedJson = Utility::parseString("{ \"str\" : \"Robin\",\"float\" : 15.05 }");
    ASSERT_EQ(std::any_cast<std::string>(parsedJson["str"]), "Robin");
    ASSERT_EQ(std::any_cast<float>(parsedJson["float"]), 15.05f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}