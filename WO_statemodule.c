#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
//#include "mipslab.h"  /* Declatations for these labs */
#include "WO_ESPheader.h" /* Declarations of functions controlling ESP-01 */
#include "WO_LCDheader.h" /* Declarations of display functions for LCD */
#include "WO_buttons.h" /* Declarations of I/O button functions and ISR*/

#define MAIN_MENU 1
#define WIFI_MENU 3 // Needs to be changed, discuss with Kyle
#define CITY_MENU 2

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

void initialize_LED(){
	volatile int* trise = (volatile int*) 0xbf886100; 
    *trise = *trise & ~0xff; // set LEDs to output (initialize 8 lsb of Port E to outputs)
	//volatile int* porte = (volatile int*) 0xbf886110;
	*porte = *porte | 0x0; // LEDs begin by showing value 0 (initialize value of Port E to 0) 
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
/*

// Display main menu

display_menu(MAIN_MENU); // I guess should be navigate, have to see if Tatus understands it (statemodule.c))
						 // also can we please call this something better than navigate

// Allow user to navigate and select next menu (should be wifi, but up to them I guess ¯\_(ツ)_/¯ )
// Need a while loop to keep this up?


if(get_btns() & 0x2){ // if button 2 is pressed, cursor moves downwards
	navigate_cursor_down();
 }
	
if(get_btns() & 0x1){ // if button 1 is pressed, cursor moves upwards
	navigate_cursor_up();
}

if(get_btns() & 0x4){ // if button 4 is pressed 
	switch(g_currentLine){
		
		case 0 :
		display_menu(CITY_MENU);
		break;
		
		case 1 :
		display_menu(WIFI_MENU);
		break;
		
		
}
	
*/


	