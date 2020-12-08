# SZE-MOSZE-2020-Merida_dualthrust

## Bevezető
A 'Modern szoftverfejlesztési eszközök' órára készült projekt.
A kód c++ nyelven íródik, a projekt célja egy régi típusú parancssori
RPG-re hasonlító játék megírása OOP alapelvek követésével és természetesen
a modern szoftverfejlesztési eszközök használatával.

## A program működése
A projekt keretein belül készített program egy hős és szörnyek harcát játsza le. Harc közben hősünk felfedez egy dungeon-t ahol szörnyekkel harcol. A harc közben megszerzett tapasztalat alapján szintet is lép, amely során életereje, támadási, védekezési ereje, támadási ideje és látótávolsága változik. A játék addig tart, ameddig van szörny a pályán, vagy a hős meg nem hal.
A program indításához szükséges egy JSON fájl, ami tartalmazza a játék lefutásához szükséges adatokat
**Példa a fájl (preparedgame.json) tartalmára:**
{
  "map"  : "./maps/map_1.txt",
  "hero" : "./units/Dark_Wanderer.json",
  "monster-1" : "./units/Fallen.json",
  "monster-2" : "./units/Zombie.json",
  "monster-3" : "./units/Blood_Raven.json"
}
**Példa a játék indítására:**
```bash
./a.out preparedgame.json
```
### Helytelen input: 
A program a parancssorba printeli a helyes sémát, majd kilép.
### Helyes input: 
A hős elindul a pályán, és megpróbálja megölni az összes szörnyet. A pályának a hős csak egy adott részét látja, amire kiterjed a látótávolsága.
#### A hős mozgása az alábbi parancsokkal irányítható a játék során:
**north**; **south**; **west**; **east**

### Teli térkép ***(MarkedMap)***
Meg van adva a pálya alaprajza, azon pedig a hős és a szörnyek pozíciója
***Jelölések:***
    #             = Fal
    szóköz        = Szabad mező
    H             = Hős pozíciója
    számok (1-3)  = Különböző szörnyek pozíciója
***Példa térkép:***
```txt
##############
# H #   ###  #
# ####22##  #
# 12# 3##  #
###1# ##  #
#     1   #
###########
```

### Hős ***(Hero)***
A hős adatai egy JSON fájlban vannak tárolva
#### ***Példa:***
    ***A hős neve:***                                           name
    ***Kezdeti életereje:***                                    base_health_points
    ***Kezdeti fizikai támadó ereje:***                         base_damage
    ***Kezdeti mágikus támadó ereje:***                         base_magical-damage
    ***Kezdeti védekező ereje (fizikai támadással szemben):***  base_defense
    ***Kezdeti látótávja mezőkben:***                           light_radius
    ***Kezdeti támadósebessége (sec):***                        base_attack_cooldown
    ***Szükséges tapasztalati  egy szintlépéshez:***            experience_per_level
    ***Plusz életerő szintenként:***                            health_point_bonus_per_level
    ***Plusz fizikai támadóerő szintenként:***                  damage_bonus_per_level
    ***Plusz mágikus támadóerő szintenként:***                  magicaldamage_bonus_per_level
    ***Plusz védekező erő szintenként:***                       defense_bonus_per_level
    ***Támadósebesség szorzó szintenként:***                    cooldown_multiplier_per_level
```json
    {
        "name" : "Prince Aidan",
        "base_health_points" : 30,
        "base_damage" : 3,
        "base_magical-damage" : 2,
        "base_defense" : 1,
        "light_radius" : 2,
        "base_attack_cooldown" : 1.1,
        "experience_per_level" : 20,
        "health_point_bonus_per_level" : 5,
        "damage_bonus_per_level" : 1,
        "magicaldamage_bonus_per_level" : 1,
        "defense_bonus_per_level" : 1,
        "cooldown_multiplier_per_level": 0.9
    }
```
### Szörny ***(Monster)***
A szörny adatai szintén egy JSON fájlban vannak tárolva ***(4 különböző szörny létezik)***
#### ***Példa:***
    ***A szörny háttértörténete:***  lore
    ***Neve:***                      name
    ***Életereje:***                 health_points
    ***Védekező ereje:***            defense
    ***Fizikai támadóereje:***       damage
    ***Mágikus támadóereje:***       magical-damage
    ***Támadási sebessége (sec):***  attack_cooldown
    ***Faja:***                      race
```json
    {
        "lore" : "The lowest rank of the undead, zombies befoul much of the wilderness of the Western Kingdoms, as well as the tombs and crypts of the whole of Sanctuary. Zombies serve the darkness blindly and without thought, attacking only with their bare hands. They move slowly, but with relentless determination, seeking to consume the flesh of the living. They are simple-minded and easily outwitted, but in large groups can overwhelm the unwary.",


        "name" : "Zombie",
        "health_points" : 10, 
        "defense" : 2, 
        "damage" : 1, "attack_cooldown" : 2.8,
        "magical-damage" : 1,
        "race" : "undead"
    }
```
### Megjelenítés
## Tesztek
### In-output teszt
Helyes input esetben egy szkript leteszteli, hogy a kapott kimenet a valós értékeket közli-e.
A program parancssorba printeli, hogy a kimenet helyes, vagy sem.
### Unit tesztek
A program egyes komponenseit tesztelik, googletest segítségével futtatjuk őket.
### Memória hibák ellenőrzése
Valgrind segítségével derítjük fel a memory leak-eket és az egyéb memória hibákat.
Az alábbi beállításokkal használjuk a Valgrindot:
```bash
valgrind -s --leak-check=full --track-origins=yes
```
## Csapattagok
Lapat Krisztián\
Lilik Ferenc\
Nemes Tamás

A dokumentáció Doxygen segítségével készült,
Az alábbi linken elérhető:
https://teaching-projects.github.io/SZE-MOSZE-2020-Merida_dualthrust/index.html