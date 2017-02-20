
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "master.h"  /* Declarations for all functions and data */


void processButtons(int buttonPress, volatile int *currentline,volatile int *currentmenu)
	{
	if(buttonPress & 0x4)// Button 4
			{
	   	navigate(currentline, currentmenu);
			}
	if(buttonPress & 0x2) // button 2
		  {
			move_cursor(1,currentline);
 			}
	if(buttonPress & 0x1) // button 1
			{
			move_cursor(-1,currentline);
			}
}


void navigate(volatile int *currentline,volatile int *currentmenu)
	{


	if(*currentmenu == 0)
		{
    select_line(*currentline, currentmenu);
		}

	else if(*currentmenu == 1) //This is the cities screen. Index line 4 is back. All else calls ESP
		{
		select_line(*currentline + 4, currentmenu);
	  }

	else if(*currentmenu == 2)
		{
		select_line(*currentline + 8, currentmenu);
		}

	PORTE = *currentmenu;
	clear_line(currentline);
  return;
	}



void select_line(int currentline, volatile int *currentmenu)
  {
  switch(currentline)
    {

			// home menu options *************************************
    case 0:
      {
      display_menu(1);//menu 1 is the list of cities to choose from.
      *currentmenu = 1;
      return;
      }
    case 1:
      {
      *currentmenu = 2;
      display_menu(2);//This is the wifi options menu.
      return;
      }
    case 2:
			{
      *currentmenu = 0;
      display_menu(0);
      return;
			}
    case 3:
      {
      *currentmenu = 0;
      display_menu(0);
      return;
      }



			// City menu options ************************************
		case 4:
			{
				display_menu(1);//Unimplemented
				*currentmenu = 1;
				return;
			}
		 case 5:
		 {
			display_menu(1);//Unimplemented
 			*currentmenu = 1;
  	  return;

 		 }
		 case 6:
		 {
			display_menu(1);//Unimplemented
			*currentmenu = 1;
 			return;
 		 }
		 case 7:
		 {
			display_menu(0);//back function
			*currentmenu = 0;
			return;
		 }



		 // Wifi menu options **************************************
		 case 8:
		 {
		  display_menu(2);//Unimplemented
 		  *currentmenu = 2;
 			return;
 		 }
		 case 9:
		 {
			 display_menu(2);//Unimplemented
			 *currentmenu = 2;
 			return;
 		 }
		 case 10:
		 {
			 display_menu(2);//Unimplemented
			 *currentmenu = 2;
			return;
		 }
		 case 11:
		 {
			display_menu(0);//back function
			*currentmenu = 0;
			return;
		 }

    }
  }
