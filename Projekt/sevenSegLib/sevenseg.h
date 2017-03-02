/*    sevenseg.h
    for seven segment display

    */

#include "Arduino.h"

#ifndef _SEVENSEG_H_
#define _SEVENSEG_H_

enum {A, B, C, D, E, F, G};
#define MAXPINS 7

/*    Struct for holding segment pins   */
typedef struct _SEG{
    int pins[MAXPINS];
}sseg;

sseg ssegInit(int a, int b, int c, int d, int e, int f, int g);
void ssegTest(sseg ss);
void ssegDisplay(int i);

#endif // _SEVENSEG_H_
