/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "master.h"  /* Declatations for all h files */


int currentline = 0;


int timeoutcount = 0; // global counter



/* Interrupt Service Routine */
void processButtons(int buttonPress)
{
	if(buttonPress & 0x4)// Button
	   	PORTE = PORTE + 1;
	if(buttonPress & 0x2)
		  {
			textbuffer[currentline][12] = ' ';
  		currentline = mod((currentline + 1),4);
			textbuffer[currentline][12] = '*';
 			}
	if(buttonPress & 0x1)
			{
			textbuffer[currentline][12] = ' ';
		  currentline = mod((currentline-1),4);
			textbuffer[currentline][12] = '*';

			}
}

void user_isr( void )
	{
  if((IFS(0) & 0x100) == 0x100)
		{
		TMR2 = 0x0; // Clear timer register
		IFS(0) = IFS(0) & 0xfffffeff; // reset event flag
		timeoutcount++;
  	}

  if(timeoutcount == 3)
		{ // execute display/time functions after count reaches 10
		timeoutcount = 0;
		int btnpress = getbtns();
  	processButtons(btnpress);

		}
	}

/* Lab-specific initialization goes here */
void labinit( void )
{
  volatile int* trise = (volatile int*) 0xbf886100;
  *trise = *trise & ~0xff; // set LEDs to output (initialize 8 lsb of Port E to outputs)
	textbuffer[0][12] = '*';
  TRISD = TRISD | ~0xffffe01f; // set bits 11 through 5 of Port D as inputs

  IPC(4) = IPC(4) | 0x1f000000; // set priority (SURPRISE)
  IEC(0) = IEC(0) | 0x80000; // enable SW4 interrupt (SURPRISE)

  T2CON = 0x70; // set prescale for timer to 1:256
  TMR2 = 0x0; // Clear timer register
  PR2 = 31250; // Load period register (80 mHz/256/10 = 31,250)

  IPC(2) = IPC(2) | 0x1C; // set highest priority (7)
  IPC(2) = IPC(2) | 0x3; // set highest subpriority (3)
  enable_interrupt(); // enable global interrupts
  IEC(0) = IEC(0) | 0x100; // enable Timer 2 interrupt

  T2CON = T2CON | 0x8000; // Start timer
}

/* This function is called repetitively from the main program */
void labwork( void ) 
  {
 display_update();
  }
