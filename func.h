// Getting portrait sprite.
char* GetPortraitSprite() {
	switch(varPlayerChar) {
		case 0: return(sprPortMero); break;
		case 1: return(sprPortMaki); break;
		default: return(sprBlank); break;
	}
}