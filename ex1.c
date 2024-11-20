/******************
Name: Marino Marco Siegwart
ID: 346268600
Assignment: ex1
*******************/
#include <stdio.h>

// REMINDER : YOU CANT USE ANY CONTROL FLOW OPERATIONS OR FUNCTIONS, ONLY BITWISE.

int main() {
	// What bit
  	printf("What bit:\n");
  	/*Scan two integers (representing number and a position)
	Print the bit in this position. */
  	int numberOne, numberTwo, bitPosition;
  	printf("Please enter a number:\n");
  	scanf("%d", &numberOne);
  	printf("Please enter a position:\n");
  	scanf("%d",&bitPosition);
  	/*shifting the number to the right by bitPosition so the rightmost
  	digit is the desired bit and storing the result in bitValue*/
  	int bitValue = numberOne>>bitPosition;

  	// Defining the Mask value to be one
  	int mask = 0x1;
  	/*the bitValue&mask command outputs only the rightmost bit's value (0 or 1)
	which is the desired bit (see two comments before) */
  	printf("The bit in position %d of number %d is: %d\n", bitPosition, numberOne, bitValue&mask);

  	// Set bit
  	printf("\nSet bit:\n");
  	/*Scan two integers (representing number and a position)
  	Make sure the bit in this position is "on" (equal to 1)
  	Print the output
  	Now make sure it's "off" (equal to 0)
  	Print the output */
  	printf("Please enter a number:\n");
  	scanf("%d", &numberOne);
  	printf("Please enter a position:\n");
  	scanf("%d",&bitPosition);
	//moving the 1 digit in mask with value 1 to bit position
	mask <<= bitPosition;
	//the "Or" makes the bitPosition digit become 1 or "on"
	printf("Number with bit %d set to 1: %d\n", bitPosition, mask|numberOne);
	/*the "Not" on mask converts all digits in mask except bitPosition to 1
	and so the "And" with number makes the bit at bitPosition 0 and the rest the same*/
	printf("Number with bit %d set to 0: %d\n", bitPosition, ~mask&numberOne);

  	// Toggle bit
  	printf("\nToggle bit:\n");
  	/*Scan two integers (representing number and a position)
  	Toggle the bit in this position
  	Print the new number */
	printf("Please enter a number:\n");
	scanf("%d", &numberOne);
	printf("Please enter a position:\n");
	scanf("%d",&bitPosition);
	// reassigning mask according to the updated bit position (so the on bit is in bitPosition)
	mask = 0x1<<bitPosition;
	/*xor with the bit "1" flips the bit and so the bit at bitPosition will be flipped
	while xor with the bit "0" will not affect the rest of the bits so only this bit will be flipped*/
	printf("Number with bit %d toggled: %d\n", bitPosition, mask^numberOne);

  	// Even - Odd
  	printf("\nEven - Odd:\n");
  	/* Scan an integer
  	If the number is even - print 1, else - print 0. */
	printf("Please enter a number:\n");
	scanf("%d", &numberOne);
	//resetting mask to 0x1
	mask = 0x1;
	/* "And" with the mask 0x1 gives 1 if odd
	and 0 if even and xor with 0x1 again flips the result*/
	printf("%d\n", 0x1^(numberOne&mask));

  	// 3, 5, 7, 11
  	printf("\n3, 5, 7, 11:\n");
  	/* Scan two integers in octal base
  	sum them up and print the result in hexadecimal base
  	Print only 4 bits, in positions: 3,5,7,11 in the result. */
	// defining
	printf("Please enter the first number (octal):\n");
	scanf("%o",&numberOne);
	printf("Please enter the second number (octal):\n");
	scanf("%o", &numberTwo);
	int numberSum = numberOne + numberTwo;
	printf("The sum in hexadecimal: %X\n", numberSum);
	/* similarly to earlier also here we find the bit value by shifting the bit we want to the rightmost digit
	and then applying "And" on it with 0x1 (mask)*/
	printf("The 3,5,7,11 bits are: %d%d%d%d\n", mask&numberSum>>3, mask&numberSum>>5,
		mask&numberSum>>7, mask&numberSum>>11);
	printf("Bye!\n");

  	return 0;
}
