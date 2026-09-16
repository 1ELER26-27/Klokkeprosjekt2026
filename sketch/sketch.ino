/*
  KLOKKEPROSJEKT 2026
  ====================
  En smart skole-timeplan klokke med ESP32 og NeoPixel LED-ring
    
  Hver elev/gruppe skal implementere sin egen funksjon.
  Alle funksjoner må følge spesifikasjonene nøyaktig!
*/

#include <WiFi.h> // Bibliotek for WiFi-funksjoner, inkludert i Arduino IDE (Må bruke ESP32 eller ESP8266 for WiFi)
#include <WiFiMulti.h> // Lar ESP32 koble seg til beste tilgjengelige nettverk (Wokwi eller fysisk)
#include <ArduinoOTA.h> // Bibliotek for trådløs programmering (Over-The-Air) over WiFi
#include <time.h> // Bibliotek for tidsfunksjoner, inkludert i Arduino IDE
#include <sys/time.h> // Bibliotek for timeval og settimeofday (brukes til dummytid/testing)
#include <Adafruit_NeoPixel.h> // Bibliotek for NeoPixel LED-ring, må lastes ned via Library Manager i Arduino IDE

// Hent lokale nettverkshemmeligheter hvis secrets.h finnes (ignorert av Git):
#if __has_include("secrets.h")
  #include "secrets.h"
#else
  #define FYSISK_WIFI_SSID ""
  #define FYSISK_WIFI_PASS ""
  #define BRUK_STATISK_IP false
#endif

// ========== HARDWARE KONFIGURASJON ==========
#define LED_PIN 25        // Pin for NeoPixel ring
#define NUM_LEDS 77       // Antall LEDs på ringen/stripen (juster dette tallet hvis dere bruker en ring med f.eks. 60 eller 24 LEDs)
#define soundpin 26       // Buzzerpin hvis vil bruke buzzer....
#define BUTTON_PIN 27     // Pin for valgfri fysisk knapp (kobles med INPUT_PULLUP: ett ben til pinnen, det andre til GND)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// ========== WIFI KONFIGURASJON ==========
WiFiMulti wifiMulti;
const char* WOKWI_SSID = "Wokwi-GUEST";
const char* WOKWI_PASS = "";
// Bakoverkompatibilitet hvis noen funksjoner refererer til ssid/password:
const char* ssid = WOKWI_SSID;
const char* password = WOKWI_PASS;

// ========== ENUMS OG DATASTRUKTURER ==========
enum Fag {
  INGENTING = 0, FRIMINUTT, ELKRETSER, ENOGSTYR, NORSK, ENGELSK, MATTE, NATURFAG, GYM
};

enum Ukedag {
  SONDAG = 0, MANDAG, TIRSDAG, ONSDAG, TORSDAG, FREDAG, LORDAG
};

struct timePlan {
  Ukedag dag;       // Se enum Ukedag
  byte startTime;   // 0-23
  byte startMinutt; // 0-59
  byte varighet;    // Minutter
  Fag fag;          // Se enum for fag
};

// ========== GLOBALE VARIABLER ==========
timePlan plan[50];     // Array for hele ukens timeplan (Ikke laget enda)
int antallTimer = 2;   // TODO: Oppdater til HØYESTE INDEX + 1 når fyllPlan() er ferdig utfylt (satt til 2 for test-eksempler)

Fag gjeldendeFag = INGENTING; // Hvilket fag vi har nå (bruker enum)
Fag forrigeFag = INGENTING;   // Hvilket fag vi hadde før
int sekunderIgjen = 0;        // Sekunder igjen av gjeldende aktivitet

// Status-flagg for animasjoner
bool nyTime = false;          // True når en ny time starter
bool nyttFriminutt = false;   // True når et nytt friminutt starter
bool ferdigForDagen = false;  // True når skoledagen er ferdig
bool erHelg = false;          // True når det er helg

int melodi[3] = {1, 2, 3};             // Eksempel-toner til melodiSpiller()
int melodi_varighet[3] = {100, 100, 100}; // Eksempel-varigheter (ms) til melodiSpiller()

// ========== FUNKSJONSERKLÆRINGER ==========
// Disse funksjonene må elevene implementere:

// ENKLE FUNKSJONER:
bool sjekkHelg(int ukedag); // Returnerer true hvis ukedag er lørdag/søndag
uint32_t fagFarge(Fag fag); // Returnerer LED-fargen som hører til faget
String fagNavn(Fag fag); // Returnerer navnet på faget som tekst (til Serial Monitor)
void blinkLED(uint32_t farge, int antallBlink); // Blinker hele ringen i en farge et gitt antall ganger
void timeStartAnimasjon(uint32_t fagfarge); // Viser en kort animasjon når en ny time starter
void friminuttAnimasjon(int minutt, int index); // Viser en animasjon i friminuttet
void visMeny(); // Meny hvor brukeren kan aktivere alle funksjonene
void sjekkSerialMeny(); // Sjekker Serial-input og åpner menyen hvis brukeren skriver "meny"

