/*
 * GccApplication1.c
 *
 * Created: 2017-03-14 10:16:11
 * Author : Johan Kampe
 */

/*   Needed for delay.h    */
#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /*   Set PB3 to be output    */
    DDRB = 0b00001000;
    /*    Loop   */
    while (1){
        PORTB = 0b00001000;
        _delay_ms(1000);
        PORTB = 0b00000000;
        _delay_ms(1000);
    }
}
