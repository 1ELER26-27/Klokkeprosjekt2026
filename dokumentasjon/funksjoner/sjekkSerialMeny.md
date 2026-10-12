# `sjekkSerialMeny`
**Laget av:** <Endre>

**Hva gjør den?**
Lese hva som ligger på serial, skjekker om det er meny. 
Hvis det er meny skal han kjøre meny funksjonen. Hvis ikke svarer
han "Ugyldig kommando". 

**Parametere:**
- <navn> (<type>): <hva parameteren betyr / brukes til>
Ingen

**Returverdi:**
- <type>: <hva som returneres og hva det betyr>
(skriv "Ingen (void)" hvis funksjonen ikke returnerer noe)
Ingen (void)

**Refleksjon:**
<Hvorfor løste du det på denne måten? Var det noe som var vanskelig eller lurt
å tenke på? Er det noe du ville gjort annerledes?>
Jeg valgte å løse oppgaven ved å skjekke om Serial.available() er større enn 0. Hvis det finnes data, leser funskjonen inn kommandoen som brukeren har skrevet. Deretter skjekker funskjonen om kommando er gyldig. I dette tilfeldet er den eneste gyldige kommando "meny". Hvis brukeren skriver denne kommandoen vil funskjonen skrive "Vis Meny" til Serial, og hvis kommandoen er ugyldig, vil den si det "UGYLDIG KOMMANDO". Det var litt vanskelig i starten, men etter litt hjelp fikk jeg det til.