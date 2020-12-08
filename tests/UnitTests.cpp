#include "../Damage.h"
#include "../Game.cpp"
#include "../Hero.cpp"
#include "../JSON.cpp"
#include "../Map.cpp"
#include "../Monster.cpp"
#include <gtest/gtest.h>

//Test for the Monster class

TEST(unitTests, parseMonster){
    ASSERT_NO_THROW(Monster::parse("../Zombie.json"));
}

TEST(unitTests, isAlive){
    Monster dead = Monster("Dead",0,Damage(100,100),0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, getHealth){
    Monster healthy = Monster("Healthy",1000,Damage(1000,1000),1000,1000);
    ASSERT_EQ(healthy.getHealthPoints(), 1000);
}

TEST(unitTests, getPhysicalDamage){
    Monster strong = Monster("strong",1000,Damage(1000,1000),1000,1000);
    ASSERT_EQ(strong.getPhysicalDamage(), 1000);
}
TEST(unitTests, getMagicalDamage){
    Monster stronger = Monster("stronger",1000,Damage(1000,1000),1000,1000);
    ASSERT_EQ(stronger.getMagicalDamage(), 1000);
}
TEST(unitTests, getDefense){
    Monster defender = Monster("defender",1000,Damage(1000,1000),1000,1000);
    ASSERT_EQ(defender.getDefense(), 1000);
}

TEST(unitTests, getACD){
    Monster strong = Monster("strong",1000,Damage(1000,1000),1000,1000);
    ASSERT_EQ(strong.getAttackCoolDown(), 1000);
}

TEST(unitTests, sufferDamage){
    Monster attacker = Monster("Attacker",10,Damage(10,10),10,10);
    Monster dead = Monster("Dead",1,Damage(100,100),1,1);
    dead.sufferDamage(&attacker);
    ASSERT_EQ(dead.isAlive(), false);
}

//Test for the Hero class

TEST(unitTests, parseHero){
    ASSERT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}

TEST(unitTests, levelUp){
    Hero hero = Hero("Hero",100,Damage(100,100),100,100,100,100,100,100,100,100,100,2);
    Monster enemy = Monster("Monster",100,Damage(100,100),1,1);
    hero.fightTilDeath(enemy);
    //This levelup test also test the constructor, the fighttildeath method, as well as most of the getters.
    ASSERT_EQ(hero.getLevel(),2);
    ASSERT_EQ(hero.getHealthPoints(),200);
    ASSERT_EQ(hero.getAttackCoolDown(),200);
    ASSERT_EQ(hero.getPhysicalDamage(),200);
    ASSERT_EQ(hero.getMagicalDamage(),200);
    ASSERT_EQ(hero.getDefense(),200);
    ASSERT_EQ(hero.getLightRadius(),200);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}