// MIDDELS FUNKSJONER:
void visKlokkevisere(int time, int minutt, int sec); // Tegner time-, minutt- og sekundviser på ringen
void nedtellingBar(int index, int sekunderIgjen, uint32_t fagfarge); // Tegner en nedtellingsbue for gjenværende tid av aktiviteten
void melodiSpiller(int note[], int varighet[], int antallToner); // Spiller av en liste med toner og varigheter på buzzeren
void spillMelodi(int melodiNr); // Spiller lyd/blink for gitt melodi-nummer
void visGjeldendeStatus(int index, int minutt); // Viser animasjon ved hendelser basert på status-flaggene
void ferdigForDagenAnimasjon(); // Viser animasjon når skoledagen er ferdig
void helgeSluttAnimasjon(); // Viser feiringsanimasjon etter siste time på fredag
void handterHelg(int ukedag); // Sjekker om det er helg og oppdaterer flagg/animasjon

// AVANSERTE FUNKSJONER:
void fyllPlan(); // Fyller plan[] med ukens timeplan
int beregnTidIgjen(int index, int time, int minutt, int sekund); // Returnerer sekunder igjen av gjeldende aktivitet
Fag hentGjeldendeFag(int index); // Returnerer faget for gitt indeks i plan[]
bool hentInternetTid(); // Kobler til WiFi/NTP og henter riktig klokkeslett, returnerer true ved suksess
void helgAnimasjon(); // Viser animasjon i helgene
int planIndex(int ukedag, int time, int minutt); // Returnerer indeksen i plan[] for gjeldende time, eller -1
void handterAktivitetsbytte(Fag nyttFag, int ukedag); // Oppdager fagbytte og setter riktige status-flagg/melodi
void settDummyTid(int ukedag, int time, int minutt, int sekund); // Setter ESP32-klokken manuelt til test-tidspunkt
void setupArduinoOTA(); // Klargjør ESP32 for trådløse oppdateringer (OTA) over WiFi

// EKSTRA / VALGFRIE FUNKSJONER (utvider funksjonaliteten - se ELEVOPPGAVER.md):
void startNedtelling(uint32_t farge, int minutt, int sekund); // Blokkerende nedtellingstimer, avbrytes ved å skrive "stopp" i Serial
void spillAnimasjon(uint32_t farge, int sekunder); // Fri animasjon i en gitt farge, i et gitt antall sekunder
void startStoppeklokke(uint32_t farge); // Blokkerende stoppeklokke (teller oppover), avbrytes ved å skrive "stopp" i Serial
bool knappTrykket(); // Returnerer true én gang når den fysiske knappen trykkes ned (krever kabling, se HARDWARE.md)
void spillRTTTL(String sang); // Spiller av en RTTTL-ringetonestreng på buzzeren
void settOppWebserver(); // (Ekstra stor oppgave) Setter opp webserveren og definerer nettsidene
void handterWebKlient(); // (Ekstra stor oppgave) Håndterer innkommende nettleser-forespørsler, kalles hver loop()
String genererMenyHTML(); // (Ekstra stor oppgave) Bygger HTML-menyen som vises i nettleseren

//==================================================================================================================================

void startupAnimasjon() {
  // Enkel oppstart-animasjon
  for(int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 50, 100));
    strip.show();
    delay(10);
  }
  strip.clear();
  strip.show();
}

void settDummyTid(int ukedag, int time, int minutt, int sekund) {
  // Setter ESP32-klokken manuelt til et gitt tidspunkt slik at klokken kan tikke og testes uten fungerende WiFi/NTP.
  // Referanseuke i september 2026: SONDAG=6. sept, MANDAG=7. sept, TIRSDAG=8. sept, ONSDAG=9. sept, etc.
  struct tm t = {0};
  t.tm_year = 2026 - 1900;
  t.tm_mon  = 8;          // September (0 = jan, 8 = sep)
  t.tm_mday = 6 + ukedag; // Dag i måneden som matcher ukedagen (SONDAG=0 -> 6. sept)
  t.tm_hour = time;
  t.tm_min  = minutt;
  t.tm_sec  = sekund;
  t.tm_isdst = 1;         // Norsk sommertid

  time_t epoch = mktime(&t);
  struct timeval tv;
  tv.tv_sec = epoch;
  tv.tv_usec = 0;
  settimeofday(&tv, NULL);
}

