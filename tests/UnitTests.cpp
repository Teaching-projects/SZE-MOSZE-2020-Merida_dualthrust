#include "../Damage.h"
#include "../Game.cpp"
#include "../PreparedGame.cpp"
#include "../Hero.cpp"
#include "../JSON.cpp"
#include "../Map.cpp"
#include "../MarkedMap.cpp"
#include "../Monster.cpp"
#include <gtest/gtest.h>

//Test for the Monster class 
//ALL DONE
// It has 16 public functions, 
//parse(path), Monster(name, hp, damage, defense, acd), ~Monster(),
//Monster(monster)(copy constructor), getName(), getPhysicalDamage(),
//getMagicalDamage(), getDefense(), getHealthPoints(), getACD(), sufferDamage(monsterpointer)
//setPosition(row, cloumn), getPosition(), deliverHit, fightTilDeath

TEST(unitTests, parseMonster){
    ASSERT_NO_THROW(Monster::parse("../Zombie.json"));
}

TEST(unitTests, MonsterCopyConstructor){
    Monster healthy = Monster("Healthy",1000,Damage(1000,1000),1000,1000);
    Monster healthytoo = Monster(healthy);
    ASSERT_EQ(healthytoo.getDefense(), 1000);
}

TEST(unitTests, isAlive){
    Monster dead = Monster("Dead",0,Damage(100,100),0,0);
    ASSERT_EQ(dead.isAlive(), false);
}

TEST(unitTests, setPosition_getPosition){
    Monster lost = Monster("Lost",1000,Damage(1000,1000),1000,1000);
    lost.setPosition(5,5);
    ASSERT_EQ(lost.getPosition().first, 5);
    ASSERT_EQ(lost.getPosition().second, 5);
}

TEST(unitTests, getName){
    Monster dead = Monster("Dead",0,Damage(100,100),0,0);
    ASSERT_EQ(dead.getName(), "Dead");
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

TEST(unitTests, fightTilDeath){
    Monster attacker = Monster("Attacker",10,Damage(10,10),10,10);
    Monster dead = Monster("Dead",1,Damage(100,100),1,1);
    attacker.fightTilDeath(dead);
    ASSERT_EQ(dead.isAlive(), false);
}

//Test for the Hero class
//ALL DONE
// It has 6 public functions
//Hero(takes a ton of things.), getMaxHealthPoints, getLevel, getLightRadius, 
//parse, deliverhit
TEST(unitTests, parseHero){
    ASSERT_NO_THROW(Hero::parse("../Dark_Wanderer.json"));
}

TEST(unitTests, levelUp){
    Hero hero = Hero("Hero",100,Damage(100,100),100,100,100,100,100,100,100,100,100,2);
    Monster enemy = Monster("Monster",100,Damage(100,100),1,1);
    hero.fightTilDeath(enemy);
    //This levelup test also test the constructor, the fighttildeath method etc
    ASSERT_EQ(hero.getLevel(),2);
    ASSERT_EQ(hero.getHealthPoints(),200);
    ASSERT_EQ(hero.getMaxHealthPoints(),200);
    ASSERT_EQ(hero.getAttackCoolDown(),200);
    ASSERT_EQ(hero.getPhysicalDamage(),200);
    ASSERT_EQ(hero.getMagicalDamage(),200);
    ASSERT_EQ(hero.getDefense(),200);
    ASSERT_EQ(hero.getLightRadius(),200);
}

//Test for the Damage class 
//ALL DONE
//It has 3 public functions, +, +=, *=
TEST(unitTests, DamageAddition)
{
    Damage damage1 = Damage(100,100);
    Damage damage2 = Damage(100,100);
    damage1 +   damage2;
    ASSERT_EQ(damage1.physical,200);
    ASSERT_EQ(damage1.magical,200);
}

TEST(unitTests, DamageAddEq)
{
    Damage damage1 = Damage(100,100);
    Damage damage2 = Damage(100,100);
    damage1 +=  damage2;
    ASSERT_EQ(damage1.physical,200);
    ASSERT_EQ(damage1.magical,200);
}

TEST(unitTests, DamageMultiplicationEq)
{
    Damage damage1 = Damage(100,100);
    Damage damage2 = Damage(100,100);
    damage1 *=  damage2;
    ASSERT_EQ(damage1.physical,10000);
    ASSERT_EQ(damage1.magical,10000);
}

//Test for the Game class 
//THESE NEED TO BE DONE
// It has 7 public functions, 
//Game(), ~Game(), Game(filepath), setMap(mappointer), 
//putHero(heropointer, row, column), putMonster(monster, row, column), run(istest)

/* TEST(unitTests, setMap) This test does some wonky things, not sure what the problem is
{
    Game game = Game();
    Map map = Map("../maps/map_for_gametest.txt");
    ASSERT_NO_THROW(game.setMap(&map));
} */

TEST(unitTests, PutHeroFree)
{
    Game game("../maps/map_for_test.txt");
    Hero hero = Hero::parse("../Dark_Wanderer.json");
    ASSERT_NO_THROW(game.putHero(&hero, 1, 1));
}

TEST(unitTests, PutHeroWall)
{
    Game game("../maps/map_for_test.txt");
    Hero hero = Hero::parse("../Dark_Wanderer.json");
    ASSERT_THROW(game.putHero(&hero, 0, 0), Game::OccupiedException);
}

TEST(unitTests, PutMonsterFree)
{
    Game game("../maps/map_for_test.txt");
    Monster monster = Monster::parse("../Fallen.json");
    ASSERT_NO_THROW(game.putMonster(monster, 1, 1));
}

TEST(unitTests, PutMonsterWall)
{
    Game game("../maps/map_for_test.txt");
    Monster monster = Monster::parse("../Fallen.json");
    ASSERT_THROW(game.putMonster(monster, 0, 0), Game::OccupiedException);
}

//Test for the Map class 
// It has 9 public functions,
//Map(), ~Map(), Map(filepath), get(y,x)
//THESE NEED TO BE DONE getHeroPosition(),
//getMonsterPositions(char), setHeroPosition(pair(first is row, second is column)), 
//drawMap(viewrange, hero row, hero column), setTile(row, column, type)
TEST(unitTests, MapEmptyConstructor)
{    
    ASSERT_NO_THROW(Map map());
}
TEST(unitTests, MapConstructor)
{    
    Map map("../maps/map_for_test.txt");
    ASSERT_EQ(map.get(0,0),1);
}
TEST(unitTests, Mapget)
{    
    Map map("../maps/map_for_test.txt");
    ASSERT_EQ(map.get(0,0),1);
    ASSERT_EQ(map.get(1,1),0);
}

//Test for the PreparedGame class 
// ALL DONE ASIDE FROM DESTRUCTOR
// It has 3 public functions, 
//THESE NEED TO BE DONE
//PreparedGame(), ~PreparedGame(), PreparedGame(filepath)
TEST(unitTests, PreparedGameEmptyConstructor)
{    
    ASSERT_NO_THROW(PreparedGame preparedgame());
}
TEST(unitTests, PreparedGameConstructor)
{    
    ASSERT_NO_THROW(PreparedGame preparedgame("preparedgame.json"));
}

//Test for the MarkedMap class 
// ALL DONE ASIDE FROM DESTRUCTOR
// It has 2 public functions, 
//THESE NEED TO BE DONE
//~MarkedMap(), MarkedMap(filepath)
TEST(unitTests, MarkedMapConstructor)
{    
    MarkedMap markedmap("../maps/map_1.txt");
    ASSERT_EQ(markedmap.get(0,0),1);
    ASSERT_EQ(markedmap.get(0,0),1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
