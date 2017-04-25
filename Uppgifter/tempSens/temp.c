/*    Store temp values up to 15 in 8 bit variables 2x4 bits   */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char uint8_t;

#define MAX_VALUES 20

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

void setTempH(uint8_t * tempArr, uint8_t temp){
    printf(" - SETTING HIGH BITS: %i\n", temp);
    *tempArr |= (temp << 4);
}

void setTempL(uint8_t * tempArr, uint8_t temp){
    printf(" - SETTING LOW BITS: %i\n", temp);
    *tempArr |= ((0b00001111) & temp);
}

uint8_t getTempH(uint8_t tempArr){
    uint8_t ret = 0x00;
    ret |= (tempArr >> 4);
    return ret;
}

uint8_t getTempL(uint8_t tempArr){
    uint8_t ret = 0x00;
    ret = tempArr & (0b00001111);
    return ret;
}

uint8_t getRandomTemp(void){
    return (rand() % (15-8)) + 8 + 1;
}

/*    Seed random   */
void initRand(void){
    time_t t;
    srand((unsigned) time(&t));
}
