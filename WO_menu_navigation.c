
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declarations for these labs */
void navigate(volatile int *currentline,volatile int *currentmenu)
	{
    textbuffer[*currentline][12] = ' ';
		if(*currentmenu == 0)
			{
      select_line(currentline, currentmenu);
			}
		else if(*currentmenu != 0)
			{
			(*currentmenu)= 0;
			display_menu(1);
		  }

	*currentline = 0;
  PORTE = PORTE + *currentmenu;
	textbuffer[*currentline][12] = '*';
  return;
	}


void select_line(volatile int *currentline, volatile int *currentmenu)
  {
  switch(*currentline)
    {
    case 0:
      {
      display_menu(2);//menu 2 is the list of cities to choose from. It is menu 2
      *currentmenu = 2;
      return;
      }
    case 1:
      {
      *currentmenu = 3;
      display_menu(3);//This is the wifi options menu. It is menu case 3
      return;
      }
    case 2:
      display_string(0,"Not implemented yet");
      quicksleep(1000);
      *currentmenu = 0;
      display_menu(1);
      return;
    case 3:
      {
      display_string(0,"Not implemented yet");
      quicksleep(1000);
      *currentmenu = 0;
      display_menu(1);
      return;
      }
    }
  }
