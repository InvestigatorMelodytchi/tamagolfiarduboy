// Definition.
#ifndef GVAR_H
#define GVAR_H

// Imports.
#include <Arduino.h>
#include <Arduboy2.h>
#include <ArduboyTones.h>

// Control objects.
Arduboy2Base ardu;
Sprites spr;
ArduboyTones snd(ardu.audio.enabled);

// Game state.
#define STATE_LOGO	0
#define STATE_TITLE	1
#define STATE_HELP	2
#define STATE_CHAR	3
#define STATE_GAME	4
#define STATE_SCORE	5
#define STATE_END	6
byte gameState = STATE_TITLE;

// Character stats.
PROGMEM const byte statChar[] = {3, 3, 3, 3, 3, 1, 5, 3, 4, 4, 3, 1, 2, 3, 4, 3, 2, 3, 3, 4, 1, 5, 1, 5, 5, 2, 2, 3};

// Logo variables.

// Menu variables.
byte varMenuChoice = 0;
byte varMenuLocked = 0;

// Gameplay variables.

// Scorecard variables.

// Results variables.

// Player variables.
byte varPlayerChar = 0;

// Misc. variables.
byte varGameAnimClock = 0;
byte varGameAnimFrame = 0;
byte varWaitTimer = 0;
byte varTemp;

// End.
#endif