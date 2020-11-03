# SZE-MOSZE-2020-Merida_dualthrust

## Bevezető
A 'Modern szoftverfejlesztési eszközök' órára készült projekt.
A kód c++ nyelven íródik, a projekt célja egy régi típusú parancssori
RPG-re hasonlító játék megírása OOP alapelvek követésével és természetesen
a modern szoftverfejlesztési eszközök használatával.

## A program működése
A projekt keretein belül készített program egy hős és szörnyek harcát játsza le. Harc közben a felek a megszerzett tapasztalat alapján szintet is lépnek, amely során életerejük, támadásuk ereje és támadási idejük változik.
Futásához bemeneti paramétereket vár, a következő séma alapján:

**KarakterNev(string) KarakterHP(int) KarakterATK(int) KarakterACD(double) KarakterXPperSzint(int) KarakterHPperSzint(int) KarakterDMGperSzint(int) KarakterACDperSzint(float) EllensegNev(string) EllensegHP(int) EllensegATK(int) EllensegACD EllensegSzint(1) EllensegMaxHP EllensegTapasztalat(0) EllensegXPperSzint EllensegHPperSzint EllensegDMGPerSzint EllensegACDperSzint**

Helytelen input esetén a program a parancssorba printeli a helyes sémát, majd kilép.
Helyes input esetén a hős és a szörnyek 'oda-vissza' módon támadják egymást, amíg egyikőjük életereje el nem fogy.
Ez utóbbi esetben egy szkript leteszteli, hogy a kapott kimenet a valós értékeket közli-e.
A program parancssorba printeli, hogy a kimenet helyes, vagy sem.

## Csapattagok
Lapat Krisztián\
Lilik Ferenc\
Nemes Tamás

Github pages dokumentáció: https://teaching-projects.github.io/SZE-MOSZE-2020-Merida_dualthrust/index.html