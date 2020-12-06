#include "../Damage.h"
#include "../Game.cpp"
#include "../Hero.cpp"
#include "../JSON.cpp"
#include "../Map.cpp"
#include "../Monster.cpp"
#include <gtest/gtest.h>

//Test for the Monster and Hero class

TEST(unitTests, parseMonster){
    ASSERT_NO_THROW(Monster::parse("../Zombie.json"));
}

TEST(unitTests, parseHero){
    ASSERT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}

TEST(unitTests, isAlive){
    Damage().physical=0;
    Monster dead = Monster("Dead",0,0,0,0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, getHealth){
    Damage().physical=1000;
    Monster healthy = Monster("Healthy",1000,1000,1000,1000,1000);
    ASSERT_EQ(healthy.getHealthPoints(), 1000);
}

TEST(unitTests, getPhysicalDamage){
    Damage().physical=1000;
    Monster strong = Monster("strong",1000,1000,1000,1000,1000);
    ASSERT_EQ(strong.getPhysicalDamage(), 1000);
}
TEST(unitTests, getMagicalDamage){
    Damage().magical=1000;
    Monster stronger = Monster("stronger",1000,1000,1000,1000,1000);
    ASSERT_EQ(stronger.getMagicalDamage(), 1000);
}
TEST(unitTests, getDefense){
    Damage().physical=1000;
    Monster defender = Monster("defender",1000,1000,1000,1000,1000);
    ASSERT_EQ(defender.getDefense(), 1000);
}

TEST(unitTests, sufferDamage){
    Damage().physical=10;
    Damage().magical=10;
    Monster attacker = Monster("Attacker",10,10,10,10,10);
    Damage().physical=1;
    Damage().magical=1;
    Monster dead = Monster("Dead",1,1,1,1,1);
    dead.sufferDamage(&attacker);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, levelUp){
    Damage().physical=100;
    Damage().magical=100;
    Hero hero = Hero("Hero",100,100,100,100,100,100,100,100,100,100,2);
    Damage().physical=1;
    Damage().magical=1;
    Monster enemy = Monster("Monster",100,1,1,1,1);
    hero.fightTilDeath(enemy);

    ASSERT_EQ(hero.getLevel(),2);
    ASSERT_EQ(hero.getHealthPoints(),200);
    ASSERT_EQ(hero.getAttackCoolDown(),200);
    ASSERT_EQ(hero.getDamage().physical,200);
    ASSERT_EQ(hero.getDamage().magical,200);
    ASSERT_EQ(hero.getDefense(),200);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}