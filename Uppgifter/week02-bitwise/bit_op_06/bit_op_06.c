/*
Bitwise operation exercises

Exercise 06
Write a C program to input any number from user and toggle or invert or
flip nth bit of the given number using bitwise operator.
How to toggle/invert/flip nth bit of a given number using bitwise operator
in C programming.

Example:
Input number: 22
Input nth bit to toggle: 1
(--I use bit 1 as first bit, exercise example uses 0)
Output after toggling nth bit: 20 (in decimal)

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
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
  num = toggleBitAtPosition(num, bit);
  printf("\nToggling bit %i\n", bit);
  printf("New number: %i\n", num);
  printf("Binary: ");
  printBinary(num);
  printf("\nBit %02i: ", bit);
  printPositionMarker(bit);
  return 0;
}
