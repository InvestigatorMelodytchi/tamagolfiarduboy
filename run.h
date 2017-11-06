// Definition.
#ifndef RUN_H
#define RUN_H

// Running the game.
void Run() {
	// Global animation clock.
	if (varGameAnimClock > 0) {varGameAnimClock--;}
	else {
		varGameAnimClock = 30;
		varGameAnimFrame = (1 - varGameAnimFrame);
	}
	
	// General wait timer.
	if (varWaitTimer > 0) {varWaitTimer--;}
	
	// State switching.
	switch(gameState) {
		// Logo.
		case STATE_LOGO:
			break;
		
		// Title screen.
		case STATE_TITLE:
			if (ardu.justPressed(UP_BUTTON) || ardu.justPressed(DOWN_BUTTON)) {snd.tones(sndGenSelect); varMenuChoice = (1 - varMenuChoice);}
			else if (ardu.justPressed(B_BUTTON)) {
				if (varMenuChoice == 0) gameState = STATE_CHAR;
				else gameState = STATE_HELP;
				snd.tones(sndGenConfirm);
				varMenuChoice = 0;
			}
			break;
			
		// Help.
		case STATE_HELP:
			if (ardu.justPressed(A_BUTTON) || ardu.justPressed(B_BUTTON)) {gameState = STATE_TITLE; varMenuChoice = 1; snd.tones(sndGenCancel);}
			break;
		
		// Character select.
		case STATE_CHAR:
			if (!varMenuLocked) {
				if (ardu.justPressed(A_BUTTON)) {gameState = STATE_TITLE; varMenuChoice = 0; snd.tones(sndGenCancel);}
				if (ardu.justPressed(LEFT_BUTTON)) {if (varMenuChoice > 0) {varMenuChoice--;} else {varMenuChoice = 5;} snd.tones(sndGenSelect);}
				if (ardu.justPressed(RIGHT_BUTTON)) {if (varMenuChoice < 5) {varMenuChoice++;} else {varMenuChoice = 0;} snd.tones(sndGenSelect);}
				varPlayerChar = varMenuChoice;
			}
			break;
		
		// Gameplay.
		case STATE_GAME:
			break;
		
		// Scorecard.
		case STATE_SCORE:
			break;
		
		// Results.
		case STATE_END:
			break;
	}
	
	// End.
}

// End.
#endif