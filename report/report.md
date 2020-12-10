# Tagok

| Név | Github azonosito  | Javasolt relatív érdemjegy | Becsült óra | Indoklás  | 
| --- | ---- | --- | ------------------ | --------- |
| Lilik Ferenc | @lilikf | +2 | 70-80 óra | A csapat húzóereje volt, feladatait, amik a projekt legnagyobb kihívást jelentő feladatai voltak, gyorsan, pontosan, igényesen végezte, valamint azonnal segítséget nyújtott a csapattársaknak probléma esetén. A projekt elkészítéséhez szükséges eszközöket ismeri, alkalmazni tudja, a feladat megoldásokat átlátja. A feladatok megoldásánál nem csak a funkcionalitás, de az esztétika és az optimalizálás is szempontok voltak. |
| Lapat Krisztián | @lapatkrisz | 0 | 30-40 | Részt vett a legtöbb feladat megoldásában, a rá bízott feladatokat sikerült többnyire önállóan megoldania határidőre. A többi feladat megoldását is figyelemmel kísérte, a megoldásokat és az alkalmazott eszközöket megismerte és használni is tudja. |
| Nemes Tamás | @nemestom | +2 | 200+ óra | Döntő szerepe volt a feladatok elosztásában a csapattársak között, és azok megoldásában is. Feladatait gyorsan, precízen végezte, a rá bízott feladatokon kívül sokat segített a többiek munkájában is. A feladatokhoz szükséges elméletet mindig értette, és sikerrel alkalmazta a gyakorlati megoldásoknál. |


# Videók

 - [Gameplay](/videos/gameplay.mp4)
 - [CodeBaseDefense](/videos/codebasedefense.mp4)

# Befejezett feladatok

| Feladat | Merge ideje a határidóhöz (nap) | Change request körök | Reviewer | 
| ------- | ------------------------------- | -------------------- | -------- |
| Feladat 1 | -2 | 0 | @oliverosz | 
| Feladat 2 | +2 | 2 | @wajzy |
| jsonparser | +15 | 1 | @wajzy |
| levelup | -1 | 1 | @oliverosz |
| attackspeed | +4 | 1 | @vizvezetek |
| attackspeedFIX | +9 | 0 | @oliverosz |
| documentation | -1 | 1 | @lilikf, @pottyok / @balintxd, @mushukcha |
| unittesztek | -1 | 0 | @nemestom, @pottyok / @tamasori, @balintxd |
| makefile | -2 | 1 | @hegyhati |
| refactor | -3 | 1 | @hegyhati |
| docker | -3 | 0 | @hegyhati |
| jsonpimp | Merge: 11.29 | 0 | @nemestom
| map | Merge: 11.23 | 0 | @lapatkrisz, @pottyok / @balintxd, @mushukcha |
| game | Merge: 11.30 | 0 | @lilikf |
| defense | Merge: 11.22 | 0 | @lapatkrisz |
| damage | Merge: 12.07 | 0 | @nemestom  |
| markedmap(parsed game) | Merge: 12.08 | 0 | @nemestom |
| preparedgame | nem készült el | - | -
| light radius | Merge: 12.04 | 0 | @lilikf |
| rendering | Merge: 12.08 | 0 | @nemestom |

# Unit tesztek

| Osztály | Publikus metódusok száma | Unit tesztelt metódusok száma | Unit tesztek száma |
| --- | --- | --- | --- |
| `Monster` | 16 | 16 | 12 | 
| `Hero` | 6 | 6 | 1 |
| `Damage` | 3 | 3 | 3 |
| `Map` | 9 | 3 | 3 |
| `MarkedMap` | 2 | 1 | 1 |
| `Game` | 7 | 2 | 4 |
| `PreparedGame` | 3 | 2 | 1 |  
| `JSON` | 8 | 0 | 0 |
| `Renderer` | 2 | 0 | 0 |
| `TextRenderer` | 3 | 0 | 0 |
| `SVGRenderer` | 4 | 0 | 0 |
| `HeroTextRenderer` | 1 | 0| 0 |
| `HeroSVGRenderer` | 1 | 0 | 0 |
| `ObserverTextRenderer` | 1 | 0 | 0 |
| `ObserverSVGRenderer` | 1 | 0 | 0 |

# Kód dokumentáció

| Teljesen dokumentált osztályok | Részben dokumentált osztályok | Nem dokumentált osztályok |
| --- | ... | ... | 
| `Monster` | ... | ... | 
| `Hero` | ... | ... |  
| `Map` | ... | ... |  
| `MarkedMap` | ... | ... |  
| `Game` | ... | ... |  
| `PreparedGame` | ... | ... |  
| `JSON` | ... | ... |  
| ... |


# Mindenféle számok

 - Összes cpp kódsor : 1185 (kommentek és whitespace-k nélkül)
 - Egyéb kódsor (make,doxyfile,shellscript, ...) :
    - make: 48
    - doxyfile: 15
    - shellscript: 17
    - yml: 64
    - docker: 25
 - cppcheck
   - warning : 0
   - style : 0
   - performance : 0
   - unusedFunction : 0 
   - missingInclude : 0

# Implicit megtanult dolgok
Olyanok, amik nem a tárgy anyaga, de muszáj/hasznos volt elsajátítani:
 - Lilik Ferenc:
 - 
 - Lapat Krisztián: Linux shell használata, sok szenvedéstől kímélt meg pl. a dockeres feladatnál.
 - 
 - Nemes Tamás:
 - Sok cpp funkció, adatstruktúra új volt, rá voltam kényszerülve a használatukra. OOP aktuális a félévben, segített ez a tárgy a megértésében.
 - JSON struktúra
 - bash scriptelés nagyon alapjai
 - ...

# Feedback (optional)

Melyik részt találtátok a leghasznosabbnak, miért. Használtátok-e az itt megszerzett dolgokat esetleg közben máskor. Volt-e olyan, amit hiányoltatok a tárgyból. Utólag visszagondolva is jó volt-e az online videósdi?

Lapat Krisztián: GitHub-ot most kellett először komolyabban használnom, a jövőben is jót fog tenni ez az ismeretség, a videós megoldásnak pedig kifejezetten örültem (visszanézhetőség, rugalmasság).

Nemes Tamás: Nekem tetszett az online videós megoldás, a videó + konzultáció bőven jó szerintem, vissza is lehet nézni, nektek is több időtök marad. Pont aktuális probléma volt a félév során containerek készítése egy, más-más verziójú tensorflow keras stb-t kellett összeválogatni különböző programokhoz. 
A félév során használt vscode + wsl linux + gcc kombinációval lényegesen könnyebb dolgozni mint egy vs szerű ide-vel, ezt is a tárgynak köszönhetem.

# Üzenet a jövőbe (optional)

Így, hogy túlvagytok rajta, mi az, aminek örültetek volna, ha első héten elmondom, avagy: jövőre mit lenne jó, ha elmondanék majd?

Lilik Ferenc:

Lapat Krisztián:

Nemes Tamás: Időmenedzsmentre figyelmeztetni a hallgatókat, ha mondjuk nehezebb feladatok érkeznek, vagy "dömping" van feladatokból, azokat arányosan elosztani. 
