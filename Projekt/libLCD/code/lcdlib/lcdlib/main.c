
/*	 Pins
	LCD pin 0-7:	PD0-7
	E:				PB6
	RS				PB7	*/

#include <avr/io.h>
#define F_CPU 1000000

#include <util/delay.h>

#define RSPIN	PB7
#define EPIN	PB6

int main(void)
{
	/*	 Set pins as write!		*/
	DDRD = 0b11111111; //0xff
	DDRB = 0b11000000; //0xc0

    while (1) {	
		PORTB = 0x00;
	    PORTB |= RSPIN;
	    PORTB |= EPIN;
	    _delay_ms(1);
	    //PORTB = 0x00;
	    PORTD = 0b00000011;
	    _delay_ms(1);
    }
}

