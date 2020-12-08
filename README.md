# SZE-MOSZE-2020-Merida_dualthrust

## Bevezető
A 'Modern szoftverfejlesztési eszközök' órára készült projekt.
A kód c++ nyelven íródik, a projekt célja egy régi típusú parancssori
RPG-re hasonlító játék megírása OOP alapelvek követésével és természetesen
a modern szoftverfejlesztési eszközök használatával.

## A program működése
A projekt keretein belül készített program egy hős és szörnyek harcát játsza le. Harc közben hősünk felfedez egy dungeon-t ahol szörnyekkel harcol. A harc közben megszerzett tapasztalat alapján szintet is lép, amely során életereje, támadási, védekezési ereje, támadási ideje és látótávolsága változik. A játék addig tart, ameddig van szörny a pályán, vagy a hős meg nem hal. A MarkedMap osztály segítségével be tudunk olvasni egy előre elkészített pályát txt-ből, ahol adott a hős és a szörnyek elhelyezkedése.

### Helytelen input: 
A program a parancssorba printeli a helyes sémát, majd kilép.
### Helyes input: 
A hős elindul a pályán, és megpróbálja megölni az összes szörnyet. A pályának a hős csak egy adott részét látja, amire kiterjed a látótávolsága.
#### A hős mozgása az alábbi parancsokkal irányítható a játék során:
**north**; **south**; **west**; **east**

## Tesztek
Helyes unput esetben egy szkript leteszteli, hogy a kapott kimenet a valós értékeket közli-e.
A program parancssorba printeli, hogy a kimenet helyes, vagy sem.
További tesztek is léteznek a programhoz: memóriaszemetelés ellenőrzése; kódteszt googletest segítségével.

## Csapattagok
Lapat Krisztián\
Lilik Ferenc\
Nemes Tamás

Github pages dokumentáció: https://teaching-projects.github.io/SZE-MOSZE-2020-Merida_dualthrust/index.html