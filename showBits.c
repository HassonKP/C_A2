/*Killian Hasson		Class: CS201		Date: 02/04/2022
 *
 * For this program we were required to take in two hexadecimal 32 bit integers and display which bits the two numbers
 * both have set to 1. We have to print the bit numbers counting from 0 as welll as the resulting number in hexadecimal.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	//unisgned ints for holding the values
	unsigned int value1 = 0;
	unsigned int value2 = 0;
	//used for hexadecimal input
	char * next;

	//if only two argcs theres no input
	if (argc < 2)
	{
		printf("Error: no arguments\n");
		return 1;
	}

	//if two many arguments passed, return
	if (argc != 3) 
	{
		printf("Error: invalid arguments\n");
		return 1;
	}

	//first hexadecimal input parsed into value1
	value1 = strtoul(argv[1], &next, 16);
	
	//check for invalid hexadecimal input
	if ((int)*next != 0) 
	{
		printf("Error: invalid arguments\n");
		return 1;
	}
  
	//second hexadecimal input parsed into value2
	value2 = strtoul(argv[2], &next, 16);
  
	//check for invalid hexadecimal input
	if ((int)*next != 0) 
	{
    		printf("Error: invalid arguments\n");
    		return 1;
  	}
  
	printf("v1: %u, v2: %u\n", value1, value2);
  	
	//used for bit shifting
	unsigned int value_common = 0;
  
	printf("Bits ");

	//For loop to navigate through the value1 and value2 to find matching bits set to 1
  	for (int j = 0; j < 32; j++) 
	{
		//if found, increase common value
    		if (value1 & (1 << j) && value2 & (1 << j)) 
		{
      			printf("%d,", j);
      			value_common |= 1 << j;
    		}
  	}
	
  	printf(" in common. Hexadecimal: %x, Signed: %d, Unsigned: %u.\n", value_common, (int)value_common, value_common);
  
	return 0;
}

