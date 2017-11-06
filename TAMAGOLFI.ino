/* 
 * Tamagolfi
 * Version INDEV
 * developed by ???
 * 2017
 */

// Imports.
#include "gvar.h"
#include "spr.h"
#include "snd.h"
#include "func.h"
#include "draw.h"
#include "run.h"

// Setup.
void setup() {
  ardu.begin();
  ardu.setFrameRate(60);
  snd.volumeMode(VOLUME_ALWAYS_HIGH);
}

// Loop.
void loop() {
  if (ardu.nextFrame()) {
    ardu.pollButtons();
    Run();
    Draw();
  }
}
