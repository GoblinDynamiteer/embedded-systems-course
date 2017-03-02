/*    sevenseg.c
    for seven segment display

    segments
        A
    F  |``| B
       -G-
    E |__| C
       D
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
    for(int i = 0; i < MAXPINS; i++){
        pinMode(ret.pins[i], OUTPUT);
    }
    return ret;
}

/*  Turn on all segments */
void ssegTest(sseg ss){
    for(int i = 0; i < MAXPINS; i++){
        digitalWrite(ss.pins[i], HIGH);
    }
}

/*    Display a number on the seven segment display   */
void ssegDisplay(sseg ss, int num){
    /*  Turn all leds off */
    for(int i = 0; i < MAXPINS; i++){
        digitalWrite(ss.pins[i], LOW);
    }
    switch(num){
        case 1:
            digitalWrite(ss.pins[C], HIGH);
            digitalWrite(ss.pins[B], HIGH);
            break;
    }
}
