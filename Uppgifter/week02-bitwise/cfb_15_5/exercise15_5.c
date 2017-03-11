/*
Bitwise operation exercises

Exercise 15.5
From book 'C från början' by Jan Skansholm

Write a program that reads a hexadecimal number
to a variable of type unsigned int. Determine if
the number contains a 1 in the third bit from
the right.

If so, change the bit to 0 and set the first bit
from the right to 1.

Print the hexadecimal value.

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>

int checkBitAtPosition(unsigned int num, int bit);
unsigned int setBit(unsigned int num, int bit, int value);
void printBinary(unsigned int hex);

int main(int argc, char const *argv[]) {
  unsigned int hexNum;
  printf("Enter a hexadecimal number: ");
  /*   %x is formating for hexadecimal  */
  scanf("%x", &hexNum);
  printf("Hex: %x\nBinary: ", hexNum);
  printBinary(hexNum);
  /*   Check if bit in position 3 from right is 1  */
  if(checkBitAtPosition(hexNum, 3)){
    printf("\nSet third bit to 0:\n");
    hexNum = setBit(hexNum, 3, 0);
    printf("Hex: %x\nBinary: ", hexNum);
    printBinary(hexNum);
    printf("\nSet first bit to 1:\n");
    hexNum = setBit(hexNum, 1, 1);
    printf("Hex: %x\nBinary: ", hexNum);
    printBinary(hexNum);
  }
  return 0;
}

/*  Set bit at specific position to 1/0 */
unsigned int setBit(unsigned int num, int bit, int value){
  if(value){ //set bit to 1
    /*   Shift in 1 to correct bit position to set to 1
        and OR with num, the bit at postion 'bit' will be 1 */
    num = num | (0x0001 << bit-1);
  }
  else{ //set bit to 0
    /*   Shift in 1 to correct bit position to set to 0,
        inverse all digits, and AND with num, the bit at
        position 'bit' will be 0 */
    num = num & ~(0x0001 << bit-1);
  }
  return num;
}

/*   Returns bit value at position 'bit'  */
int checkBitAtPosition(unsigned int num, int bit){
  /*  Shift in 1 to position bit -1 */
  unsigned int a = 0x0001 << bit-1;
  /*  Return 1/0 for bit at 'bit' in num.
      if 1: Value from & operand will be > 0
      if 0: Value will be 0.

      example
      num 0x7:                  0111
      a 1 shifted 3 positions   1000
      0111 & 1000 = 0

      example
      num 0xf:                  1111
      a 1 shifted 3 positions   1000
      1111 & 1000 = 1     */
  return ((num & a) > 0);
}

/*   For binary output  */
void printBinary(unsigned int hex){
  int spacer = 3;
  for(int i = 4*4; i > 0; i--){
    printf("%i", checkBitAtPosition(hex, i));
    if(!spacer--){
      printf(" ");
      spacer = 3;
    }
  }
}
