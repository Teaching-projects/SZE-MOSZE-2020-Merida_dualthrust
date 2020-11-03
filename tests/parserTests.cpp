#include "../JSON.cpp"

#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(JSON::parseFromFile("../units/Tolvaj.json"));
}

TEST(parserTests, ParseFromStream) {
    std::ifstream f("../units.Tolvaj.json");
    ASSERT_NO_THROW(JSON::parseStream(f));
}

//==========================================================================

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}