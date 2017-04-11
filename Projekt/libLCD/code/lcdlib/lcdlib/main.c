
/*	 Pins
	LCD pin 0-7:	PD0-7
	E:				PB6
	RS				PB7	*/

#include <avr/io.h>
#define F_CPU 1000000

#include <util/delay.h>

#define RSPIN	7
#define EPIN	6

void toggleE(){
	PORTB |= (1<<EPIN);
	_delay_us(1);
	PORTB &= ~(1<<EPIN);
	_delay_us(1);
}

void clearDisplay(){
	PORTB &= ~(1<<RSPIN);
	_delay_us(1);
	PORTD = 0b00000001; //Clear display
	_delay_ms(2);
	toggleE();
}


int main(void)
{
	/*	 Set pins as write!		*/
	DDRD = 0b11111111; //0xff
	DDRB = 0b11000000; //0xc0	
	PORTB = 0b00000000; //set all b ports off
	PORTD = 0x0C; //Set display on
	_delay_ms(1);
	toggleE();
	clearDisplay();
	int counter = 16;
    while (1) {	
		PORTB |= (1<<RSPIN);
		//7 6 5 4 3 2 1 0
		PORTD = 0b00001111;
		_delay_ms(1);
		toggleE();
		_delay_ms(100);
		if(!counter--){
			clearDisplay();
			counter = 16;
		}
    }
}