void setupArduinoOTA() {
  // Hostname som vises i Arduino IDE og på nettverket
  ArduinoOTA.setHostname("klokke-esp32");

  ArduinoOTA.onStart([]() {
    String type = (ArduinoOTA.getCommand() == U_FLASH) ? "skisse/kode" : "filsystem";
    Serial.println("\n📡 Starter trådløs OTA-oppdatering (" + type + ")...");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\n✅ OTA-oppdatering fullført! Restarter ESP32...");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    static int sisteProsent = -1;
    int prosent = (progress / (total / 100));
    if (prosent != sisteProsent && prosent % 10 == 0) {
      Serial.printf("⏳ OTA-fremdrift: %u%%\n", prosent);
      sisteProsent = prosent;
    }
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("❌ OTA-feil [%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Autentisering feilet");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Oppstart feilet");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Tilkobling feilet");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Mottak feilet");
    else if (error == OTA_END_ERROR) Serial.println("Avslutning feilet");
  });

  ArduinoOTA.begin();
  Serial.println("📡 ArduinoOTA aktivert (Hostname: klokke-esp32)");
}

// ========== SETUP ==========
void setup() {
  Serial.begin(115200);
  Serial.println("🕐 KLOKKEPROSJEKT STARTER...");

  // Initialiser valgfri fysisk knapp (se HARDWARE.md for kobling)
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  // Initialiser LED-strip
  strip.begin();
  strip.show();
  startupAnimasjon();
  
  // Sett eventuell fast/statisk IP hvis konfigurert i secrets.h
  #if BRUK_STATISK_IP
    IPAddress local_IP(STATISK_IP);
    IPAddress gateway(STATISK_GATEWAY);
    IPAddress subnet(STATISK_SUBNET);
    IPAddress primaryDNS(STATISK_DNS);
    WiFi.config(local_IP, gateway, subnet, primaryDNS);
  #endif

  // Registrer nettverk i WiFiMulti (ESP32 velger automatisk det som er tilgjengelig):
  wifiMulti.addAP(WOKWI_SSID, WOKWI_PASS); // Alltid klar for Wokwi-simulering
  if (strlen(FYSISK_WIFI_SSID) > 0) {
    wifiMulti.addAP(FYSISK_WIFI_SSID, FYSISK_WIFI_PASS); // Fysisk nettverk fra secrets.h
  }

  // Koble til WiFi og hent tid
  if(hentInternetTid()) {
    Serial.println("✅ WiFi og tid OK!");
    blinkLED(strip.Color(0, 255, 0), 2); // Grønn = success
  } else {
    Serial.println("⚠️ WiFi/NTP ikke tilkoblet (eller ikke ferdig implementert).");
    Serial.println("🕒 Setter dummytid: Onsdag kl. 09:30:00 (for at klokken skal tikke og kunne testes)");
    settDummyTid(ONSDAG, 9, 30, 0);
    blinkLED(strip.Color(255, 150, 0), 2); // Oransje/gul = dummytid aktiv
  }

  // Klargjør trådløs programmering (OTA) hvis WiFi er tilkoblet
  if (WiFi.status() == WL_CONNECTED) {
    setupArduinoOTA();
  }

  // (Ekstra stor oppgave) Sett opp webserveren for web-grensesnittet, hvis implementert
  settOppWebserver();
  
  // Lag timeplan
  fyllPlan();
  Serial.println("📅 Timeplan lastet!");
  
  Serial.println("🚀 Klokke klar!");
}

