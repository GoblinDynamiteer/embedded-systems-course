/*    Store temp values up to 15 in 8 bit variables 2x4 bits   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uint8_t;

#define MAX_VALUES 100

void setTempH(uint8_t * tempArr, uint8_t temp);
void setTempL(uint8_t * tempArr, uint8_t temp);
uint8_t getTempH(uint8_t tempArr);
uint8_t getTempL(uint8_t tempArr);
void initRand(void);
uint8_t getRandomTemp(void);

int main(){
    initRand();
    uint8_t tempVal[MAX_VALUES];
    /*   Set random temp values    */
    for(int i = 0; i < MAX_VALUES; i++){
        setTempH(&tempVal[i], getRandomTemp());
        setTempL(&tempVal[i], getRandomTemp());
        printf("TEMP %i HIGH BITS: %i\n", i, getTempH(tempVal[i]));
        printf("TEMP %i LOW BITS : %i\n\n", i, getTempL(tempVal[i]));
        //printf("random: %i\n", getRandomTemp());
    }
}

/*    Set value to 4 high bits in 8 bit integer   */
void setTempH(uint8_t * tempArr, uint8_t temp){
    printf(" - SETTING HIGH BITS: %i\n", temp);
    *tempArr &= ~(0b11110000);
    *tempArr |= (temp << 4);
}

/*    Set value to 4 low bits in 8 bit integer   */
void setTempL(uint8_t * tempArr, uint8_t temp){
    printf(" - SETTING LOW BITS: %i\n", temp);
    *tempArr &= ~(0b00001111);
    *tempArr |= temp;
}

/*    Get value from 4 low bits in 8 bit integer   */
uint8_t getTempH(uint8_t tempArr){
    return (uint8_t) 0x00 | (tempArr >> 4);;
}

/*    Get value from 4 high bits in 8 bit integer   */
uint8_t getTempL(uint8_t tempArr){
    return (uint8_t) 0x00 | (tempArr & (0b00001111));
}

/*    Randomize a value up to 15   */
uint8_t getRandomTemp(void){
    return (rand() % (15)) + 1;
}

/*    Seed random   */
void initRand(void){
    time_t t;
    srand((unsigned) time(&t));
}
