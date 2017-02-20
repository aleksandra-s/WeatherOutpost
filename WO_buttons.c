#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include "WO_buttons.h"

void initialize_buttons(void){};

int getbtns(void){
	int buttonData = ((PORTD >> 5) & 0x7);
	return buttonData;
}
