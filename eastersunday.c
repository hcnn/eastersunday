#include "eastersunday.h"

void eastersunday(int y, int *m, int *d)
{
    // Error-Checking
	if( (y < 1583) || (y > 4099) ){
        fprintf(stderr, "The year have to be between 1583 and 4099");
        exit(-1);
	}

   	int FirstDig = (int)(y/100.0); //first 2 digits of year
   	int Remain19 = (y % 19); //remainder of year / 19

	// calculate PFM date
	int temp = 202 ; // Smallest temp is 202-198-0-2=2
	temp -= (11 * Remain19) ; // values up to 198 possible what is still less than 202
   	temp += (int)((FirstDig - 15) / 2.0) ; // Smallest FirstDig is 15; MAX=202-0+7=209
    
	switch(FirstDig)
	{
		case 21:
		case 24:
		case 25:
		case 27:
		case 28:
		case 29:
		case 30:
		case 31:
		case 32:
		case 34:
		case 35:
		case 38:
			temp -= 1;
			break;
		case 33:
		case 36:
		case 37:
		case 39:
		case 40:
			temp -= 2;
			break;
	}
	temp = (temp % 30);

	//Compute tA
	int tA = temp + 21; // tA cannot be less than 20; MAX=29+21=40
	if( temp == 29 )
	{
		tA -= 1;
	}
	if( (temp == 28) && (Remain19 > 10) )
	{
		tA -= 1;
	}

	// find the next Sunday
	int tB = (tA - 19) % 7; // As said, tA cannot be less than 20
    
	//Compute tC
	int tC = (40 - FirstDig) % 4; // Maximum value is FirstDig=40
	if(tC == 3)
	{
		tC += 1;
	}
	if( tC > 1 )
	{
		tC += 1;
	}
        
	//Compute tD
	temp = (y % 100); // temp is unsigned 
    int tD = ((temp + (int)(temp/4.0)) % 7);

	//Compute tE
	int tE = (((20 - tB - tC - tD) % 7) + 1);	// Max tB=6, tC=3, tD=6 ==> 20-6-3-6=5

	//Compute Day d
	d[0] = (tA + tE);

	// return the date
	m[0] = 3;
	if( d[0] > 31 )
	{
		d[0] -= 31;
		m[0] = 4;
	}
}
