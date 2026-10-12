# Hardware – Klokkeprosjekt 2026

Dette dokumentet beskriver den fysiske oppkoblingen av klokken: hvordan ESP32, NeoPixel-ringen og buzzeren er koblet sammen, hvor koblingsskjemaet ligger, og hvor 3D-modellen av rammen rundt lyset er delt. Dette dokumentet skal holdes oppdatert av gruppa/gruppene som jobber med hardware — se [ELEVOPPGAVER.md](ELEVOPPGAVER.md#hardware-oppgaver-krever-samarbeid) for selve oppgavebeskrivelsen.

## Oppkobling

Koble ESP32 til NeoPixel-ringen og eventuell buzzer slik:

| Signal | NeoPixel / Buzzer Pin | ESP32 Pin | Kommentar |
|---|---|---|---|
| **Spenning** | 5V / VCC | **5V / VIN** | Strømforsyning til LED-ene |
| **Jord** | GND | **GND** | Felles jord |
| **LED-data** | DIN (Data In) | **GPIO 25** | Styresignal til ringen (`LED_PIN`) |
| **Buzzer (+)** | Pluss (+) | **GPIO 26** | *(Valgfritt)* Lydsignal (`soundpin`) |
| **Buzzer (-)** | Minus (-) | **GND** | Felles jord |
| **Knapp (ben 1)** | - | **GPIO 27** | *(Valgfritt)* Trykknapp for `knappTrykket()` (`BUTTON_PIN`, bruker `INPUT_PULLUP`) |
| **Knapp (ben 2)** | - | **GND** | Felles jord |

> **Tips:** Har dere ikke buzzer koblet til? Ingen fare — funksjonen `spillMelodi` kan fint blinke LED-ringen med farger i stedet for å spille lyd!

## Koblingsskjema (draw.io)

Kretsen skal tegnes som et koblingsskjema i [draw.io](https://app.diagrams.net/) (også kjent som diagrams.net). Slik gjør dere det:

1. Gå til [app.diagrams.net](https://app.diagrams.net/) og lag skjemaet (ESP32, NeoPixel-ring, buzzer og hvordan pinnene kobles sammen).
2. Lagre fila som `dokumentasjon/hardware/koblingsskjema.drawio` i repoet (opprett mappene hvis de ikke finnes).
3. Eksporter også et bilde (PNG/SVG) av skjemaet til samme mappe, f.eks. `dokumentasjon/hardware/koblingsskjema.png`, slik at det kan vises direkte under.
4. Bytt ut lenken/bildet under med deres eget.

<!-- Når skjemaet er klart, bytt ut linjen under med f.eks.: -->
<!-- ![Koblingsskjema](dokumentasjon/hardware/koblingsskjema.png) -->

**Koblingsskjema:** _(ikke lagt til ennå — lim inn bilde eller lenke her)_

## 3D-modell av rammen (Autodesk Fusion 360)

Rammen rundt lyset (se [3D-printet ramme/kabinett](ELEVOPPGAVER.md#-3d-printet-rammekabinett) i elevoppgavene) designes i Autodesk Fusion 360 og deles i skyen slik at hele klassen kan se og bygge videre på modellen.

1. Design rammen i Fusion 360.
2. Del prosjektet/mappen i skyen (**Share** → kopier lenken, sørg for at den er delt med "Anyone with the link can view" eller tilsvarende).
3. Lim inn lenken under.

**Lenke til Fusion 360-prosjekt:** _(ikke lagt til ennå — lim inn delt lenke her)_

---

## Dokumentasjon fra hardware-gruppene

Denne seksjonen fylles ut etter hvert som gruppene fullfører sine hardware-oppgaver (se [ELEVOPPGAVER.md](ELEVOPPGAVER.md#hardware-oppgaver-krever-samarbeid)). Kopiér malen under, fyll den ut og legg den til her — én seksjon per gruppe/oppgave.

### Mal (kopiér denne og fyll ut)

```markdown
### 🔌/🖨️ <Kabling og lodding / 3D-printet ramme>

**Gruppe:** <navn på elevene i gruppa>
**Dato:** <dato>

**Hva gjorde vi?**
<Kort beskrivelse av hva som ble gjort>

**Bilder/vedlegg:**
<Lenke(r) til bilder, lagt i f.eks. dokumentasjon/hardware/>

**Hvordan testet vi det?**
<Hvordan dere verifiserte at koblingen/rammen fungerte som den skulle>

**Refleksjon:**
<Hva var vanskelig? Hva ville dere gjort annerledes neste gang?>
```

<!-- Legg til utfylte seksjoner under, én per gruppe -->
