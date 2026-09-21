# Elevoppgaver – Klokkeprosjekt 2026

Dere skal sammen bygge ferdig en smart skole-timeplan-klokke med en NeoPixel LED-ring. Koden i `sketch/sketch.ino` inneholder alle funksjonene dere trenger, men de fleste er tomme skjeletter merket med `// Laget av:` og `// TODO:`. Hver elev/gruppe velger én eller flere funksjoner og implementerer dem.

## Spilleregler

1. Velg en funksjon fra listen under som ingen andre i klassen har tatt.
2. Skriv navnet ditt i `// Laget av: <Fornavn>` inne i funksjonen.
3. Fyll ut dokumentasjonen for funksjonen din i din egen fil under [dokumentasjon/funksjoner/](dokumentasjon/funksjoner/) — ikke i sketch.ino, se hvorfor under.
4. Ikke endre funksjonens navn, parametere eller returtype — resten av koden er avhengig av at signaturen er uendret.
5. **Test funksjonen din før du leverer!** Du kan teste den via Serial-monitoren, eller legge til en midlertidig testlinje nederst i `setup()` for å se at den virker (husk å fjerne testlinjen før du committer):
   - For `sjekkHelg`: `Serial.println(sjekkHelg(LORDAG) ? "OK: Helg!" : "Feil");`
   - For `fagNavn`: `Serial.println("Test fagNavn: " + fagNavn(MATTE));`
   - For `fagFarge`: `strip.fill(fagFarge(MATTE)); strip.show();`
   - For animasjoner/visere: kall funksjonen din direkte nederst i `setup()` og se resultatet på ringen!

---

## Dokumentasjonsstandard

`sketch/sketch.ino` er en C++-fil og egner seg dårlig til lange forklaringer — derfor skrives dokumentasjonen i en egen fil per funksjon, i mappa [dokumentasjon/funksjoner/](dokumentasjon/funksjoner/), i stedet for som kommentarblokker i koden. Inne i selve funksjonen holder det med den korte `// Laget av: <Fornavn>`-kommentaren.

Se [dokumentasjon/README.md](dokumentasjon/README.md) for malen du skal fylle ut (og et utfylt eksempel for `fagFarge`) — finn fila for din funksjon i [dokumentasjon/funksjoner/](dokumentasjon/funksjoner/) (samme navn som funksjonen), og fyll inn der.

Poenget med dokumentasjonen er todelt: den skal gjøre det lett for andre (og deg selv) å forstå hva funksjonen gjør uten å lese hele koden, **og** den skal tvinge deg til å reflektere over løsningen din i stedet for bare å skrive kode og gå videre.

Bruk malen i [dokumentasjon/README.md](dokumentasjon/README.md) på **alle** funksjonene dere implementerer.

---

## Funksjonsoversikt / Booking

Skriv navnet ditt (eller gruppa) i `Hvem`-kolonnen når du tar en oppgave, og oppdater `Status` etter hvert som du jobber. Gyldige statuser: **Ledig** (default, ikke tatt) → **⚠️ Påbegynt** → **✅ Ferdig**. `Dokumentasjon`-kolonnen lenker til fila i [dokumentasjon/funksjoner/](dokumentasjon/funksjoner/) der du skal fylle ut malen for funksjonen din.

