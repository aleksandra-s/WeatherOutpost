//equivalent of time4io
#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"


int getbtns(void){
	int buttonData = ((PORTD >> 5) & 0x7);
	return buttonData;
}
