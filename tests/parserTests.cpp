#include "../Utility.cpp"

#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(Utility::parseFile("../units/Tolvaj.json"));
}

TEST(parserTests, badFormat_missing_doubledot) {
    ASSERT_NO_THROW(Utility::parseString("{ \"str\" \"Robin\",\"float\" : 15.05 }"));
}

TEST(parserTests, badFormat_missing_curly_bracket) {
    ASSERT_NO_THROW(Utility::parseString(" \"str\" : \"Robin\",\"float\" : 15.05 }"));
}

TEST(parserTests, badFormat_missing_apostrophe) {
    ASSERT_NO_THROW(Utility::parseString(" \"str\" : Robin,\"float\" : 15.05 }"));
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