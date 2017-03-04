/*
The 5 problems
Problem 1

Write three functions that compute the sum of
the numbers in a given list using a
for-loop, a while-loop, and recursion.

Johan Kämpe
Mjukvaruutvecklare Inbyggda System

Kurs
Programmering av inbyggda system
 */

#include <stdio.h>
int addForLoop(int l[], int size);
int addWhileLoop(int l[], int size);
int addRecursion(int l[], int size);

int main(int argc, char const *argv[]) {
    int list[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    /*  Get number of elements in list */
    int size = sizeof(list) / sizeof(list[0]);
    /*  Call functions and print result */
    int result = addForLoop(list, size);
    printf("addForLoop: %d\n", result);
    result = addWhileLoop(list, size);
    printf("addWhileLoop: %d\n", result);
    result = addRecursion(list, size);
    printf("addRecursion: %d\n", result);
    return 0;
}

/*   Function that adds elements in int
    array using a for-loop    */
int addForLoop(int l[], int size){
    int add = 0;
    for(int i = 0; i < size; i++){
        add += l[i];
    }
    return add;
}

/*   Function that adds elements in int
    array using a while-loop    */
int addWhileLoop(int l[], int size){
    int add = 0, i = 0;
    /*   Runs while size is not zero    */
    while(size--){
        /*   Add value in element i to variable add,
            and increase index i by one    */
        add += l[i++];
    }
    return add;
}

/*    Recursive function that returns sum of elements in
    an int array.   */
int addRecursion(int l[], int size){
    /*   Keep adding elements from list end, until size is zero     */
    if(size){
        return l[size-1] + addRecursion(l, size-1);
    }
    return 0;
}
