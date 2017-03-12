/*
Bitwise operation exercises

Exercise 05
Write a C program to input any number from user and clear the nth bit of
the given number using bitwise operator.
How to clear nth bit of a given number using bitwise operator in C programming.
How to unset (0) the value of nth bit of a given number in C.

Example:
Input number: 13
Input nth bit to clear: 0
Output number after clearing nth bit: 12 (in decimal)

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>
#include "lib/libbitop.h"

int main(int argc, char const *argv[]) {
  int num, bit;
  printf("Enter integer: ");
  scanf("%i", &num);
  printf("Enter bit position to set to 1: ");
  scanf("%i", &bit);
  /*  Assumes the first bit starts at 1 */
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
  num = setBitAtPosition(num, bit, 0);
  printf("\nChanged bit %i to 0:\n", bit);
  printf("New number: %i\n", num);
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
  return 0;
}
