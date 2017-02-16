//KYLE SINCLAIR

/*Button function and ISR*/
//'Header' file for I/O
//Describes what functions in other modules
//the main loop calls, with what paremters
//and what it expects returned. This header 
//file doesn't need to be included anywhere.
//It's sole purpose is to define this module's
//responsibilities and requirements




//ESP FUNCTION CALLS*******************************************************************************************

void display_wifi_networks()
  {
  
  }
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
// Send AT+CIPSTART="TCP","api.openweathermap.org",80
// Then AT+CIPSEND=119 (number may vary based on chosen city)
// And GET /data/2.5/weather?q=London,uk&units=metric&APPID=c2e01f5a4c6a50caf58fe4301f5a9e3d
// which will be filled with the correct city and country
char* (char* city, char* country, int return_info_length);



//BOOLEAN CHECK FUNCTIONS******************************************************************************************************

//This function returns true if communication with the
//ESP has been successfully established
char hasESP()
  {
  //return check_esp_connect
  }
//hasWifi returns true if the ESP has successfully connected to a wifi
//network
char hasWifi()
  {
 // return verify_ap_connection(); 
  }

//MENU NAVIGATION FUNCTIONS****************************************************************************************************
//This function will return the user to the main menu in the event that one of the boolean
//checks, such as hasWifi or hasESP returns false
void return_to_menu()
  {
  //call_update_menu with parameter 1;
  }
void update_menu(int currentMenu, int direction)
  {
  //selects appropriate starting position in the array (This array is stored in the data file)
  //then uses the display_menu functions to print out the strings contained in that portion ofthe array
  }




//SPECIFIC DISPLAY FUNCTIONS***************************************************************************************************


/* Buttons module (incl. ISR) */


//can we define arrays of menus and characters, complete with printing functions elsewhere?
