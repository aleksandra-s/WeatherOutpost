#ifndef WO_LCDHEADER_H
#define WO_LCDHEADER_H

// Initialize LCD
void initialize_LCD(void);

// Display string on a line
void display_string(int line, char *s);
	
//Navigate cursor (*) to a line
void put_cursor_index(int line);

#endif
