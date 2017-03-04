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



todo:
    Fix comparison between numbers of size > 2 digits
    currently sorts by first digit only.
    Solution: Check amount of digits & compare digit by digit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*  Assume largest integer in list has 10 digits */
#define MAXDIGITS 10

int largest(int l[], int n);
void sort(int *array, int size);
int getFirstDigit(int num);

int main(int argc, char const *argv[]){
    int list[] = {50, 2, 1, 9, 8, 77};
    int size = sizeof(list) / sizeof(list[0]);
    printf("List: ");
    for(int i = 0; i< size; i++){
        printf("%i ", list[i]);
    }
    printf("\nLargest number from numbers in list: %i\n", largest(list, size));
    return 0;
}

int largest(int l[], int n){
    /*  Array of strings */
    char * num[n], *result;
    sort(l, n);
    /*  Convert integers to strings, hold in string array */
    for(int i = 0; i < n; i++){
        /*  Allocate memory for string */
        num[i] = malloc(sizeof(char) * MAXDIGITS);
        /*   Convert integer in list to string    */
        sprintf(num[i], "%d", l[i]);
    }
    /*    Allocate memory for result, and fill with null terminators   */
    result = malloc(sizeof(char) * MAXDIGITS * n);
    memset(result, '\0', n);
    /*    Copy sorted string numbers to result   */
    for(int i = 0; i< n; i++){
        strcat(result, num[i]);
    }
    /*  Return result, converted to an integer */
    return atoi(result);
}

/*   Swap two integer values, passed by reference  */
void _swap(int *n1, int *n2) {
   int temp = *n1;
   *n1 = *n2;
   *n2 = temp;
}

/*   Returns the first digit of an integer    */
int getFirstDigit(int num){
    while(num){
        /*    Do integer division until first digit   */
        if(num / 10 != 0){
            num /= 10;
        }
        else{
            return num;
        }
    }
}

/*  Sort string list with insertion sort */
void sort(int *array, int size){
	int ix, jx;
	for(ix = 0; ix < size; ix++){
		jx = ix;
        /*  Sort by first digit */
		while(jx &&
            (getFirstDigit(array[jx-1]) < getFirstDigit(array[jx]))){
    			_swap(&array[jx], &array[jx-1]);
    			jx--;
		}
	}
}