| Vanskelighetsgrad | Funksjon | Hvem | Status | Dokumentasjon |
|---|---|---|---|---|
| Enkel | `sjekkHelg` | | Ledig | [sjekkHelg.md](dokumentasjon/funksjoner/sjekkHelg.md) |
| Enkel | `fagFarge` | Erik | ✅ Ferdig | [fagFarge.md](dokumentasjon/funksjoner/fagFarge.md) |
| Enkel | `fagNavn` | | Ledig | [fagNavn.md](dokumentasjon/funksjoner/fagNavn.md) |
| Enkel | `blinkLED` | Bjørn | ⚠️ Påbegynt | [blinkLED.md](dokumentasjon/funksjoner/blinkLED.md) |
| Enkel | `timeStartAnimasjon` | | Ledig | [timeStartAnimasjon.md](dokumentasjon/funksjoner/timeStartAnimasjon.md) |
| Enkel | `friminuttAnimasjon` | Vilde | ✅ Ferdig | [friminuttAnimasjon.md](dokumentasjon/funksjoner/friminuttAnimasjon.md) |
| Enkel | `visMeny` | | Ledig | [visMeny.md](dokumentasjon/funksjoner/visMeny.md) |
| Enkel | `sjekkSerialMeny` | Endre | ✅ Ferdig | [sjekkSerialMeny.md](dokumentasjon/funksjoner/sjekkSerialMeny.md) |
| Middels | `visKlokkevisere` | Alexander og Johan | ⚠️ Påbegynt | [visKlokkevisere.md](dokumentasjon/funksjoner/visKlokkevisere.md) |
| Middels | `nedtellingBar` | Alexander og Johan | ⚠️ Påbegynt | [nedtellingBar.md](dokumentasjon/funksjoner/nedtellingBar.md) |
| Middels | `melodiSpiller` | Viggo | ⚠️ Påbegynt | [melodiSpiller.md](dokumentasjon/funksjoner/melodiSpiller.md) |
| Middels | `spillMelodi` | | Ledig | [spillMelodi.md](dokumentasjon/funksjoner/spillMelodi.md) |
| Middels | `visGjeldendeStatus` | | Ledig | [visGjeldendeStatus.md](dokumentasjon/funksjoner/visGjeldendeStatus.md) |
| Middels | `ferdigForDagenAnimasjon` | Tobias og Vrishab | ⚠️ Påbegynt | [ferdigForDagenAnimasjon.md](dokumentasjon/funksjoner/ferdigForDagenAnimasjon.md) |
| Middels | `helgeSluttAnimasjon` | Joachim | ⚠️ Påbegynt | [helgeSluttAnimasjon.md](dokumentasjon/funksjoner/helgeSluttAnimasjon.md) |
| Middels | `handterHelg` | | Ledig | [handterHelg.md](dokumentasjon/funksjoner/handterHelg.md) |
| Avansert | `fyllPlan` | Nicholas & Marcel | ✅ Ferdig | [fyllPlan.md](dokumentasjon/funksjoner/fyllPlan.md) |
| Avansert | `beregnTidIgjen` | Luka & Marcel | ✅ Ferdig | [beregnTidIgjen.md](dokumentasjon/funksjoner/beregnTidIgjen.md) |
| Avansert | `hentGjeldendeFag` | Marcel | ✅ Ferdig | [hentGjeldendeFag.md](dokumentasjon/funksjoner/hentGjeldendeFag.md) |
| Avansert | `hentInternetTid` | Marcel & Luka | ✅ Ferdig | [hentInternetTid.md](dokumentasjon/funksjoner/hentInternetTid.md) |
| Avansert | `helgAnimasjon` | Franklin | ⚠️ Påbegynt | [helgAnimasjon.md](dokumentasjon/funksjoner/helgAnimasjon.md) |
| Avansert | `planIndex` | | Ledig | [planIndex.md](dokumentasjon/funksjoner/planIndex.md) |
| Avansert | `handterAktivitetsbytte` | | Ledig | [handterAktivitetsbytte.md](dokumentasjon/funksjoner/handterAktivitetsbytte.md) |
| Ekstra (valgfritt) | `startNedtelling` | | Ledig | [startNedtelling.md](dokumentasjon/funksjoner/startNedtelling.md) |
| Ekstra (valgfritt) | `spillAnimasjon` | | Ledig | [spillAnimasjon.md](dokumentasjon/funksjoner/spillAnimasjon.md) |
| Ekstra (valgfritt) | `startStoppeklokke` | | Ledig | [startStoppeklokke.md](dokumentasjon/funksjoner/startStoppeklokke.md) |
| Ekstra (valgfritt) | `knappTrykket` (krever kabling) | | Ledig | [knappTrykket.md](dokumentasjon/funksjoner/knappTrykket.md) |
| Ekstra (valgfritt) | `spillRTTTL` | | Ledig | [spillRTTTL.md](dokumentasjon/funksjoner/spillRTTTL.md) |
| Ekstra stort (samarbeid) | Web-grensesnitt (`settOppWebserver`, `handterWebKlient`, `genererMenyHTML`) | | Ledig | [web-grensesnitt.md](dokumentasjon/funksjoner/web-grensesnitt.md) |
| Hardware (samarbeid, ikke koding) | Kabling og lodding | | Ledig |
| Hardware (samarbeid, ikke koding) | 3D-printet ramme/kabinett | Leo | ⚠️ Påbegynt |

