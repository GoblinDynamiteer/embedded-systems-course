/*
Bitwise operation exercises

Exercise 03
http://www.codeforwin.in/2016/01/
  c-program-to-get-value-of-nth-bit-of-number.html

Write a C program to input any number from user and check whether the nth
bit of the given number is set (1) or not (0).
How to check whether the nth bit of a given number is set or unset using
bitwise operator in C programming.

Example:
Input number: 12
Input nth bit number: 2
Output: 2 bit of 12 is set (1).


Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>

/*  Bits in int (8 bits per byte)  */
#define NUM_BITS sizeof(int) * 8

int checkBitAtPosition(int num, int bit);
void printBinary(int hex);
void printPositionMarker(int num);

int main(int argc, char const *argv[]) {
  int num, checkBit;
  printf("Enter integer: ");
  scanf("%i", &num);
  printf("Enter bit position: ");
  scanf("%i", &checkBit);
  /*  Assumes the first bit starts at 1 */
  printf("Bit at position %i: %i\n",
    checkBit, checkBitAtPosition(num, checkBit));
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", checkBit);
  printPositionMarker(checkBit);
  return 0;
}

/*   Returns bit value at position 'bit'  */
int checkBitAtPosition(int num, int bit){
  int a = 0x0001 << bit-1; //Assumes the first bit starts at 1
  return ((num & a) > 0);
}

/*   For binary output  */
void printBinary(int num){
  int spacer = 3;
  for(int i = NUM_BITS; i > 0; i--){
    printf("%i", checkBitAtPosition(num, i));
    if(!spacer--){
      printf(" ");
      spacer = 3;
    }
  }
}

/*  Prints "#" at bit position, to be used with printBinary()  */
void printPositionMarker(int num){
  int spacer = 3;
  for(int i = 1; i < NUM_BITS; i++){
    printf(" ");
    if(!spacer--){
      printf(" ");
      spacer = 3;
    }
    if(i == NUM_BITS - num){
      break;
    }
  }
  printf("#");
}
