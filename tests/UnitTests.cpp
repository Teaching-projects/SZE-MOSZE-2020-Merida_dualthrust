#include "../JSON.cpp"
#include "../Monster.cpp"
#include "../Hero.cpp"
#include "../Damage.h"
#include <gtest/gtest.h>

//Test for the Monster and Hero class

TEST(unitTests, parseMonster){
    ASSERT_NO_THROW(Monster::parse("../Zombie.json"));
}

TEST(unitTests, parseHero){
    ASSERT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}

TEST(unitTests, isAlive){
    Monster dead = Monster("Dead",0,0,0,0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, getHealth){
    Monster healthy = Monster("Healthy",1000,1000,1000,1000,1000);
    ASSERT_EQ(healthy.getHealthPoints(), 1000);
}

TEST(unitTests, getPhysicalDamage){
    Monster strong = Monster("strong",1000,1000,1000,1000,1000);
    ASSERT_EQ(strong.getPhysicalDamage(), 1000);
}
TEST(unitTests, getMagicalDamage){
    Monster stronger = Monster("stronger",1000,1000,1000,1000,1000);
    ASSERT_EQ(stronger.getMagicalDamage(), 1000);
}
TEST(unitTests, getDefense){
    Monster defender = Monster("defender",1000,1000,1000,1000,1000);
    ASSERT_EQ(defender.getDefense(), 1000);
}

TEST(unitTests, sufferDamage){
    Monster attacker = Monster("Attacker",10,10,10,10,10);
    Monster dead = Monster("Dead",1,1,1,1,1);
    dead.sufferDamage(&attacker);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, levelUp){
    Damage tmp (10, 10);
    Hero hero = Hero("Hero",100,tmp,100,100,100,100,100,100,100,2);
    Monster enemy = Monster("Monster",1,tmp,1,1,1);
    hero.fightTilDeath(enemy);

    ASSERT_EQ(hero.getLevel(),2);
    ASSERT_EQ(hero.getHealthPoints(),200);
    ASSERT_EQ(hero.getAttackCoolDown(),200);
    ASSERT_EQ(hero.getPhysicalDamage(),200);
    ASSERT_EQ(hero.getMagicalDamage(),200);
    ASSERT_EQ(hero.getDefense(),200);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}