---

## Enkle funksjoner

### `bool sjekkHelg(int ukedag)`
Avgjør om en gitt ukedag er en helgedag.
- **Parameter:** `ukedag` (int) – tallverdi for ukedagen, se `enum Ukedag` (SONDAG=0 ... LORDAG=6).
- **Returverdi:** `bool` – `true` hvis det er lørdag eller søndag, ellers `false`.
- **Hint:** Sammenlign `ukedag` med enum-verdiene `SONDAG` og `LORDAG` i stedet for tallene 0/6 direkte — det gjør koden lettere å lese.

### `uint32_t fagFarge(Fag fag)`
Se det utfylte eksempelet over. Returnerer LED-fargen som hører til et gitt fag.
- **Parameter:** `fag` (Fag) – hvilket fag (se `enum Fag`).
- **Returverdi:** `uint32_t` – fargeverdi laget med `strip.Color(r, g, b)`.
- **Hint:** Bruk `switch`/`case` med én farge per fag, og husk et `default`-case.

### `String fagNavn(Fag fag)`
Gjør om et fag fra `enum Fag` til en lesbar tekst som skrives ut på Serial-monitoren.
- **Parameter:** `fag` (Fag) – hvilket fag det gjelder (f.eks. `MATTE`, `ENOGSTYR`, `FRIMINUTT`).
- **Returverdi:** `String` – navnet på faget som tekst (f.eks. `"Matematikk"`, `"Energi og styresystemer"`, `"Friminutt"`).
- **Hint:** Bruk `switch`/`case` på samme måte som i `fagFarge()`, men returner tekst i stedet for farge. Husk `default: return "Fri / Ukjent";`.

### `void blinkLED(uint32_t farge, int antallBlink)`
Blinker hele LED-ringen i en gitt farge et antall ganger.
- **Parametere:** `farge` (uint32_t) – fargen som skal blinkes, `antallBlink` (int) – hvor mange ganger den skal blinke.
- **Returverdi:** Ingen (void).
- **Hint:** `strip.fill(farge)` + `strip.show()` for å slå på, `strip.clear()` + `strip.show()` for å slå av, med en `delay()` mellom hver.

### `void timeStartAnimasjon(uint32_t fagfarge)`
Viser en kort animasjon når en ny time starter.
- **Parameter:** `fagfarge` (uint32_t) – fargen til faget som nettopp startet.
- **Returverdi:** Ingen (void).
- **Hint:** Prøv f.eks. å la fargen "vokse" ut fra ett punkt på ringen, eller fylle ringen gradvis.

### `void friminuttAnimasjon(int minutt, int index)`
Viser en animasjon i friminuttet som gjerne bør vise hvor mye tid som er igjen.
- **Parametere:** `minutt` (int) – gjeldende minutt, `index` (int) – raden i `plan[]` for friminuttet (kan være `-1` hvis det ikke er friminutt).
- **Returverdi:** Ingen (void).
- **Hint:** `plan[index].startMinutt` og `plan[index].varighet` forteller når friminuttet startet/slutter. Husk å håndtere `index == -1`.

### `void visMeny()`
Viser en meny på Serial-monitoren der man kan velge å teste de andre funksjonene.
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** `Serial.println()` for menyvalg, `Serial.readStringUntil('\n')` + `input.toInt()` for å lese hva brukeren velger, og `switch`/`case` for å kalle riktig funksjon. Du kan også bruke den ferdige hjelpefunksjonen `settDummyTid(ukedag, time, minutt, sekund)` i et menyvalg for å simulere ulike dager og tider (f.eks. onsdag 09:30, fredag 13:59 eller lørdag).

### `void sjekkSerialMeny()`
Sjekker om brukeren har skrevet noe på Serial-monitoren, og åpner menyen hvis teksten er `"meny"`.
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** `Serial.available()` forteller om det finnes tekst å lese. Husk `input.trim()` for å fjerne mellomrom/linjeskift før du sammenligner strengen.

