/*
Bitwise operation exercises

Exercise 02
http://www.codeforwin.in/2016/01/
  c-program-to-check-most-significant-bit-of-number-is-set-or-not.html

Write a C program to input any number from user and check whether the
Most Significant Bit (MSB) of the given number is set (1) or not (0).
How to check whether the most significant bit of any given number is
set or unset using bitwise operator in C programming.

Example:
Input number: -1
Output: Most Significant Bit (MSB) of -1 is set (1).

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

int main(int argc, char const *argv[]) {
  int num;
  printf("Enter integer: ");
  scanf("%i", &num);
  /*  First bit determines positive/negative value,
    MSB is maxBits -1 */
  if(checkBitAtPosition(num, NUM_BITS-1)){
    printf("MSB is set!\n");
  }
  else{
    printf("MSB is not set!\n");
  }
  printf("Binary:\n");
  printBinary(num);
  return 0;
}

/*   Returns bit value at position 'bit'  */
int checkBitAtPosition(int num, int bit){
  int a = 0x0001 << bit-1;
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
