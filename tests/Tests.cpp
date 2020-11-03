#include "../JSON.cpp"
#include "../Monster.h"
#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(JSON::parseFromFile("../units/Tolvaj.json"));
}

TEST(parserTests, ParseFromStream) {
    std::ifstream f("../units.Tolvaj.json");
    ASSERT_NO_THROW(JSON::parseStream(f));
}

//TESTS FOR THE JSON CLASS

TEST(parserTests, TypeCastCheck) {
    JSON data = JSON::parseFromFile("./Testfiles/normal.json");
    ASSERT_EQ(data.get<std::string>("string"), "Merida Dualthrust");
    ASSERT_EQ(data.get<int>("int"), 100);
    ASSERT_EQ(data.get<float>("float"), 0.1f);
}

TEST(parserTests, Format_oneLine) {
    JSON data = JSON::parseFromFile("./Testfiles/oneline.json");
    ASSERT_EQ(data.get<std::string>("string"), "Merida Dualthrust");
    ASSERT_EQ(data.get<int>("int"), 100);
    ASSERT_EQ(data.get<float>("float"), 0.1f);
}

TEST(parserTests, Format_mixed) {
    JSON normal_order = JSON::parseFromFile("./Testfiles/normal.json");
    JSON mixed_order  = JSON::parseFromFile("./Testfiles/mixed_order.json");
    ASSERT_EQ(normal_order.get<std::string>("string"), mixed_order.get<std::string>("string"));
    ASSERT_EQ(normal_order.get<int>("int"), mixed_order.get<int>("int"));
    ASSERT_EQ(normal_order.get<float>("float"),mixed_order.get<float>("float"));
}

TEST(parserTests, Format_whitespaces) {
    JSON normal = JSON::parseFromFile("./Testfiles/normal.json");
    JSON spaces  = JSON::parseFromFile("./Testfiles/whitespaces.json");
    ASSERT_EQ(normal.get<std::string>("string"), spaces.get<std::string>("string"));
    ASSERT_EQ(normal.get<int>("int"), spaces.get<int>("int"));
    ASSERT_EQ(normal.get<float>("float"),spaces.get<float>("float"));
}

TEST(parserTests, Format_badDelimiter) {
    bool parseException=false;
    try{
    JSON bad_delimiter = JSON::parseFromFile("./Testfiles/missing_curly.json");
    }catch(JSON::ParseException){
        parseException=true;
    }
    ASSERT_EQ(parseException,true);
}

//Test for the Monster and Hero class

TEST(unitTests, parseUnit){
    ASSERT_NO_THROW(Monster("asd",10,10,0.5));
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}