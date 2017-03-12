/*
Bitwise operation exercises

Exercise 10
Write a C program to input any number from user and find total number of
leading zeros of the given number (in binary representation) using bitwise
operator. How to find total number of leading zeros of a given number
(in binary representation) using bitwise operator in C programming.
Finding total number of leading zeros of a given number using C programming.

Example:
Input any number: 22
Output leading zeros: 27 (using 4 byte signed integer)

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
  int num, bit, lz; //lz = leading zeroes
  printf("Enter integer: ");
  scanf("%i", &num);
  bit = findHighestSetBit(num);
  printf("Highest set bit is bit %i\n", bit);
  printBinaryAndBitPosition(num, bit);
  /* Trailing zeroes after first set bit from right    */
  lz = NUM_BITS - bit;
  printf("\nLeading zeroes: %i\n", lz);
  return 0;
}
