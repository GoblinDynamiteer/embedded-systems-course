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
        case 2:
            digitalWrite(ss.pins[A], HIGH);
            digitalWrite(ss.pins[B], HIGH);
            digitalWrite(ss.pins[G], HIGH);
            digitalWrite(ss.pins[D], HIGH);
            digitalWrite(ss.pins[E], HIGH);
            break;
        case 3:
            digitalWrite(ss.pins[A], HIGH);
            digitalWrite(ss.pins[B], HIGH);
            digitalWrite(ss.pins[C], HIGH);
            digitalWrite(ss.pins[D], HIGH);
            digitalWrite(ss.pins[G], HIGH);
            break;
        case 4:
            digitalWrite(ss.pins[F], HIGH);
            digitalWrite(ss.pins[G], HIGH);
            digitalWrite(ss.pins[B], HIGH);
            digitalWrite(ss.pins[C], HIGH);
            break;
        case 5:
            digitalWrite(ss.pins[A], HIGH);
            digitalWrite(ss.pins[F], HIGH);
            digitalWrite(ss.pins[G], HIGH);
            digitalWrite(ss.pins[C], HIGH);
            digitalWrite(ss.pins[D], HIGH);
            break;
        case 6:
            ssegTest(ss);
            digitalWrite(ss.pins[B], LOW);
            break;
        case 7:
            digitalWrite(ss.pins[A], HIGH);
            digitalWrite(ss.pins[C], HIGH);
            digitalWrite(ss.pins[B], HIGH);;
            break;
        case 8:
            ssegTest(ss);
            break;
        case 9:
            ssegTest(ss);
            digitalWrite(ss.pins[E], LOW);
            break;
        case 0:
            ssegTest(ss);
            digitalWrite(ss.pins[G], LOW);
            break;
    }
}
