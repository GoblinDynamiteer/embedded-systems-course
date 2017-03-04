/*
The 5 problems
Problem 4

Write a function that given a list of non negative integers,
arranges them such that they form the largest possible number.

For example, given [50, 2, 1, 9],
the largest formed number is 95021.

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Kurs
Programmering av inbyggda system
 */

#include <stdio.h>
#include <stdlib.h>

/*  Assume largest integer in list has 10 digits */
#define MAXDIGITS 10

int largest(int l[], int n);

int main(int argc, char const *argv[]){
    int list[] = {50, 2, 1, 9};
    int size = sizeof(list) / sizeof(list[0]);
    printf("%i\n", largest(list, size));
    return 0;
}


int largest(int l[], int n){
    /*  Array of strings */
    char * num[n];
    /*  Convert integers to strings, hold in string array */
    for(int i = 0; i < n; i++){
        /*  Allocate memory for string */
        num[i] = malloc(sizeof(char) * MAXDIGITS);
        /*   Convert integer in list to string    */
        sprintf(num[i], "%d", l[i]);
    }
    for(int i = 0; i< n; i++){
        printf("char: %s\n", num[i]);
    }
    return n;
}
