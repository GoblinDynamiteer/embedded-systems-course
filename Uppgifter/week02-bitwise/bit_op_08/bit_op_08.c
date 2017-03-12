/*
Bitwise operation exercises

Exercise 08
Write a C program to input any number from user and find the
lowest order set bit of the given number using bitwise operator.
How to find first set bit in a given number using bitwise
operator in C programming.
Finding first set bit in a binary number using C program.

Example:
Input any number: 22
Output first set bit: 1

dec 22
bin 0001 0110
(I use 1 as first bit, lowest order set bit for me is 2 in example)

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>
#include "lib/libbitop.h"

int main(int argc, char const *argv[]) {
  int num, bit = 7;
  printf("Enter integer: ");
  scanf("%i", &num);
  bit = findLowestSetBit(num);
  printf("Lowest set bit is bit %i\n", bit);
  printBinaryAndBitPosition(num, bit);
  return 0;
}