// ========== HOVEDLOOP ==========
void loop() {
  // Håndter trådløs programmering (OTA) – aktiveres automatisk hvis WiFi kobler til
  static bool otaAktiv = false;
  if (!otaAktiv && WiFi.status() == WL_CONNECTED) {
    setupArduinoOTA();
    otaAktiv = true;
  }
  if (otaAktiv) {
    ArduinoOTA.handle();
  }

  // Hent gjeldende tid
  time_t now;
  struct tm timeinfo;
  time(&now);
  localtime_r(&now, &timeinfo);

  sjekkSerialMeny();
  if (knappTrykket()) { visMeny(); } // Valgfri fysisk knapp åpner menyen (se ELEVOPPGAVER.md)
  handterWebKlient(); // (Ekstra stor oppgave) Håndterer nettleser-forespørsler, hvis implementert
  handterHelg(timeinfo.tm_wday);

  // Beregn gjeldende fag og tid igjen
  int index_plan = planIndex(timeinfo.tm_wday, timeinfo.tm_hour, timeinfo.tm_min);
  Fag nyttFag = hentGjeldendeFag(index_plan);
  sekunderIgjen = beregnTidIgjen(index_plan, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

  handterAktivitetsbytte(nyttFag, timeinfo.tm_wday);
  gjeldendeFag = nyttFag;

  // Sjekk om det skal vises en hendelses-animasjon (ny time, friminutt, ferdig for dagen)
  visGjeldendeStatus(index_plan, timeinfo.tm_min);

  // Normal visning på LED-ringen (nedtelling og klokkevisere)
  strip.clear();
  nedtellingBar(index_plan, sekunderIgjen, fagFarge(gjeldendeFag));
  visKlokkevisere(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
  strip.show();

  // Debug info hver 5. sekund
  static unsigned long lastDebug = 0;
  if(millis() - lastDebug > 5000) {
    debugInfo();
    lastDebug = millis();
  }
  
  delay(500); // Oppdater to ganger i sekundet (hvert 500. ms)
}

void debugInfo() {
  // Tips: Utvid gjerne med flere Serial.print()-linjer etter hvert som dere legger til flere variabler (f.eks. erHelg, index_plan, WiFi.status())
  time_t now;
  struct tm timeinfo;
  time(&now);
  localtime_r(&now, &timeinfo);

  char tidStr[9];
  snprintf(tidStr, sizeof(tidStr), "%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);

  Serial.print("Tid: ");
  Serial.print(tidStr);
  Serial.print(" | Fag: ");
  Serial.print(fagNavn(gjeldendeFag));
  Serial.print(" (id ");
  Serial.print(gjeldendeFag);
  Serial.print(") | Sekunder igjen: ");
  Serial.print(sekunderIgjen);
  Serial.print(" (ca. ");
  Serial.print(sekunderIgjen / 60);
  Serial.println(" min)");
}

// ========== FUNKSJONSIMPLEMENTASJONER ==========
// ELEVENE MÅ IMPLEMENTERE DISSE FUNKSJONENE:

bool sjekkHelg(int ukedag) {
  // Laget av: 
  // TODO: Returner true hvis det er helg (lørdag eller søndag), ellers false
  // Input: ukedag er et tall der SONDAG=0 ... LORDAG=6 (se enum Ukedag)
  // Tips: Sammenlign ukedag med enum-verdiene SONDAG og LORDAG
  return false; // Placeholder - alltid "ikke helg"
}

//==================================================================================================================================

void handterHelg(int ukedag) {
  // Laget av: 
  // TODO: Bruk sjekkHelg(ukedag) til å avgjøre om det er helg akkurat nå
  // TODO: Oppdater den globale variabelen erHelg, og kall helgAnimasjon() når det er helg
  // Tips: Skriv gjerne ut en Serial-melding kun første gang det blir helg (bruk erHelg til å huske status)
}

//==================================================================================================================================


void visMeny() {
  // Laget av: 
  // TODO: Lag en meny på Serial-monitor der brukeren kan velge å teste de andre funksjonene
  // Tips: Serial.println() for å skrive ut valg, Serial.readStringUntil('\n') for å lese input
  // Tips: input.toInt() gjør om teksten brukeren skriver til et tall du kan bruke i switch/case
  // Tips: Du kan kalle settDummyTid(ONSDAG, 9, 30, 0) som et menyvalg for å simulere/teste ulike dager og tider!
  Serial.println("TODO: Lag menyen din her!");
}

//==================================================================================================================================

void sjekkSerialMeny() {
  // Laget av: 
  // TODO: Sjekk om brukeren har skrevet noe i Serial-monitoren, og åpne menyen med visMeny() hvis teksten er "meny"
  // Tips: Serial.available() forteller om det finnes tekst å lese
  // Tips: Serial.readStringUntil('\n') leser inn teksten, input.trim() fjerner mellomrom/linjeskift
}

//==================================================================================================================================

uint32_t fagFarge(Fag fag) {
  // Laget av: 
  // TODO: Returner en unik LED-farge for hvert fag i enum Fag
  // Tips: strip.Color(r, g, b) tar verdier fra 0-255 for hver fargekanal
  // Tips: Bruk switch/case eller if-else, én farge per fag
    switch (fag) {
        case matte:
            return strip.Color(198, 27, 108)
    
        case norsk:
            return strip.Color(239, 168, 123)

        case engelsk:
            return strip.Color(66, 20, 54)

        case naturfag:
            return strip.Color(180, 16, 199)

        case 
    }
}

//==================================================================================================================================

String fagNavn(Fag fag) {
  // Laget av: 
  // TODO: Returner navnet på faget som lesbar tekst til Serial Monitor
  // Tips: Bruk switch/case akkurat som i fagFarge(), med en tekststreng per fag:
  //       case MATTE: return "Matematikk";
  //       case ENOGSTYR: return "Energi og styresystemer";
  // Tips: Husk et default-case for ukjente fag
  switch (fag) {
    case INGENTING: return "Fri / Ingen time";
    case FRIMINUTT: return "Friminutt";
    default:        return "Fag-id " + String(fag); // Placeholder - fyll inn fagnavn her!
  }
}

//==================================================================================================================================

void blinkLED(uint32_t farge, int antallBlink) {
  // Laget av: 
  // TODO: Blink hele ringen "antallBlink" ganger med fargen "farge"
  // Tips: strip.fill(farge) fyller alle LEDs, strip.clear() slår dem av
  // Tips: Husk strip.show() etter hver endring, og en kort delay() mellom av/på
}

//==================================================================================================================================

void timeStartAnimasjon(uint32_t fagfarge) {
  // Laget av: 
  // TODO: Vis en kort animasjon når en ny time starter, i fagets farge
  // Input: fagfarge er fargen til faget som nettopp startet
  // Tips: F.eks. la fargen "vokse" ut fra ett punkt, eller fyll ringen gradvis
}

//==================================================================================================================================

void friminuttAnimasjon(int minutt, int index){
  // Laget av: 
  // TODO: Vis en animasjon i friminuttet som viser hvor mye tid som er igjen
  // Input: minutt er gjeldende minutt, index er raden i plan[] for friminuttet
  if(index == -1){return;}

  // Tips: plan[index].startMinutt og plan[index].varighet forteller når friminuttet startet/slutter
  // Tips: Bruk map() for å regne om et tidspunkt til en LED-posisjon (0 til NUM_LEDS)
}


//==================================================================================================================================

// Hjelpefunksjoner for klokkevisere (disse er ferdig laget og kan brukes direkte i visKlokkevisere):
int time_viser(int time, int minutt) {
  int t_min = (time % 12) * 60;
  int time_pix = ((t_min + minutt) * NUM_LEDS) / 720;
  return time_pix % NUM_LEDS;
}

int minutt_viser(int minutt, int sekund) {
  int min_pix = ((minutt * 60 + sekund) * NUM_LEDS) / 3600;
  return min_pix % NUM_LEDS;
}

int sekund_viser(int sekund) {
  float total = (sekund % 60) + (millis() % 1000) / 1000.0;
  int sek_pix = (int)((total * NUM_LEDS) / 60);
  return sek_pix % NUM_LEDS;
}

void visKlokkevisere(int time, int minutt, int sec) {
  // Laget av: 
  // TODO: Tegn time-, minutt- og sekundviseren på ringen
  // Input: time (0-23), minutt (0-59), sec (0-59)
  // NB: strip.clear() og strip.show() håndteres automatisk i loop() - ikke kall dem her!
  // Tips: Du kan bruke de ferdige hjelpefunksjonene over for å finne LED-indeksene:
  //       int pTime = time_viser(time, minutt);
  //       int pMin  = minutt_viser(minutt, sec);
  //       int pSek  = sekund_viser(sec);
  // Tips: strip.setPixelColor(pixel, farge) tegner én piksel om gangen (f.eks. rød timeviser, blå minuttviser, hvit sekundviser)
}

//==================================================================================================================================

void nedtellingBar(int index, int sekunderIgjen, uint32_t fagfarge) {
  // Laget av: 
  // TODO: Tegn en "bue" av LEDs som viser hvor mye tid som er igjen av gjeldende aktivitet
  // Input: index er raden i plan[], sekunderIgjen er tid igjen, fagfarge er fargen som skal brukes
  // NB: strip.clear() og strip.show() håndteres automatisk i loop() - ikke kall dem her!
  if(index == -1){return;}

  // Tips: Bruk plan[index].varighet * 60 for å finne total varighet i sekunder
  // Tips: map() kan regne om sekunderIgjen til en LED-posisjon (0 til NUM_LEDS)
}

//==================================================================================================================================

void melodiSpiller(int note[], int varighet[], int antallToner) {
  // Laget av: 
  // TODO: Spill av "antallToner" toner fra "note" med tilhørende varighet fra "varighet"
  // Input: note[] er frekvenser (Hz), varighet[] er hvor lenge hver tone skal spilles (ms)
  // Tips: Bruk tone(soundpin, note[i], varighet[i]) for hver tone i en for-løkke (i fra 0 til antallToner-1)
  // Tips: Legg gjerne inn en kort delay() mellom tonene også, slik at de ikke flyter sammen
  // Tips: IKKE bruk sizeof(note) her - arrays som sendes til funksjoner "råtner" til pekere, så det gir feil svar
}


void spillMelodi(int melodiNr) {
  // Laget av: 
  // TODO: Implementer denne funksjonen
  // Input: melodiNr er melodinummer (1=friminutt, 2=time, etc.)
  // Spill en melodi (kan være tom implementasjon hvis ingen buzzer)
  
  // TIPS til implementering - ALTERNATIV 1 (med buzzer):
  // - Bruk tone(soundpin, frekvens, varighet) eller kall melodiSpiller(melodi, melodi_varighet, 3)
  // - Friminutt: Glad melodi (høye toner)
  // - Time: Nøytral tone (middels toner)
  //
  // TIPS til implementering - ALTERNATIV 2 (uten buzzer):
  // - Bruk LED-signaler i stedet for lyd
  // - Friminutt: blinkLED(strip.Color(0, 255, 0), 3) // Grønn
  // - Time: blinkLED(strip.Color(255, 0, 0), 2) // Rød
  // - Lag forskjellige blinkmønstre for hvert melodiNr
  
  // Placeholder - velg alternativ og implementer!
}



//==================================================================================================================================

void ferdigForDagenAnimasjon() {
  // Laget av: 
  // TODO: Vis en rolig animasjon som markerer at skoledagen er ferdig
  // Tips: F.eks. en myk fade inn/ut med strip.fill() og strip.show()
  // Tips: strip.Color(r, g, b) lager fargen, delay() styrer hastigheten
}

//==================================================================================================================================

void helgeSluttAnimasjon() {
  // Laget av: 
  // TODO: Implementer denne funksjonen
  // Vis en spektakulær animasjon når siste time på fredag er ferdig (Maks 30 sekunder)
  
  // TIPS til implementering:
  // - Dette er den store celebrasjonen - vær kreativ og spektakulær!
  // - Kombiner flere effekter: fyrverkeri, regnbuer, puls, rotasjoner
  // - Bruk alle 30 sekunder for en episk opplevelse
  // - Start rolig og bygg opp til klimaks
  // - Eksempel: Fyrverkeri → regnbue → feiring → rolig slutt
  // - Bruk math-funksjoner for smooth overganger
  // - Dette er eleven sin sjanse til å virkelig skinne!
  
  // Placeholder - implementer en episk helgesluttanimasjon!
}

//==================================================================================================================================

void fyllPlan() {
  // Laget av: 
  // TODO: Fyll inn hele ukeplanen med plan[indeks] = {dag, startTime, startMinutt, varighet, fag};
  // Tips: Bruk egne indeks-serier per dag, f.eks. mandag = 0-9, tirsdag = 10-19, osv.
  // Tips: Det er OK å ha hull i listen! Ikke alle indekser trenger å brukes.

  // Eksempel (mandag, første time kl. 08:00 i 45 minutter, i faget MATTE):
  plan[0] = {MANDAG, 8, 0, 45, MATTE};

  // Eksempel (onsdag kl. 09:15 i 60 minutter, i faget ELKRETSER - aktiv under dummytid kl. 09:30):
  plan[1] = {ONSDAG, 9, 15, 60, ELKRETSER};

  // TODO: Legg til resten av timeplanen for hele uken her...
}

//==================================================================================================================================

Fag hentGjeldendeFag(int index) {
  // Laget av: 
  // TODO: Returner faget som står i plan[index]
  // Tips: Husk å sjekke om index er -1 (ingen time nå) og returner INGENTING i så fall
  return INGENTING; // Placeholder
}

//==================================================================================================================================

int beregnTidIgjen(int index, int time, int minutt, int sekund) {
  // Laget av: 
  // TODO: Regn ut hvor mange sekunder som er igjen av aktiviteten i plan[index]
  // Input: index er raden i plan[], time/minutt/sekund er klokkeslettet akkurat nå
  if (index == -1) { return 0; }

  // Tips: Gjør om både "nå" og "når timen slutter" til sekunder fra midnatt og ta differansen:
  //       int naSek = time * 3600 + minutt * 60 + sekund;
  //       int sluttSek = plan[index].startTime * 3600 + (plan[index].startMinutt + plan[index].varighet) * 60;
  //       return max(0, sluttSek - naSek);
  return 0; // Placeholder
}

//==================================================================================================================================

int planIndex(int ukedag, int time, int minutt) {
  // Laget av: 
  // TODO: Finn og returner indeksen i plan[] som matcher gjeldende ukedag/time/minutt
  // Input: ukedag (se enum Ukedag), time (0-23), minutt (0-59)
  // Output: Indeksen (0-49) til riktig rad i plan[], eller -1 hvis ingen time pågår nå
  // Tips: Gjør om klokkeslettet til minutter fra midnatt: int naMin = time * 60 + minutt;
  // Tips: Løp gjennom plan[] (fra 0 til antallTimer - 1). For hver rad der plan[i].dag == ukedag og plan[i].fag != INGENTING:
  //       int startMin = plan[i].startTime * 60 + plan[i].startMinutt;
  //       int sluttMin = startMin + plan[i].varighet;
  //       Sjekk om naMin er fra og med startMin og mindre enn sluttMin. Returner da i!
  return -1; // Placeholder - "ingen time akkurat nå"
}

//==================================================================================================================================

bool hentInternetTid() {
  // Laget av: Marcel & Luka
  int forsok = 0;
  const char* TZ_INFO = "CET-1CEST,M3.5.0/2,M10.5.0/3";

  // wifiMulti.run() skanner og kobler automatisk til beste tilgjengelige nettverk (Wokwi eller fysisk)
  while(wifiMulti.run() != WL_CONNECTED && forsok < 20) {
    delay(500);
    forsok++;
  }
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi-tilkobling mislyktes.");
    return false;
  }
  else {
    Serial.print("WiFi-tilkobling lyktes til: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP-adresse: ");
    Serial.println(WiFi.localIP());
    configTzTime(TZ_INFO, "pool.ntp.org");
    struct tm t;
    return getLocalTime(&t);
  }
  return false;
}

//==================================================================================================================================

void helgAnimasjon() {
  // Laget av: 
  // TODO: Implementer denne funksjonen
  // Lag en kul animasjon som vises i helgene
  
  // TIPS til implementering - Vær kreativ! Dette er din sjanse til å skinne:
  // - Regnbue-effekter: Bruk forskjellige farger som roterer
  // - Bouncing balls: Simuler en ball som spretter
  // - Fade-effekter: Fade inn/ut med forskjellige farger
  // - Roterende mønstre: Roter et mønster rundt ringen
  // - Stjernehimmel: Tilfeldige LEDs som blinker som stjerner
  // - Fyrverk-effekt: Eksplosjoner av farger
  // - Bruk math-funksjoner som sin(), cos() for smooth animasjoner
  // - Kombiner forskjellige effekter!
  // - Husk: ikke bruk for lange delays (animasjonen kalles hver loop)
  
  // Placeholder - vær kreativ og implementer din egen kule animasjon!
}

//==================================================================================================================================

void handterAktivitetsbytte(Fag nyttFag, int ukedag) {
  // Laget av: 
  // TODO: Sjekk om nyttFag er forskjellig fra den globale variabelen forrigeFag (da har vi byttet aktivitet)
  // TODO: Sett riktig status-flagg (ferdigForDagen, nyttFriminutt eller nyTime) og spill riktig melodi med spillMelodi()
  // Tips: Hvis nyttFag == INGENTING og forrigeFag != INGENTING: skoledagen er slutt!
  //       - Hvis ukedag == FREDAG: kall helgeSluttAnimasjon()
  //       - Ellers: sett ferdigForDagen = true
  // Tips: Hvis nyttFag == FRIMINUTT: sett nyttFriminutt = true og kall spillMelodi(1)
  // Tips: Hvis nyttFag != INGENTING og nyttFag != FRIMINUTT: sett nyTime = true og kall spillMelodi(2)
  // TODO: Husk å oppdatere forrigeFag = nyttFag til slutt!
}

//==================================================================================================================================

void visGjeldendeStatus(int index, int minutt) {
  // Laget av: 
  // TODO: Sjekk status-flaggene (ferdigForDagen, nyttFriminutt, nyTime) og vis riktig animasjon
  // Tips: Sjekk flaggene i rekkefølge med if / else if:
  //       - Hvis ferdigForDagen: kall ferdigForDagenAnimasjon() og nullstill flagget (ferdigForDagen = false;)
  //       - Hvis nyttFriminutt:  kall friminuttAnimasjon(minutt, index) og nullstill flagget (nyttFriminutt = false;)
  //       - Hvis nyTime:         kall timeStartAnimasjon(fagFarge(gjeldendeFag)) og nullstill flagget (nyTime = false;)
}

//==================================================================================================================================
// ========== EKSTRA / VALGFRIE FUNKSJONER ==========
// Disse er valgfrie tilleggsoppgaver - se ELEVOPPGAVER.md for beskrivelse, hint og vanskelighetsgrad.
//==================================================================================================================================

void startNedtelling(uint32_t farge, int minutt, int sekund) {
  // Laget av: 
  // TODO: Lag en blokkerende nedtellingstimer som tar over hele ringen
  // Input: farge er fargen ringen skal telle ned i, minutt/sekund er hvor lang tid som skal telles ned
  // Tips: Regn ut totalt antall sekunder: int totalSek = minutt * 60 + sekund;
  // Tips: Bruk en løkke som teller ned ett sekund om gangen med delay(1000), og regn ut hvor mange
  //       LEDs som skal være tent akkurat nå (f.eks. med map()) basert på hvor mange sekunder som er igjen.
  // Tips: Sjekk Serial.available() i hver runde av løkken - hvis brukeren skriver "stopp", avbryt løkken tidlig.
  // Tips: Kall f.eks. blinkLED(farge, 5) helt til slutt for å markere at nedtellingen er ferdig (hopp over dette ved avbrytelse).
  // Tips: Husk strip.clear() + strip.show() før funksjonen returnerer.
}

//==================================================================================================================================

void spillAnimasjon(uint32_t farge, int sekunder) {
  // Laget av: 
  // TODO: Vis en fri, selvvalgt animasjon i "farge" som varer i omtrent "sekunder" sekunder
  // Tips: Dette er din egen frie oppgave - kombiner gjerne effekter du har sett i andre animasjoner
  //       (fade, rotasjon, blink), men bruk parameterne til å style farge og varighet.
}

//==================================================================================================================================

void startStoppeklokke(uint32_t farge) {
  // Laget av: 
  // TODO: Lag en blokkerende stoppeklokke som teller oppover til brukeren avbryter den
  // Input: farge er fargen "viseren" skal ha
  // Tips: Bruk en uendelig løkke (f.eks. while(true)) som hvert sekund flytter en tent LED ett hakk videre
  //       rundt ringen (bruk % NUM_LEDS for å håndtere at den går en runde og starter på nytt)
  // Tips: Sjekk Serial.available() hver runde - hvis brukeren skriver "stopp", avbryt løkken
  // Tips: Skriv ut totalt antall sekunder som gikk til Serial når løkken avbrytes
  // Tips: Husk strip.clear() + strip.show() før funksjonen returnerer
}

//==================================================================================================================================

bool knappTrykket() {
  // Laget av: 
  // TODO: Les av den fysiske knappen på BUTTON_PIN og returner true KUN én gang per trykk (ikke hver loop mens den holdes inne)
  // Krever kabling: se koblingstabellen i HARDWARE.md
  // Tips: digitalRead(BUTTON_PIN) er LOW når knappen er trykket inn (siden vi bruker INPUT_PULLUP)
  // Tips: Bruk en static bool for å huske om knappen var nede forrige gang du sjekket, slik at du
  //       kun returnerer true på selve overgangen fra "ikke trykket" til "trykket" (debouncing)
  return false; // Placeholder - knappen er "aldri trykket"
}

//==================================================================================================================================

// Hjelpetabell for RTTTL-toner (ferdig laget, kan brukes direkte i spillRTTTL):
// Rekkefølge: c, c#, d, d#, e, f, f#, g, g#, a, a#, b (frekvenser for oktav 4)
int noteFrekvenser[12] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

int rtttlFrekvens(int noteIndeks, int oktav) {
  // Ganger/deler grunnfrekvensen med 2 for hver oktav opp/ned fra oktav 4
  return noteFrekvenser[noteIndeks] * pow(2, oktav - 4);
}

void spillRTTTL(String sang) {
  // Laget av: 
  // TODO: Parse en RTTTL-ringetonestreng og spill den av med tone()
  // Input: sang er en RTTTL-streng på formatet "Navn:d=4,o=5,b=125:8c,8d,8e,2f" (navn:standardverdier:noter)
  // Tips: Del strengen opp med sang.indexOf(':') og substring() for å skille navn/standardverdier/noter
  // Tips: Del opp notedelen med komma (','), og hver enkelt note i varighet+tone(+#)+oktav, f.eks. "8c" = 1/8 note, tonen C
  // Tips: Bruk noteFrekvenser[] og rtttlFrekvens(indeks, oktav) rett over denne funksjonen til å slå opp frekvensen for hver tone
  // Tips: tone(soundpin, frekvens, varighetMs) spiller tonen - legg inn en kort delay/pause mellom hver note
}

//==================================================================================================================================
// EKSTRA STOR OPPGAVE (krever samarbeid, se ELEVOPPGAVER.md): Web-grensesnitt via nettleser.
// Kan først startes når visMeny() og sjekkSerialMeny() er ferdig implementert.
//==================================================================================================================================

void settOppWebserver() {
  // Laget av: 
  // TODO: Sett opp og start webserveren (kalles én gang fra setup(), etter at WiFi er koblet til)
  // Tips: #include <WebServer.h> øverst i fila, og lag et globalt objekt: WebServer server(80);
  // Tips: Definer ruter med server.on("/", handlerFunksjon), og kall til slutt server.begin()
}

void handterWebKlient() {
  // Laget av: 
  // TODO: Håndter innkommende nettleser-forespørsler (kalles hver loop())
  // Tips: Dette blir stort sett bare ett enkelt kall til server.handleClient(), forutsatt at
  //       settOppWebserver() har definert rutene riktig
}

String genererMenyHTML() {
  // Laget av: 
  // TODO: Bygg og returner en HTML-streng som viser de samme valgene som visMeny() viser på Serial
  // Tips: Bygg opp en String med vanlig HTML (<html><body><ul><li>...</li></ul></body></html>)
  // Tips: Gjenbruk gjerne samme tekster/valg som du skrev i visMeny()
  return "<html><body><h1>TODO: Lag menyen din her!</h1></body></html>"; // Placeholder
}



