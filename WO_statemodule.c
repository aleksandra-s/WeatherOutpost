#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
//#include "mipslab.h"  /* Declatations for these labs */
#include "WO_ESPheader.h" /* Declarations of functions controlling ESP-01 */
#include "WO_LCDheader.h" /* Declarations of display functions for LCD */
#include "WO_buttons.h" /* Declarations of I/O button functions and ISR*/

#define MAIN_MENU_TOTAL 2
#define MAIN_MENU_WIFI 0
#define MAIN_MENU_CITIES 1

const char *mainMenuStrings[MAIN_MENU_TOTAL];
mainMenuStrings[MAIN_MENU_WIFI] = "Wifi";
mainMenuStrings[MAIN_MENU_CITIES] = "Cities";

// Declare global variables

char g_menu[10][10];
volatile int* porte = (volatile int*) 0xbf886110;

void die(int deathValue){
	*porte = deathValue;
	while(1);
}	



int main(void) {
	
	int state = 0;
	int menuIndex = 0;
	
	// Initialize LCD and buttons (i.e. set correct registers, done in LCD and button modules)

	initialize_LED();
	initialize_buttons();
	initialize_LCD();

	// Before anything is displayed, check that the ESP-01 is connected to chipkit
	
	if (check_esp_connect() == 0){
		char espNotConnectedAlert[] = "ESP-01 not connected";
		display_string(1,espNotConnectedAlert); // Alert the user of issue w ESP connection 
											// (Display function declarations unclear, 
											// for now I am using a mix of my own dummy
											// functions and implemented ones that I can understand)
	}
											
	while(1){
		
		switch(state){
			case 0 : // zero state
			
			// Display main menu
			display_menu(mainMenuStrings, MAIN_MENU_TOTAL); // I guess should be navigate, have to see if Tatus understands it (statemodule.c))
															// also can we please call this something better than navigate
			put_cursor_index(menuIndex);
			
			state = 1;
			break;
			
			case 1 : // first state
				
			// Allow user to navigate and select next menu (should be wifi, but up to them I guess ¯\_(ツ)_/¯ )


			if(get_btns() & 0x2){ // if button 2 is pressed, cursor moves downwards
				menuIndex++;
				if(menuIndex >= MAIN_MENU_TOTAL){
					menuIndex = 0;
				}
				put_cursor_index(menuIndex);
			}
	
			if(get_btns() & 0x1){ // if button 1 is pressed, cursor moves upwards
				if(menuIndex == 0){
					menuIndex = MAIN_MENU_TOTAL;
				}
				menuIndex--;
				put_cursor_index(menuIndex);
			}

			if(get_btns() & 0x4){ // if button 4 is pressed 
				switch(menuIndex){
		
				case MAIN_MENU_WIFI :
				state = 2; //wifi menu state
				break;
		
				case MAIN_MENU_CITIES :
				state = 3; //city menu state
				break;
			}
			break;
			
			case 2 :
				
			break;
			
		}




	}
	
	return 0;
}	


	
