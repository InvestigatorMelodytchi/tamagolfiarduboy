// Definition.
#ifndef DRAW_H
#define DRAW_H

// Drawing name on the select screen.
void DrawCharName() {
	switch(varMenuChoice) {
		// Mero.
		case 0: spr.drawErase(33, 52, sprCharFont, 12); spr.drawErase(39, 52, sprCharFont, 4); spr.drawErase(45, 52, sprCharFont, 11); spr.drawErase(51, 52, sprCharFont, 14); spr.drawErase(57, 52, sprCharFont, 3); spr.drawErase(63, 52, sprCharFont, 24); spr.drawErase(70, 52, sprCharFont, 19); spr.drawErase(77, 52, sprCharFont, 2); spr.drawErase(83, 52, sprCharFont, 7); spr.drawErase(89, 52, sprCharFont, 8); break;
		
		// Makiko.
		case 1: spr.drawErase(46, 52, sprCharFont, 12); spr.drawErase(52, 52, sprCharFont, 0); spr.drawErase(58, 52, sprCharFont, 10); spr.drawErase(64, 52, sprCharFont, 8); spr.drawErase(70, 52, sprCharFont, 10); spr.drawErase(76, 52, sprCharFont, 14); break;
			
		// Anemoriritchi.
		case 2: spr.drawErase(23, 52, sprCharFont, 0); spr.drawErase(29, 52, sprCharFont, 13); spr.drawErase(35, 52, sprCharFont, 4); spr.drawErase(41, 52, sprCharFont, 12); spr.drawErase(47, 52, sprCharFont, 14); spr.drawErase(53, 52, sprCharFont, 17); spr.drawErase(59, 52, sprCharFont, 8); spr.drawErase(65, 52, sprCharFont, 17); spr.drawErase(71, 52, sprCharFont, 8); spr.drawErase(77, 52, sprCharFont, 19); spr.drawErase(84, 52, sprCharFont, 2); spr.drawErase(90, 52, sprCharFont, 7); spr.drawErase(96, 52, sprCharFont, 8); break;
			
		// Kiramotchi.
		case 3: spr.drawErase(33, 52, sprCharFont, 10); spr.drawErase(39, 52, sprCharFont, 8); spr.drawErase(45, 52, sprCharFont, 17); spr.drawErase(51, 52, sprCharFont, 0); spr.drawErase(57, 52, sprCharFont, 12); spr.drawErase(63, 52, sprCharFont, 14); spr.drawErase(69, 52, sprCharFont, 19); spr.drawErase(76, 52, sprCharFont, 2); spr.drawErase(82, 52, sprCharFont, 7); spr.drawErase(88, 52, sprCharFont, 8); break;
			
		// Chamametchi.
		case 4: spr.drawErase(30, 52, sprCharFont, 2); spr.drawErase(36, 52, sprCharFont, 7); spr.drawErase(42, 52, sprCharFont, 0); spr.drawErase(48, 52, sprCharFont, 12); spr.drawErase(54, 52, sprCharFont, 0); spr.drawErase(60, 52, sprCharFont, 12); spr.drawErase(66, 52, sprCharFont, 4); spr.drawErase(72, 52, sprCharFont, 19); spr.drawErase(79, 52, sprCharFont, 2); spr.drawErase(85, 52, sprCharFont, 7); spr.drawErase(91, 52, sprCharFont, 8); break;
			
		// Watawatatchi.
		case 5: spr.drawErase(26, 52, sprCharFont, 22); spr.drawErase(32, 52, sprCharFont, 0); spr.drawErase(38, 52, sprCharFont, 19); spr.drawErase(45, 52, sprCharFont, 0); spr.drawErase(51, 52, sprCharFont, 22); spr.drawErase(57, 52, sprCharFont, 0); spr.drawErase(63, 52, sprCharFont, 19); spr.drawErase(70, 52, sprCharFont, 0); spr.drawErase(76, 52, sprCharFont, 19); spr.drawErase(84, 52, sprCharFont, 2); spr.drawErase(90, 52, sprCharFont, 7); spr.drawErase(96, 52, sprCharFont, 8); break;
			
		// Mamametchi.
		case 6: spr.drawErase(33, 52, sprCharFont, 12); spr.drawErase(39, 52, sprCharFont, 0); spr.drawErase(45, 52, sprCharFont, 12); spr.drawErase(51, 52, sprCharFont, 0); spr.drawErase(57, 52, sprCharFont, 12); spr.drawErase(63, 52, sprCharFont, 4); spr.drawErase(69, 52, sprCharFont, 19); spr.drawErase(76, 52, sprCharFont, 2); spr.drawErase(82, 52, sprCharFont, 7); spr.drawErase(88, 52, sprCharFont, 8); break;
	}
}

// Drawing.
void Draw() {
	// Clearing.
	ardu.clear();
	ardu.fillScreen(WHITE);
	
	// State switching.
	switch(gameState) {
		// Logo.
		case STATE_LOGO:
			break;
		
		// Title screen.
		case STATE_TITLE:
			spr.drawErase(13, 0, sprTitleName, 0);
			spr.drawErase(0, 24, sprTitleMero, 0);
			spr.drawErase(88, 32, sprTitleMenu, (uint8_t)varMenuChoice);
			break;
			
		// Help.
		case STATE_HELP:
			spr.drawErase(39, 7, sprHelpQr, 0);
			break;
		
		// Character select.
		case STATE_CHAR:
			DrawCharName();
			spr.drawErase(67, 3, sprCharStatbox, 0);
			spr.drawErase(97, 8, sprCharStatbar, (uint8_t)pgm_read_word(&statChar[(uint8_t)varPlayerChar * 4]) - 1);
			spr.drawErase(97, 16, sprCharStatbar, (uint8_t)pgm_read_word(&statChar[((uint8_t)varPlayerChar * 4) + 1]) - 1);
			spr.drawErase(97, 24, sprCharStatbar, (uint8_t)pgm_read_word(&statChar[((uint8_t)varPlayerChar * 4) + 2]) - 1);
			spr.drawErase(97, 32, sprCharStatbar, (uint8_t)pgm_read_word(&statChar[((uint8_t)varPlayerChar * 4) + 3]) - 1);
			ardu.fillRect(0, 48, 128, 2, BLACK);
			if (!varMenuLocked) {
				spr.drawErase(1 + varGameAnimFrame, 52, sprCharArrow, 0);
				spr.drawErase(121 - varGameAnimFrame, 52, sprCharArrow, 1);
			}
			spr.drawErase(0, 9 - varGameAnimFrame, GetPortraitSprite(), 0);
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
	
	// Finalizing.
	ardu.display();
}

// End.
#endif