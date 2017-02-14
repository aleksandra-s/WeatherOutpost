// ALEKSANDRA
/* ESP functions/module */

// DONE WHEN CHIPKIT IS TURNED ON
// Initialize UART registers, check that ESP-01 communication is up.
// Send AT, connected if returns OK, then return true. Else false.
char check_esp_connect();

// CALLED BY STATE MODULE WHEN USER CHOOSES WIFI IN MAIN MENU
// List all APs and return list as char array (send AT+CWMODE=1 to set wifi mode 
// then AT+CWLAP to list APs, fill char array with list, count up as filled and 
// set first element in array as number of APs (count))
// If count == 0, no APs
// If char* == null, problem w/ getting APs
char* list_aps(); // global char*? SSID have max 32 char
 
// CALLED BY STATE MODULE WHEN USER CHOOSES AP IN WIFI MENU AND KEYS IN PASSWORD
// Takes in array with SSID and password, send AT+CWJAP="SSID","pword", if returns
// FAIL, return false, else return true
// Send AT+CWJAP? to find whether the ESP is connected to a network- if an AP is
// returned, return true. Else, false.
char connect_to_ap(char* ssid, char* pwrd);

// CALLED BY STATE MODULE TO VERIFY WHETHER CONNECTION WAS SUCCESSFUL
// Send AT+CWJAP? to find whether the ESP is connected to a network- if an AP is
// returned, return true. Else, false.
char verify_ap_connection();

// CALLED BY STATE MODULE WHEN USER SELECTS CITY
// 

// dummy functions

/* State module */

/* LCD module */

/* Buttons module (incl. ISR) */
