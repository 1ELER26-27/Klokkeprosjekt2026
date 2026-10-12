#include "pitches.h"

#ifndef MELODY_H
#define MELODY_H

#include <Arduino.h>

/*
enum Fag {
  INGENTING = 0, FRIMINUTT, ELKRETSER, ENOGSTYR, NORSK, ENGELSK, MATTE, NATURFAG, GYM
};*/

struct duration {
 float notestopp;
 float pausestopp;
 int gjentakelser;
 int okningduration;
 int nestenote;
};

uint16_t melodyHelg[] {
  NOTE_G5, NOTE_A5, NOTE_D6, NOTE_A5,

  // resolution
  NOTE_G5, NOTE_A5, NOTE_D6, NOTE_G6
};

duration varighetHelg[] {
  {5, 0, 47, 1, 3}, {5, 0, 0, 0, -1}, {5, 0, 0, 0, -1}, {5, 0, 0, 0, -1},  
  // resolution: slows down and lands on a long G6
  {26, 0},  {24, 0},  {22, 0},  {20, 0}
};

uint16_t  melodyElkretser[] {
 NOTE_C5, NOTE_E5, NOTE_G5, NOTE_C5, 
 NOTE_F5, NOTE_A5, NOTE_C6, NOTE_C6, NOTE_D6, NOTE_C6
};
duration  varighetElkretser[] {
 {10, 0, 4, 0, 2}, {10, 0, 0, 0, -1}, {10, 0, 0, 0, -1}, {10, 0}, {10, 0, 4, 0, 2}, {10, 0, 0, 0, -1}, {10, 0, 0, 0, -1}, {20, 0}, {20, 0}, {2, 0} 
  };


uint16_t  melodyMatte[] {
  NOTE_E4, NOTE_FS4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_CS4, NOTE_B3, NOTE_A3, NOTE_B3, NOTE_CS4,
  NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C3, NOTE_AS3, NOTE_C3, NOTE_D4,
  NOTE_E4, NOTE_FS4, NOTE_A4, NOTE_FS4, NOTE_E4, NOTE_CS4, NOTE_B3, NOTE_A3, NOTE_B3, NOTE_CS4,
  NOTE_F4, NOTE_G4, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_C3, NOTE_AS3, NOTE_C3, NOTE_D4,
  NOTE_A4, NOTE_B4, NOTE_C4, NOTE_F4
};
int tid = 125;
int nedgang = 5;
int ganger = 21;

duration varighetMatte[] {
 {tid, 0, 20, -nedgang, 9}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1},  {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1}, {tid, 0, 0, 0, -1},
 {tid-(nedgang*ganger), 0, 3, 0, 9}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, 
 {tid-(nedgang*ganger), 0, 3, 1, 9}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1}, {tid-(nedgang*ganger), 0, 0, 0, -1},
 {tid-(nedgang*ganger)+8, 0, 3, -4, 9}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1}, {tid-(nedgang*ganger)+8, 0, 0, 0, -1},
 {tid-(nedgang*ganger)-8}, {tid-(nedgang*ganger)-11}, {tid-(nedgang*ganger)-12}, {tid-(nedgang*ganger)-19}    
};

uint16_t  melodyNorsk[] {
 NOTE_C4, NOTE_DS4, NOTE_G4, NOTE_B4,
 NOTE_F4, NOTE_DS4, NOTE_D4, NOTE_C4,
 NOTE_C4
};
duration varighetNorsk[] {
 {10, 0, 7, 0, 3}, {10, 0, 0, 0, -1}, {10, 0, 0, 0, -1}, {10, 0, 0, 0, -1},
 {12, 0, 3, -2, 3}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1},
 {1}
};

uint16_t  melodyEngelsk[] {
  NOTE_C4, NOTE_FS4, NOTE_DS4, NOTE_A4,
  NOTE_C4, NOTE_A4, NOTE_AS4, NOTE_GS4,
  NOTE_C4
};

duration varighetEngelsk[] {
  {10, 50, 7, 0, 3}, {10, 50, 0, 0, -1}, {10, 50, 0, 0, -1}, {10, 50, 0, 0, -1}, 
  {10, 50, 7, 0, 3}, {10, 50, 0, 0, -1}, {10, 50, 0, 0, -1}, {10, 50, 0, 0, -1}, 
  {2, 50}, 
};

uint16_t melodyGym[] {
 NOTE_B5, NOTE_B5
};

duration varighetGym[] {
 {5, 1, 3}, {0.2, 0},
};

uint16_t melodySluttdag[] {
NOTE_C4, NOTE_E4, NOTE_G4, NOTE_E4,
NOTE_F4, NOTE_A4, NOTE_C5, NOTE_A4,
NOTE_C5
};

duration varighetSluttdag[] {
 {5, 50, 3, 0, 3}, {5, 50, 0, 0, -1}, {5, 50, 0, 0, -1}, {5, 50, 0, 0, -1}, 
 {5, 50, 3, 0, 3}, {5, 50, 0, 0, -1}, {5, 50, 0, 0, -1}, {5, 50, 0, 0, -1},
 {1.5}
};

uint16_t melodyFriminutt[] {
NOTE_G4, NOTE_B4, NOTE_D4,
NOTE_A4, NOTE_D4, NOTE_C4,
NOTE_G4
};

duration varighetFriminutt[] {
 {14, 0, 4, 0, 2}, {14, 0, 0, 0, -1}, {14, 0, 0, 0, -1}, 
 {14, 0, 4, 0, 2}, {14, 0, 0, 0, -1}, {14, 0, 0, 0, -1},
 {2, 50}
};

uint16_t melodyNaturfag[] {
NOTE_C4, NOTE_D3, NOTE_E4, NOTE_F3, NOTE_G4, NOTE_A3, NOTE_B4, NOTE_C3,
NOTE_E4, NOTE_F3, NOTE_G4, NOTE_A3, NOTE_B4, NOTE_C3, NOTE_D4, NOTE_E3,
NOTE_C4

};

duration varighetNaturfag[] {
 {12, 0, 3, 0, 7}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1},
 {12, 0, 3, 0, 7}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1}, {12, 0, 0, 0, -1},
 {12}
};

#endif