---

## Middels funksjoner

### `void visKlokkevisere(int time, int minutt, int sec)`
Tegner time-, minutt- og sekundviser på LED-ringen, som en vanlig klokke.
- **Parametere:** `time` (0-23), `minutt` (0-59), `sec` (0-59).
- **Returverdi:** Ingen (void).
- **Viktig:** `strip.clear()` og `strip.show()` håndteres automatisk i `loop()` rett før og etter denne funksjonen. Du skal **ikke** kalle `strip.clear()` eller `strip.show()` inne i funksjonen din!
- **Hint:** En hel runde rundt ringen (`NUM_LEDS` piksler) tilsvarer 12 timer for timeviseren, og 60 minutter/sekunder for de andre viserne. I koden ligger hjelpefunksjonene `time_viser()`, `minutt_viser()` og `sekund_viser()` ferdig laget rett over funksjonen – du kan kalle disse direkte for å finne pikselposisjonen til hver viser, og så sette farger med `strip.setPixelColor(pos, farge)`.

### `void nedtellingBar(int index, int sekunderIgjen, uint32_t fagfarge)`
Tegner en "bue" av LED-er som viser hvor mye tid som er igjen av den aktiviteten som pågår nå.
- **Parametere:** `index` (int) – raden i `plan[]`, `sekunderIgjen` (int) – sekunder igjen, `fagfarge` (uint32_t) – fargen buen skal ha.
- **Returverdi:** Ingen (void).
- **Viktig:** `strip.clear()` og `strip.show()` håndteres automatisk i `loop()`. Du skal **ikke** kalle `strip.clear()` eller `strip.show()` inne i funksjonen din!
- **Hint:** Bruk `plan[index].varighet * 60` til å finne total varighet i sekunder, og `map()` for å regne om `sekunderIgjen` til LED-posisjon (0 til `NUM_LEDS`). Husk å håndtere `index == -1`.

### `void melodiSpiller(int note[], int varighet[], int antallToner)`
Spiller av en liste med toner (frekvenser) og tilhørende varigheter på buzzeren.
- **Parametere:** `note[]` – frekvenser i Hz, `varighet[]` – varighet per tone i ms, `antallToner` (int) – hvor mange toner arrayene inneholder.
- **Returverdi:** Ingen (void).
- **Hint:** Bruk `tone(soundpin, note[i], varighet[i])` i en for-løkke fra `0` til `antallToner - 1`. **Ikke** bruk `sizeof(note)` — arrays som sendes til funksjoner "råtner" til pekere, så det gir feil svar. Det er derfor `antallToner` sendes med som egen parameter.

### `void spillMelodi(int melodiNr)`
Spiller riktig melodi/varsel basert på et melodi-nummer (1 = friminutt, 2 = time-start, osv.).
- **Parameter:** `melodiNr` (int) – melodinummer (f.eks. 1 = friminutt, 2 = time-start).
- **Returverdi:** Ingen (void).
- **Hint:** Har dere buzzer? Bruk `tone(soundpin, frekvens, varighet)` eller spill av eksempel-tonene med `melodiSpiller(melodi, melodi_varighet, 3)`. Ingen buzzer? Bruk LED-blink i stedet, f.eks. `blinkLED(strip.Color(0,255,0), 3)`.

### `void visGjeldendeStatus(int index, int minutt)`
Sjekker statusflaggene og starter riktig animasjon dersom det har skjedd en hendelse (skoledag over, friminutt eller ny time).
- **Parametere:** `index` (int) – raden i `plan[]` for aktiviteten, `minutt` (int) – gjeldende minutt.
- **Returverdi:** Ingen (void).
- **Hint:** Sjekk de globale statusflaggene i rekkefølge med `if` / `else if`:
  - Hvis `ferdigForDagen`: vis `ferdigForDagenAnimasjon()` og nullstill flagget (`ferdigForDagen = false;`).
  - Hvis `nyttFriminutt`: vis `friminuttAnimasjon(minutt, index)` og nullstill flagget (`nyttFriminutt = false;`).
  - Hvis `nyTime`: vis `timeStartAnimasjon(fagFarge(gjeldendeFag))` og nullstill flagget (`nyTime = false;`).

