# `beregnTidIgjen`

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
