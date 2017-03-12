/*
Bitwise operation exercises

Exercise 07
Write a C program to input any number from user and find the highest order
set bit of given number using bitwise operator.
How to find the highest order of the set bit of a given number using
bitwise operator in C programming.
Finding highest order set bit of any number in C programming.

Example:
Input any number: 22
Output: Highest order set bit in 22 is 4.
dec 22
bin 0001 0110
(I use 1 as first bit, highest order set bit for me is 5 in example)

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
  bit = findHighestSetBit(num);
  printf("Highest set bit is bit %i\n", bit);
  printBinaryAndBitPosition(num, bit);
  return 0;
}
