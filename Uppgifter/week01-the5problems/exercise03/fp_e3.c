/*
The 5 problems
Problem 3

Write a function that computes the list
of the first 100 Fibonacci numbers.
By definition, the first two numbers in
the Fibonacci sequence are 0 and 1, and
each subsequent number is the sum of the
previous two.

As an example, here are the first 10
Fibonnaci numbers:
    0, 1, 1, 2, 3, 5, 8, 13, 21, and 34.

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Kurs
Programmering av inbyggda system
 */

#include <stdio.h>
#include <stdlib.h>

/*  To hold higher fibonacci numbers,
    cant use for all 100 though. */
typedef unsigned long long int ulli;

ulli fibonacci(int n);
void fibonacci100();

int main(int argc, char const *argv[]) {
    fibonacci100();
    return 0;
}

/*   Calculate fibonacci number n    */
ulli fibonacci(int n){
    if(!n){
        return 0ull;
    }
    /*  Series start with 0, 1 */
    ulli num1 = 0, num2 = 1;
    while(--n){
        /*  Set num2 to next number in sequence,
            and set num1 to num2 previous value */
        ulli temp = num2;
        num2 = num1 + num2;
        num1 = temp;
    }
    return num2;
}

/*    Print the first 100 fibonacci numbers */
void fibonacci100(){
    for(int i = 0; i < 100; i++){
        /*  Unsigned long long is not big enough for higher numbers. */
        printf("%03i : %u\n", i+1, fibonacci(i));
    }
}