### `void ferdigForDagenAnimasjon()`
Viser en rolig animasjon som markerer at skoledagen er over.
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** En myk fade inn/ut med `strip.fill()` + `strip.show()` er en god start.

### `void helgeSluttAnimasjon()`
Viser en spektakulær feiringsanimasjon etter siste time på fredag (maks 30 sekunder).
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** Vær kreativ! Kombiner flere effekter (fyrverkeri, regnbue, puls, rotasjon). `sin()`/`cos()` er nyttige for myke overganger. Ikke bruk for lange `delay()`-kall om gangen.

### `void handterHelg(int ukedag)`
Sjekker om det er helg akkurat nå, og håndterer statusflagget og animasjonen for det.
- **Parameter:** `ukedag` (int).
- **Returverdi:** Ingen (void).
- **Hint:** Bruk `sjekkHelg(ukedag)`, oppdater den globale variabelen `erHelg`, og kall `helgAnimasjon()` når det er helg. Vurder å bare skrive en Serial-melding *første* gang det blir helg, ikke hver eneste loop.

---

## Avanserte funksjoner

### `void fyllPlan()`
Fyller `plan[]`-arrayet med hele ukens timeplan.
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** Bruk egne indeks-serier per dag (f.eks. mandag = 0-9, tirsdag = 10-19). Det er lov å ha "hull" i listen. Husk å oppdatere `antallTimer` når planen er fullført.

### `int beregnTidIgjen(int index, int time, int minutt, int sekund)`
Regner ut hvor mange sekunder som er igjen av aktiviteten i `plan[index]`.
- **Parametere:** `index` (int) – raden i `plan[]`, `time` (0-23), `minutt` (0-59), `sekund` (0-59) – klokkeslettet akkurat nå.
- **Returverdi:** `int` – antall sekunder igjen (0 hvis `index == -1`).
- **Hint:** Gjør om både "nå" og "når aktiviteten slutter" til sekunder fra midnatt, og ta differansen (`sluttSek - naSek`). `plan[index].startTime`, `.startMinutt` og `.varighet` gir deg sluttidspunktet.

### `Fag hentGjeldendeFag(int index)`
Slår opp hvilket fag som pågår, ut fra en indeks i `plan[]`.
- **Parameter:** `index` (int).
- **Returverdi:** `Fag` – faget i `plan[index]`, eller `INGENTING` hvis `index == -1`.
- **Hint:** Dette er en enkel oppslagsfunksjon — pass på grensetilfellet med `index == -1`.

### `bool hentInternetTid()` *(Ferdig implementert – Marcel & Luka)*
Kobler til WiFi og henter riktig klokkeslett fra internett (NTP).

> ℹ️ **Denne funksjonen er allerede ferdig implementert og dokumentert av Marcel & Luka som et referanseeksempel.** Se koden i `sketch/sketch.ino` og dokumentasjonen i [dokumentasjon/funksjoner/hentInternetTid.md](dokumentasjon/funksjoner/hentInternetTid.md).
- **Parametere:** Ingen.
- **Returverdi:** `bool` – `true` hvis tiden ble hentet, `false` ved feil.
- **Hint:** WiFi bruker 2-5 sekunder på å koble til, så du må vente i en `while (WiFi.status() != WL_CONNECTED)`-løkke med timeout (f.eks. maks 20 forsøk med `delay(500)`). For norsk tidssone (GMT+1 og 1 time sommertid), bruk `configTime(3600, 3600, "pool.ntp.org")` eller `configTzTime()`. Sjekk deretter om tiden er gyldig med `getLocalTime(&timeinfo)`.

### `void helgAnimasjon()`
Viser en kul animasjon som spilles gjentatte ganger i helgene.
- **Parametere:** Ingen.
- **Returverdi:** Ingen (void).
- **Hint:** Regnbue-effekter, "bouncing balls", stjernehimmel eller roterende mønstre er gode utgangspunkt. Denne kalles hver loop, så unngå lange `delay()`-kall.

