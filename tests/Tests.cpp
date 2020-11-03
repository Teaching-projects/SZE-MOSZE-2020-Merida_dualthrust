#include "../JSON.cpp"
#include "../Monster.cpp"
#include "../Hero.cpp"
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

TEST(unitTests, parseMonster){
    ASSERT_NO_THROW(Monster::parse("../Zombie.json"));
}

TEST(unitTests, parseHero){
    ASSERT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}

TEST(unitTests, isAlive){
    Monster dead = Monster("Dead",0,0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, sufferDamage){
    Monster attacker = Monster("Attacker",10,10,10);
    Monster dead = Monster("Dead",10,10,10);
    dead.sufferDamage(&attacker);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, levelUp){
    Hero hero = Hero("Hero",100,100,100,100,100,100,2);
    Monster enemy = Monster("Monster",100,1,1);
    hero.fightTilDeath(enemy);

    ASSERT_EQ(hero.getLevel(),2);
    ASSERT_EQ(hero.getHealthPoints(),200);
    ASSERT_EQ(hero.getAttackCoolDown(),200);
    ASSERT_EQ(hero.getDamage(),200);
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}