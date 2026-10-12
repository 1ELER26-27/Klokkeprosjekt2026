# `hentInternetTid`

> ℹ️ **Denne funksjonen er allerede ferdig implementert og dokumentert av Marcel & Luka som et referanseeksempel.** Se koden i `sketch/sketch.ino`.

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