### `int planIndex(int ukedag, int time, int minutt)`
Finner hvilken rad i `plan[]` som matcher gjeldende ukedag/klokkeslett.
- **Parametere:** `ukedag` (int), `time` (0-23), `minutt` (0-59).
- **Returverdi:** `int` – indeksen (0-49) til riktig rad, eller `-1` hvis ingen aktivitet pågår nå.
- **Hint:** Gjør om nåværende tid til minutter fra midnatt: `int naMin = time * 60 + minutt`. Gå gjennom `plan[]` med en for-løkke fra `0` til `antallTimer - 1`. For hver rad der `plan[i].dag == ukedag` og `plan[i].fag != INGENTING`: regn ut `startMin = startTime * 60 + startMinutt` og `sluttMin = startMin + varighet`. Hvis `naMin` er mellom `startMin` og `sluttMin`, returner indeksen `i`.

### `void handterAktivitetsbytte(Fag nyttFag, int ukedag)`
Oppdager om faget/aktiviteten har endret seg siden forrige gang, og setter riktige statusflagg.
- **Parametere:** `nyttFag` (Fag) – faget som gjelder nå, `ukedag` (int).
- **Returverdi:** Ingen (void).
- **Hint:** Sammenlign `nyttFag` med den globale `forrigeFag`.
  - Hvis `nyttFag == INGENTING` og `forrigeFag != INGENTING`, er skoledagen over! Hvis det er fredag (`ukedag == FREDAG`), kall `helgeSluttAnimasjon()`, ellers sett `ferdigForDagen = true`.
  - Hvis `nyttFag == FRIMINUTT`, sett `nyttFriminutt = true` og kall `spillMelodi(1)`.
  - Hvis `nyttFag != INGENTING` og `nyttFag != FRIMINUTT`, sett `nyTime = true` og kall `spillMelodi(2)`.
  - Husk å oppdatere `forrigeFag = nyttFag` til slutt!

---

## Ekstra / valgfrie funksjoner

Disse funksjonene er ikke en del av kjernefunksjonaliteten, men er valgfrie tillegg dere kan ta hvis dere har lyst til å utvide klokken. De ligger allerede som tomme skjeletter i `sketch/sketch.ino`.

### `void startNedtelling(uint32_t farge, int minutt, int sekund)`
En nedtellingstimer (som en kjøkkentimer) som tar over hele ringen. Ringen starter full og tømmes gradvis etter hvert som tiden går.
- **Parametere:** `farge` (uint32_t) – fargen ringen skal telle ned i, `minutt`/`sekund` (int) – hvor lang tid som skal telles ned.
- **Returverdi:** Ingen (void).
- **Viktig:** Dette er en **blokkerende** funksjon (den tar pause i resten av klokkelogikken mens den kjører) — akkurat som en fysisk kjøkkentimer. Den skal kunne **avbrytes** ved at brukeren skriver `stopp` i Serial Monitor mens den teller ned.
- **Hint:** Bruk en løkke med `delay(1000)` som teller ned sekund for sekund, og regn ut hvor mange LEDs som skal være tent basert på hvor stor andel av tiden som er igjen. Sjekk `Serial.available()` hver runde for å oppdage `stopp`. Spill gjerne av en enkel animasjon (f.eks. `blinkLED`) helt til slutt hvis den fikk telle helt ferdig.

### `void spillAnimasjon(uint32_t farge, int sekunder)`
En fri, selvvalgt animasjonsfunksjon — akkurat som `helgAnimasjon()`, men med farge og varighet som parametere i stedet for faste verdier.
- **Parametere:** `farge` (uint32_t) – fargen animasjonen skal bruke, `sekunder` (int) – omtrent hvor lenge animasjonen skal vare.
- **Returverdi:** Ingen (void).
- **Hint:** Vær kreativ! Dette er en fri oppgave uten fasit — bruk gjerne effekter du har laget/sett i andre animasjonsfunksjoner.

### `void startStoppeklokke(uint32_t farge)`
En stoppeklokke (motsatt av `startNedtelling`) som teller oppover helt til brukeren stopper den selv.
- **Parameter:** `farge` (uint32_t) – fargen på LED-en som beveger seg rundt ringen ett hakk i sekundet.
- **Returverdi:** Ingen (void).
- **Viktig:** Også denne er **blokkerende**, og avbrytes ved å skrive `stopp` i Serial Monitor. Skriv ut hvor mange sekunder som gikk til Serial når den stoppes.
- **Hint:** Bruk `% NUM_LEDS` for å håndtere at "viseren" går en hel runde og fortsetter fra begynnelsen igjen.

