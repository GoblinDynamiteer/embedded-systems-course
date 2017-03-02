/*    sevenseg.c
    for seven segment display

    */
#include "sevenseg.h"

/*   Set pins for seven segment led    */
sseg ssegInit(int a, int b, int c, int d,
    int e, int f, int g){
    sseg ret;
    ret.pins[A] = a;
    ret.pins[B] = b;
    ret.pins[C] = c;
    ret.pins[D] = d;
    ret.pins[E] = e;
    ret.pins[F] = f;
    ret.pins[G] = g;
    return ret;
}

/*  Turn on all segments */
void ssegTest(sseg ss){
    for(int i = 0; i < MAXPINS; i++){
        digitalWrite(ss.pins[i], HIGH);
    }
}

void ssegDisplay(int i){
    return;
}
