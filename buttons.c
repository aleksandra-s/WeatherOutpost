//equivalent of time4io


int getbtns(void){
	int buttonData = ((PORTD >> 5) & 0x7);
	return buttonData;
}
