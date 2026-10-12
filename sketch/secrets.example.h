#pragma once

// ==============================================================================
// NETTVERKSKONFIGURASJON FOR KLOKKEPROSJEKT (MAL / EKSEMPEL)
// ==============================================================================
// Denne filen er en mal som kan sjekkes inn på GitHub.
// 
// Slik bruker du den for ditt eget fysiske nettverk:
// 1. Kopier denne filen og lagre kopien som "secrets.h" i samme mappe (sketch/).
// 2. Fyll inn ditt eget nettverksnavn (SSID) og passord under.
// 3. Filen "secrets.h" er registrert i .gitignore og vil ALDRI havne på GitHub!
//
// Merk: I Wokwi-simulatoren trengs ikke secrets.h – koden kobler seg automatisk
// til det virtuelle "Wokwi-GUEST"-nettverket hvis secrets.h mangler eller ikke er innen rekkevidde.
// ==============================================================================

// Navn og passord for det fysiske WiFi-nettverket i klasserommet / labben:
#define FYSISK_WIFI_SSID "DittSkoleNettverk"
#define FYSISK_WIFI_PASS "DittHemmeligePassord"

// Valgfritt: Fast/statisk IP for ESP32 i labben
// Sett BRUK_STATISK_IP til true hvis du vil overstyre DHCP og tildele fast IP i koden:
#define BRUK_STATISK_IP false
#define STATISK_IP      192, 168, 1, 50
#define STATISK_GATEWAY 192, 168, 1, 1
#define STATISK_SUBNET  255, 255, 255, 0
#define STATISK_DNS     8, 8, 8, 8

