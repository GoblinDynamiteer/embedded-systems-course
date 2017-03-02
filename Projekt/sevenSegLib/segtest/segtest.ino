#include "sevenseg.h"

sseg numLed = ssegInit(12, 13, 7, 11, 10, 9, 8);

void setup(){

}

void loop(){
    for(int i = 0; i< 10; i++){
        ssegDisplay(numLed, i);
        delay(1000);
    }
}
