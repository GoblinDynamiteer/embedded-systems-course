/*
Bitwise operation exercises

Exercise 01
http://www.codeforwin.in/2016/01/c-program-to-check-lsb-of-number.html

Write a C program to input any number from user and check whether the
Least Significant Bit (LSB) of the given number is set (1) or not (0).
How to check whether the least significant bit of a number is set or
unset using bitwise operator in C programming.

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Course
Programmering av inbyggda system
*/

#include <stdio.h>

int checkBitAtPosition(unsigned int num, int bit);
void printBinary(unsigned int hex);

int main(int argc, char const *argv[]) {
  int num;
  printf("Enter integer: ");
  scanf("%i", &num);
  if(checkBitAtPosition(num, 1)){
    printf("LSB is set!\n");
  }
  else{
    printf("LSB is not set!\n");
  }
  printf("Binary:\n");
  printBinary(num);
  return 0;
}

/*   Returns bit value at position 'bit'  */
int checkBitAtPosition(unsigned int num, int bit){
  unsigned int a = 0x0001 << bit-1;
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