### `bool knappTrykket()`
Leser av en valgfri fysisk trykknapp koblet til `BUTTON_PIN`, og returnerer `true` nøyaktig én gang per trykk.
- **Parametere:** Ingen.
- **Returverdi:** `bool` – `true` akkurat idet knappen trykkes ned, ellers `false`.
- **Krever kabling:** Se koblingstabellen i [HARDWARE.md](HARDWARE.md#oppkobling) for hvordan knappen skal kobles til (`BUTTON_PIN`, med `INPUT_PULLUP`).
- **Hint:** `digitalRead(BUTTON_PIN)` er `LOW` når knappen er nede (siden vi bruker `INPUT_PULLUP`). Bruk en `static bool` for å huske forrige tilstand, slik at du kun får `true` på selve overgangen fra oppe til nede (debouncing) — ellers vil den telle mange trykk mens du holder den inne.

### `void spillRTTTL(String sang)`
Spiller av en RTTTL-ringetonestreng (samme format som gamle Nokia-ringetoner) på buzzeren.
- **Parameter:** `sang` (String) – en RTTTL-streng på formatet `"Navn:d=4,o=5,b=125:8c,8d,8e,2f"` (navn:standardverdier:noter).
- **Returverdi:** Ingen (void).
- **Hint:** Del strengen opp med `indexOf(':')`/`substring()` for å skille navn, standardverdier og noter. Del notedelen opp med komma, og hver note i varighet + tonenavn (+ evt. `#`) + oktav. Hjelpetabellen `noteFrekvenser[]` og funksjonen `rtttlFrekvens(indeks, oktav)` (ferdig laget rett over `spillRTTTL` i koden) regner ut frekvensen for deg — du trenger «bare» å parse strengen riktig og kalle `tone(soundpin, frekvens, varighetMs)`.

### 🌐 Web-grensesnitt (ekstra stor oppgave, krever samarbeid)

En avansert tilleggsoppgave for en gruppe som vil gå videre: la brukeren styre klokken via en nettside i stedet for (eller i tillegg til) Serial-menyen, ved å koble seg til IP-adressen til ESP32-en i en nettleser.

> **Avhengighet:** Denne oppgaven kan først startes når `visMeny()` og `sjekkSerialMeny()` er ferdig implementert, siden web-menyen skal gjenbruke samme meny-logikk.

**Hva skal gjøres?** Tre funksjoner må implementeres sammen:
- `settOppWebserver()` – setter opp `WebServer`-objektet og definerer nettsidene/rutene, kalles én gang fra `setup()`.
- `handterWebKlient()` – håndterer innkommende nettleser-forespørsler, kalles hver `loop()`.
- `genererMenyHTML()` – bygger HTML-siden som viser de samme valgene som `visMeny()`.

**Hint:**
- `#include <WebServer.h>` følger med ESP32-kortpakken og krever ingen ekstra installasjon.
- Lag et globalt objekt `WebServer server(80);`, definer ruter med `server.on("/", ...)`, og kall `server.begin()` i `settOppWebserver()`.
- `handterWebKlient()` blir stort sett bare et enkelt kall til `server.handleClient()`.
- Test ved å skrive ut `WiFi.localIP()` til Serial og åpne den IP-en i en nettleser på samme nettverk.

---

## Hardware-oppgaver (krever samarbeid)

I tillegg til kodefunksjonene over finnes det to fysiske oppgaver som noen i klassen bør ta ansvar for. De krever ikke koding, men er like viktige for at klokken skal fungere og se bra ut — og de er for store til å gjøre alene, så gå sammen i en gruppe på 2-4.

### 🔌 Kabling og lodding

**Hva skal gjøres?**
1. Lodd ledninger fast på riktig pad/pinne på LED-ringen (DIN, VCC, GND) slik at den kan kobles til ESP32-en med dupontledninger.
2. Koble ESP32-en til LED-ringen (og buzzer, hvis dere har en) med dupontledninger, i tråd med koblingstabellen i [HARDWARE.md](HARDWARE.md#oppkobling).
3. Last opp koden og bekreft at LED-ringen faktisk lyser riktig — det er den endelige testen på at loddingen er god.

**Hvorfor er dette viktig?**
Uansett hvor god koden er, fungerer ikke klokken uten en pålitelig fysisk tilkobling. Dette er en praktisk øvelse i å lese en koblingstabell og omsette den til ekte hardware — en ferdighet som er like nyttig som programmering, og som gir umiddelbar, synlig tilbakemelding når noe er feil (eller riktig!).

**Sikkerhet og hint:**
- Loddebolten blir svært varm (250–350 °C) — bruk loddestativ, ikke ta på spissen/den varme delen, og jobb på et ikke-brennbart underlag.
- Jobb gjerne to og to: én holder og varmer, én mater loddetinn.
- Dobbeltsjekk polaritet (VCC/GND) *før* dere kobler til strøm — feilkobling kan ødelegge LED-ringen eller ESP32-en permanent.
- Test loddepunktene med et multimeter (kontinuitetstest) før strøm kobles til, for å avsløre kalde loddepunkter eller utilsiktede kortslutninger.

**Dokumentasjon:** Ta et bilde av den ferdige kablingen/loddingen og legg det ved i PR-en (f.eks. i en `dokumentasjon/hardware/`-mappe). Fyll deretter ut malen i [HARDWARE.md](HARDWARE.md#dokumentasjon-fra-hardware-gruppene) med bilder og en kort refleksjon: Hva var vanskelig? Hvordan testet dere at koblingen fungerte?

### 🖨️ 3D-printet ramme/kabinett

**Hva skal gjøres?**
Design og skriv ut (eller lasérkutt, hvis 3D-printer ikke er tilgjengelig) en ramme som LED-ringen monteres i. Rammen må oppfylle disse kravene:

1. **Reflekterende yttervegg:** LED-ene på ringen stråler i utgangspunktet rett utover og til siden. Rammen bør derfor ha en vegg/kant utenfor ringen som reflekterer lyset videre utover — bruk gjerne hvit/blank plastfarge, og vinkle veggen slik at lyset kastes utover i stedet for å forsvinne til værs.
2. **Skillevegger mellom hver LED:** Lag en liten skillevegg mellom hver enkelt LED (som tynne "kile"-formede rom rundt hver LED, litt som et solur inndelt i skiver), slik at lyset fra én LED ikke blander seg med naboene. Det gjør det mye lettere å se nøyaktig hvilken LED som lyser — avgjørende for f.eks. klokkeviserne og nedtellingsbaren i koden.
3. Rammen må ha plass til ESP32 og eventuell buzzer, og gjerne en åpning for USB-kabelen (strøm/opplasting).

**Hvorfor er dette viktig?**
Dette er en øvelse i produktdesign og fysikk: dere må måle det fysiske utstyret (antall LED-er, ringens diameter, avstanden mellom hver LED), lage en 3D-modell som passer nøyaktig, og tenke på hvordan lys sprer seg og reflekteres — ikke bare hvordan koden styrer fargene.

**Hint:**
- Start med å måle ringens ytre/indre diameter. Finn avstanden mellom hver LED («pitch») ved å dele ringens omkrets på antall LED-er (`NUM_LEDS` i koden).
- Tenk på formen som et solur delt inn i like mange sektorer som det er LED-er — hver LED får sin egen kile-formede "lomme".
- Gratis CAD-verktøy: Tinkercad (nybegynnervennlig, nettbasert) eller Fusion 360 (mer avansert, gratis for studenter).
- Iterér! Print gjerne en liten testbit (f.eks. 1/8 av ringen) først for å sjekke mål og lysspredning, før dere printer hele rammen.

**Dokumentasjon:** Del Fusion 360-prosjektet i skyen og lim inn lenken i [HARDWARE.md](HARDWARE.md#3d-modell-av-rammen-autodesk-fusion-360). Legg deretter ved et skjermbilde av 3D-modellen og et bilde av den ferdig monterte rammen i den utfylte malen, sammen med en kort refleksjon: Hvilke valg tok dere for å spre lyset godt utover og skille LED-ene fra hverandre? Hva ville dere gjort annerledes neste gang?
