# Dokumentasjon – Klokkeprosjekt 2026

`sketch/sketch.ino` er en C++-fil og egner seg dårlig til lange forklaringer og refleksjoner. Derfor skrives **all dokumentasjon av funksjonene** her i stedet, i egne markdown-seksjoner — én per funksjon. Inne i koden holder det med en kort `// Laget av: <Fornavn>`-kommentar over funksjonen din.

Se [ELEVOPPGAVER.md](ELEVOPPGAVER.md) for selve oppgavebeskrivelsen (hva funksjonen skal gjøre, parametere, hint).

## Slik fyller du inn

1. Finn overskriften for funksjonen du har implementert lenger ned i denne fila.
2. Kopiér malen under (i den samme seksjonen) og fyll den ut.
3. Ta med endringen i samme PR som kodeendringen din.

```markdown
**Laget av:** <Fornavn>

**Hva gjør den?**
<1-3 setninger som forklarer hva funksjonen gjør, med egne ord>

**Parametere:**
- <navn> (<type>): <hva parameteren betyr / brukes til>
(skriv "Ingen" hvis funksjonen ikke tar imot noen parametere)

**Returverdi:**
- <type>: <hva som returneres og hva det betyr>
(skriv "Ingen (void)" hvis funksjonen ikke returnerer noe)

**Refleksjon:**
<Hvorfor løste du det på denne måten? Var det noe som var vanskelig eller lurt
å tenke på? Er det noe du ville gjort annerledes?>
```

Poenget med dokumentasjonen er todelt: den skal gjøre det lett for andre (og deg selv) å forstå hva funksjonen gjør uten å lese hele koden, **og** den skal tvinge deg til å reflektere over løsningen din i stedet for bare å skrive kode og gå videre.

### Eksempel: `uint32_t fagFarge(Fag fag)`

Slik kan en utfylt seksjon se ut:

**Laget av:** Kari

**Hva gjør den?**
Slår opp hvilken farge LED-ringen skal lyse i basert på hvilket fag som er
sendt inn, ved hjelp av en switch-setning på enum-verdien.

**Parametere:**
- fag (Fag): Hvilket skolefag det skal hentes en farge for (se enum Fag
  øverst i sketch.ino, f.eks. MATTE, NORSK, FRIMINUTT osv.)

**Returverdi:**
- uint32_t: En fargeverdi laget med strip.Color(r, g, b) som kan sendes rett
  til strip.setPixelColor()/strip.fill(). Returnerer svart (av) dersom faget
  ikke er gjenkjent.

**Refleksjon:**
Jeg valgte kalde farger (blå/grønn) til teorifag og en varm farge til gym,
slik at det er lett å skille dem fra hverandre på avstand. Jeg måtte huske på
default-caset i switch-en, ellers ville funksjonen ikke returnere noe for et
ukjent fag.

---

## Enkle funksjoner

### `sjekkHelg`
_(ikke dokumentert ennå)_

### `fagFarge`
_(ikke dokumentert ennå — se det utfylte eksempelet over)_

### `fagNavn`
_(ikke dokumentert ennå)_

### `blinkLED`
_(ikke dokumentert ennå)_

### `timeStartAnimasjon`
_(ikke dokumentert ennå)_

### `friminuttAnimasjon`
**Laget av:** <Vilde>

**Hva gjør den?**
<1-3 setninger som forklarer hva funksjonen gjør, med egne ord>
Jeg har lagt en animasjon til når det er friminutt, Så den går gjenom alle regnbuens farger, også på slutten i et par sek så lyser helle med random lys. 

**Parametere:**
- <navn> (<type>): <hva parameteren betyr / brukes til>
funksjonen mottar int minutt og int index, men bruker de ikke

**Returverdi:**
- <type>: <hva som returneres og hva det betyr>
Ingen (void)"

**Refleksjon:**
<Hvorfor løste du det på denne måten? Var det noe som var vanskelig eller lurt
å tenke på? Er det noe du ville gjort annerledes?> Jeg synnes at dte var litt vansklig å byne med men så fik jeg en grunnbase av den startkoden så da ble det litt enklere men synnes det var helt perfekt vansklighets grad for ,eg 

### `visMeny`
_(ikke dokumentert ennå)_

