#include "../Utility.cpp"

#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(Utility::parseFile("../units/Tolvaj.json"));
}

TEST(parserTests, badFormat_missing_doubledot) {
    int mapSize = Utility::parseString("{ \"str\" \"Robin\",\"float\" : 15.05 }").size();
    ASSERT_EQ(0,0);
}

TEST(parserTests, badFormat_missing_curly_bracket) {
    int mapSize = Utility::parseString(" \"str\" : \"Robin\",\"float\" : 15.05 }").size();
    ASSERT_EQ(mapSize, 0);
}

TEST(parserTests, badFormat_missing_apostrophe) {
    int mapSize = Utility::parseString(" \"str\" : Robin,\"float\" : 15.05 }").size();
    ASSERT_EQ(mapSize, 0);
}

TEST(parserTests, TypeParseCheck) {
    std::map<std::string, std::any> parsedJson = Utility::parseString("{ \"str\" : \"Robin\",\"float\" : 15.05 }");
    ASSERT_EQ(std::any_cast<std::string>(parsedJson["str"]), "Robin");
    ASSERT_EQ(std::any_cast<float>(parsedJson["float"]), 15.05f);
}

TEST(parserTests, ParseFromStream) {
    std::ifstream f("../units.Tolvaj.json");
    ASSERT_NO_THROW(Utility::parseStream(f));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}