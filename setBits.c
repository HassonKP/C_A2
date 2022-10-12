/*Killian Hasson		Class: CS201		Date: 02/03/2022
 *
 *  For this program we were tasked with taking in a list of integers, turn on the corresponding bits,
 *and output the results to show set membership. We also were informed to check for integers to insure 
 *they remained between 0-15 aswell as checking for no integer responses.
 * */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	unsigned int value = 0;
	unsigned long int tvalue = 0;
	char * next;
	//A conditional to ensure we recieved arguments
	if (argc < 2)
	{
		printf("Error: no arguments\n");
		return 1;
	}

	//This loop will go through the input integers
	for (int i = 1; i < argc; i++) 
	{
		//assigns value base 10 to tvalue based on the 'i'th integer ends at the next
		tvalue = strtoul(argv[i], &next, 10);
    		//This conditional checks if the integer is within the 0-15 
		if (tvalue > 15 || (int)*next != 0) 
		{
      			//read out an error
      			printf("Error: invalid arguments\n");
			return 1;
    		}
		//Mask will be utilized for left shifting
		long int mask = 1;
		value |= mask << tvalue;
	}

	//loop assists in properly displaying in correct format
	for (int j = 15; j >= 0; j--) 
	{
		//read out bits
    		printf("%d", (value & (1 << j)) ? 1 : 0);
    		//Every 4th bit create a space
		if (j % 4 == 0) 
		{
      			printf(" ");
   		}
  		
	}

	return 0;
}