### `sjekkSerialMeny`
_(ikke dokumentert ennå)_

## Middels funksjoner

### `visKlokkevisere`
_(ikke dokumentert ennå)_

### `nedtellingBar`
_(ikke dokumentert ennå)_

### `melodiSpiller`
_(ikke dokumentert ennå)_

### `spillMelodi`
_(ikke dokumentert ennå)_

### `visGjeldendeStatus`
_(ikke dokumentert ennå)_

### `ferdigForDagenAnimasjon`
_(ikke dokumentert ennå)_

### `helgeSluttAnimasjon`
_(ikke dokumentert ennå)_

### `handterHelg`
_(ikke dokumentert ennå)_

## Avanserte funksjoner

### `fyllPlan`
_(ikke dokumentert ennå)_

### `beregnTidIgjen`
**Laget av:** Marcel & Luka

**Hva gjør den?**
Funksjonen beregnTidIgjen tar inn fire parametere, index (gjeldende fag), nåværende time, minutt og sekund, og beregner hvor mye tid som er igjen av denne timen. Returnerer 0 hvis index = -1, kan være nyttig når dagen ikke har startet, eller hvis man ikke vil beregne tid.
Vanligvis returnerer den tid igjen i sekunder. 

**Parametere:**
index (int) - hvor vi er i timePlan plan[]
time (int) - Timen i tid akkurat nå, eks: kl 12:15:37, time = 12
minutt (int) - Minutt i tid akkurat nå, eks: kl 12:15:37, minutt = 15
sekund (int) - Sekund i tid akkurat nå, eks: kl 12:15:37 sekund = 37

**Returverdi:**
int: returnerer hvor mye tid som er igjen av timen i sekunder.

**Refleksjon:**
Hintene var til god hjelp, men vi forsto fort hva vi måtte gjøre. Vi testet det med å lage en dummy plan, siden timeplanen ikke var laget enda. Bruker max(0, SluttSek - naSek), slik at man får 0 hvis timen er ferdig, ikke negative verdier.

### `hentGjeldendeFag`
**Laget av:** Marcel

**Hva gjør den?**
Funksjonen tar inn index (i planen), og returnerer en verdi fra enum Fag { INGENTING (0), FRIMINUTT (1), ELKRETSER (2), ENOGSTYR (3), NORSK (4), ENGELSK (5), MATTE (6), NATURFAG (7), GYM (8)}. Hvis index = -1, blir INGENTING (0) returnert.

**Parametere:**
index (int) - hvor vi er i timePlan plan[].

**Returverdi:**
Fag (enum) - tall fra 0 - 8, hvor hvert tall står for et forskjellig fag.

**Refleksjon:**
Det var ikke en særlig vanskelig funksjon å lage.

### `hentInternetTid`
**Laget av:** Marcel & Luka

**Hva gjør den?**
hentInternetTid konfigurerer og sjekker at ESP32 sin indre klokke er synkronisert til den faktiske tiden.
Den tar også hensyn til vinter- og sommertid. Den returnerer true hvis det funket å synkronisere tiden, false hvis den feilet.

**Parametere:**
Ingen parametre

**Returverdi:**
bool: returnerer true (1) eller false (0), egentlig en sjekk for om noe stemmer eller ikke.

**Refleksjon:**
Det var litt styr med å få sommer- og vintertid til å fungere, siden det var litt merkelig syntaks å konfigurere for dette,
men med litt feilsøking fikk vi det til.

### `helgAnimasjon`
_(ikke dokumentert ennå)_

### `planIndex`
_(ikke dokumentert ennå)_

### `handterAktivitetsbytte`
_(ikke dokumentert ennå)_

## Ekstra / valgfrie funksjoner

### `startNedtelling`
_(ikke dokumentert ennå)_

### `spillAnimasjon`
_(ikke dokumentert ennå)_

### `startStoppeklokke`
_(ikke dokumentert ennå)_

### `knappTrykket`
_(ikke dokumentert ennå)_

### `spillRTTTL`
_(ikke dokumentert ennå)_

### Web-grensesnitt (`settOppWebserver`, `handterWebKlient`, `genererMenyHTML`)
_(ikke dokumentert ennå)_
