# `planIndex`
**Laget av:** Marcel

**Hva gjør den?**
planIndex() tar inn tre parametere, ukedagen, timen og minuttet, og returnerer en int i (indexen) for hvor man er i planen på dette tidspunktet. 

**Parametere:**
- <navn> (<type>): <hva parameteren betyr / brukes til>
(skriv "Ingen" hvis funksjonen ikke tar imot noen parametere)
ukedag (int) - skriv inn hvilken ukedag du vil finne indexen i plan til
time (int) - skriv inn hvilken time av klokken du vil finne indexen i plan til (eks: kl 13:15 blir 13)
minutt (int) - skriv inn hvilket minutt av klokken du vil finne indexen i plan til (eks: kl 13:15 blir 15)

int står for integer og betyr heltall. I dette tilfellet kan det være både positive og negative tall

**Returverdi:**
int - returnerer indexen i plan som oppfyller kriteriene du gir den. Hvis du vil ha planIndex(TIRSDAG, 12, 30), får du ut
15, fordi det er på dette tidspunktet i index planen er på akkurat da.

**Refleksjon:**
Ble ganske fort klar over hva jeg måtte gjøre. Trodde jeg var ferdig, men når jeg testet verdier oppdaget jeg noe veldig rart. i ble større enn 60, noe som ikke skulle gå an når for løkken gikk fra 0 til 60, det viste seg at lengre oppe der vi definerer hvor stor plan skulle være, burde den vært plan[61] ikke plan[60], siden plan[60] betyr 0 - 59.