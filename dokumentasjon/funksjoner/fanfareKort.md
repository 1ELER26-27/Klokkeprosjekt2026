# `fanfareKort`
**Laget av:** Marcel F. Høyland, Nicholas A. Kvalavåg, med hjelp av Viggo S. Jacobsen & Joachim L. Dysvik
 
**Hva gjør den?**
fanfareKort spiller av en unik fanfare for hver forandring i timeplanen.
 
**Parametere:**
fag (Fag): parameteren er definert fra vår enum, hvor INGENTING = 0, FRIMINUTT = 1, ELKRETSER = 2, ENOGSTYR = osv..., NORSK, ENGELSK, MATTE, NATURFAG, GYM. Dette brukes for å spille av riktig fanfare for hver endring i timeplanen
 
helg (bool): true eller false, hvis det er helg, spilles det av en unik fanfare.
 
**Returverdi:**
Ingen (void)
 
**Refleksjon:**
Dette skulle egentlig være en enkel funksjon, men vi valgte å komplisere den litt...
Vi ville ha en melodi for hvert fag, og nokså avanserte melodier. Dette førte til at vi måtte lage en struktur på hvordan vi setter opp melodiene.
Vi har en uint16_t for alle notene i en melodi, og en egen struct (duration) for egenskapene til hver note i uint16_t variabelen. Her kunne vi velge varigheten på hver note, varigheten mellom notene, antall gjentakelser, endring i varighet og hvor mange noter som forfølger i gjentakelsen. Dette føltes som den beste måten å lage melodiene slik vi ville.
Vi brukte også header fil (sanger.h) for alle melodiene og (pitches.h) for notene, slik at det ble litt mer ryddig.
Fordi funksjonen 