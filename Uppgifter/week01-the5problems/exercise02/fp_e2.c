/*
The 5 problems
Problem 2

Write a function that combines two lists by
alternatingly taking elements. For example:
given the two lists [a, b, c] and [1, 2, 3],
the function should return [a, 1, b, 2, c, 3].

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Kurs
Programmering av inbyggda system
 */

#include <stdio.h>
#include <stdlib.h>

int * combineLists(int a[], int b[], int size);

int main(int argc, char const *argv[]) {
    int listA[] = {1,2,3,4,5};
    int listB[] = {100,200,300,400,500};
    int size = sizeof(listA) / sizeof(listA[0]);
    int * combinedList = combineLists(listA, listB, size);
    for(int i = 0; i < size * 2; i++){
        printf("%d \n", combinedList[i]);
    }
    return 0;
}

/*   Combine two lists, assume they are of same element size
    returns pointer to new list. */
int * combineLists(int a[], int b[], int size){
    int * combList = malloc(sizeof(int) * size * 2);
    int ix = 0, ixc = 0;
    while(size--){
        combList[ixc++] = a[ix];
        combList[ixc++] = b[ix++];
    }
    return combList;
}
