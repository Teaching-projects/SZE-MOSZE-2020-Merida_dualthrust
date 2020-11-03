#include "../JSON.cpp"

#include <gtest/gtest.h>

TEST(parserTests, parseFile) {
    ASSERT_NO_THROW(JSON::parseFromFile("../units/Tolvaj.json"));
}

TEST(parserTests, ParseFromStream) {
    std::ifstream f("../units.Tolvaj.json");
    ASSERT_NO_THROW(JSON::parseStream(f));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}