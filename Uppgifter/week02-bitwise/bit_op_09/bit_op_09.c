/*
Bitwise operation exercises

Exercise 09
Write a C program to input any number from user and count number of
trailing zeros in the given number using bitwise operator.
How to find total number of trailing zeros in any given number
using bitwise operator in C programming.

Example:
Input any number: 22
Output trailing zeros: 1

dec 22
bin 0001 0110

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>
#include "lib/libbitop.h"

int main(int argc, char const *argv[]) {
  int num, bit, tz;
  printf("Enter integer: ");
  scanf("%i", &num);
  bit = findLowestSetBit(num);
  printf("Lowest set bit is bit %i\n", bit);
  printBinaryAndBitPosition(num, bit);
  /* Trailing zeroes after first set bit from right    */
  tz = bit - 1;
  printf("\nTrailing zeroes: %i\n", tz);
  return 0;
}
