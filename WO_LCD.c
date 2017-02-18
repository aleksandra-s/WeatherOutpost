// Navigate menu cursor (*) up a line
void navigate_cursor_up(){
  textbuffer[currentline][12] = ' ';
  currentline = mod((currentline + 1),4);
	textbuffer[currentline][12] = '*';
}

// Navigate menu cursor (*) down a line
void navigate_cursor_down(){
  textbuffer[currentline][12] = ' ';
	currentline = mod((currentline - 1),4);
	textbuffer[currentline][12] = '*';
}
