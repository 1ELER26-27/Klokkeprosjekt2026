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
_(ikke dokumentert ennå)_

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
_(ikke dokumentert ennå)_

### `hentGjeldendeFag`
_(ikke dokumentert ennå)_

### `hentInternetTid`
_(ikke dokumentert ennå)_

### `helgAnimasjon`
_(ikke dokumentert ennå)_

### `planIndex`
_(ikke dokumentert ennå)_

### `handterAktivitetsbytte`
_(ikke dokumentert ennå)_
