//Contains Auxially functions that do very little but are necessary
//These include things like the mod function, whose sole purpose is
//to allow modular arithmetic to work with negative numbers

void initialize_LED(){
	volatile int* trise = (volatile int*) 0xbf886100; 
    *trise = *trise & ~0xff; // set LEDs to output (initialize 8 lsb of Port E to outputs)
	//volatile int* porte = (volatile int*) 0xbf886110;
	*porte = *porte | 0x0; // LEDs begin by showing value 0 (initialize value of Port E to 0) 
}



int mod (int a, int b)
	{
   int ret = a % b;

   if(ret < 0)
	   {
     ret+=b;
	   }
   return ret;
	}
