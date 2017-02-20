//Contains Auxially functions that do very little but are necessary
//These include things like the mod function, whose sole purpose is
//to allow modular arithmetic to work with negative numbers




int mod (int a, int b)
	{
   int ret = a % b;

   if(ret < 0)
	   {
     ret+=b;
	   }
   return ret;
	}
