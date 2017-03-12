/*
Bitwise operation exercises

Exercise 04
Write a C program to input any number from user and set
nth bit of the given number as 1.

How to set nth bit of a given number using bitwise operator in C programming.
Setting nth bit of a given number using bitwise operator.

Example:
Input number: 12
Input nth bit to set: 0 (-- I will use 1 as first bit)
Output number after setting nth bit: 13 in decimal

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
  num = setBitAtPosition(num, bit, 1);
  printf("\nChanged bit %i to 1:\n", bit);
  printf("New number: %i\n", num);
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
  return 0;
}
