#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <string.h>
#include <pic32mx.h>
#include "WO_ESPHeader.h"

// DONE WHEN CHIPKIT IS TURNED ON
// Initialize UART registers, check that ESP-01 communication is up.
// Send AT, connected if returns OK, then return true. Else false.
char check_esp_connect(){
	
	return 0;
}

// CALLED BY STATE MODULE WHEN USER CHOOSES WIFI IN MAIN MENU
// List all APs and return list as char array (send AT+CWMODE=1 to set wifi mode 
// then AT+CWLAP to list APs, fill char array with list, count up as filled and 
// set first element in array as number of APs (count))
// If count == 0, no APs
// If char* == null, problem w/ getting APs
char* list_aps(){
	return NULL; // global char*? SSID have max 32 char
} 
// CALLED BY STATE MODULE WHEN USER CHOOSES AP IN WIFI MENU AND KEYS IN PASSWORD
// Takes in array with SSID and password, send AT+CWJAP="SSID","pword", if returns
// FAIL, return false, else return true
// Send AT+CWJAP? to find whether the ESP is connected to a network- if an AP is
// returned, return true. Else, false.
char connect_to_ap(char* ssid, char* pwrd){
	return 0;
}

// CALLED BY STATE MODULE TO VERIFY WHETHER CONNECTION WAS SUCCESSFUL
// Send AT+CWJAP? to find whether the ESP is connected to a network- if an AP is
// returned, return true. Else, false.
char verify_ap_connection(){
	return 0;
}

// CALLED BY STATE MODULE WHEN USER SELECTS CITY
// Send AT+CIPSTART="TCP","api.openweathermap.org",80
// Then AT+CIPSEND=119 (number may vary based on chosen city)
// And GET /data/2.5/weather?q=London,uk&units=metric&APPID=c2e01f5a4c6a50caf58fe4301f5a9e3d
// which will be filled with the correct city and country
char* get_weather_info(char* city, char* country, int return_info_length){
	return NULL;
}