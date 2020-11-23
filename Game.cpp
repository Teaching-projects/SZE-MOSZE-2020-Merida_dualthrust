#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <exception> // Might include useless stuff as i copied this from another header, will delete later

#include "Hero.h"
#include "Map.h"
#include "Game.h"

/* 
Game::Game(); // Empty Game */
Game::Game(std::string mapfilename){} // Game with the Map initialized
void setMap(Map map){}; // Set the map
void putHero(Hero hero, int x, int y){}
void putMonster(Monster monster, int x, int y){}
void run(){}
    /* 
    Legyen egy

void Game::run();
fuggveny, mely levezenyli a jatekot, de dob egy Game::NotInitializedException-t, ha meg nincs beallitva terkep, vagy nincs Hero a palyan. 
Ha minden rendben van, elindit egy loop-ot egeszen addig, amig van meg Monster eletben. 
Ha mindegyik monster le lett gyakva, akkor egy "{hero.name} cleared the map. uzenetet kiir, es befejezi a futast.

A loop sikeres elinditasa utan Hero, Map allitas mar nem tortenhet, azok Game::GameAlreadyStartedException-t dobnak. 
Monstert viszont barmikor lehet feltenni, es egy lefutott run() utan akar ujra is lehet inditani.

A loop-ban north, south, east, west parancsokat var a stadard bemenetrol a program, amivel a Herot mozgatja, ha lehetseges (falra nem tud menni, palyarol nem lehet lemenni). 
Ha olyan mezore lep a hero, ahol monsterek vannak, akkor azokkal megcsatazik. (A monsterekkel abban a sorrendben, ahogy a jatekhoz hozza lettek adva.)

Miden loop elejen kiirodik a jatek olyan formaban, hogy a falak ██-vel, a szabad teruletek ░░-vel jelenjenek meg. 
Ahol a Hero all, ott ┣┫ legyen, ahol Monsterek, ott pedig MM, M░ attol fuggoen, hogy egy vagy tobb van ott. 
Az egesz palya korul U+255x karakterekkel (azok kozul a mindenhol duplavonalasakkal) legyen egy keret.

Ha a hosunk meghal, akkor egy The hero died. kimenettel veget er a loop, es ebben az esetben Addig nem lehet ujra elinditani, amig egy masik Herot fel nem pakolunk ra.
 */



/* Exceptions to implement for set and put methods.

Ha meg nincs terkep beallitva, akkor az elsot dobja a ket put. 
Falra nem kerulhet se Monster se Hero. 
Ugyanarra a szabad mezore azonban kerulhetnek egyszerre, akar tobb Monster is. 
A harmadikat akkor dobja, ha mar van beallitva hos, es egy masodikat tennenk fel. 
Az utolsot pedig akkor, ha terkepet allitanank at, de mar vannak a palyan egysegek. (Elotte akarhanyszor lecserelhetjuk.)

Map::WrongIndexException
Game::OccupiedException
Game::AlreadyHasHeroException
Game::AlreadyHasUnitsException */