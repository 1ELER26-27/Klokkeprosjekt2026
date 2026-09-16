# Dokumentasjon – Klokkeprosjekt 2026

**all dokumentasjon av funksjonene** legges her — **én egen fil per funksjon**, i mappa [`dokumentasjon/funksjoner/`](funksjoner/). Inne i koden holder det med en kort `// Laget av: <Fornavn>`-kommentar over funksjonen din.

Se [ELEVOPPGAVER.md](../ELEVOPPGAVER.md) for selve oppgavebeskrivelsen (hva funksjonen skal gjøre, parametere, hint) og bookingtabellen som lenker til hver enkelt fil.

## Slik fyller du inn

1. Finn fila for funksjonen din i [`dokumentasjon/funksjoner/`](funksjoner/) (samme navn som funksjonen, f.eks. `fagFarge.md`).
2. Kopiér malen under og lim den inn i fila, under den ferdige overskriften.
3. Fyll ut malen.
4. Ta med endringen i samme PR som kodeendringen din.

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

## Eksempel: `uint32_t fagFarge(Fag fag)`

Slik kan en utfylt fil se ut (se også den faktiske utfylte fila: [funksjoner/fagFarge.md](funksjoner/fagFarge.md)):

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

## Mappestruktur

```
dokumentasjon/
├── README.md              <- denne fila (mal + instruksjoner)
├── funksjoner/             <- én fil per funksjon
│   ├── sjekkHelg.md
│   ├── fagFarge.md
│   ├── ...
└── hardware/               <- bilder/skjema fra hardware-gruppene (se HARDWARE.md)
```
