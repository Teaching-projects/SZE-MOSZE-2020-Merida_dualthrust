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
    Damage dmg (0, 0);
    Monster dead = Monster("Dead",0,dmg,0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, getHealth){
    Damage dmg (1000, 1000);
    Monster healthy = Monster("Healthy",1000,dmg,1000,1000);
    ASSERT_EQ(healthy.getHealthPoints(), 1000);
}

TEST(unitTests, getPhysicalDamage){
    Damage dmg (1000, 1000);
    Monster strong = Monster("strong",1000,dmg,1000,1000);
    ASSERT_EQ(strong.getPhysicalDamage(), 1000);
}
TEST(unitTests, getMagicalDamage){
    Damage dmg (1000, 1000);
    Monster stronger = Monster("stronger",1000,dmg,1000,1000);
    ASSERT_EQ(stronger.getMagicalDamage(), 1000);
}
TEST(unitTests, getDefense){
    Damage dmg (1000, 1000);
    Monster defender = Monster("defender",1000,dmg,1000,1000);
    ASSERT_EQ(defender.getDefense(), 1000);
}

TEST(unitTests, sufferDamage){
    Damage dmg_1 (10, 10);
    Monster attacker = Monster("Attacker",10,dmg_1,10,10);
    Damage dmg_2 (1, 1);
    Monster dead = Monster("Dead",1,dmg_2,1,1);
    dead.sufferDamage(&attacker);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, levelUp){
    Damage dmg_1 (100, 100);
    Hero hero = Hero("Hero",100,dmg_1,100,100,100,100,100,100,2);
    Damage dmg_2 (1, 1);
    Monster enemy = Monster("Monster",100,dmg_2,1,1);
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