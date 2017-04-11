#include <avr/io.h>

#define F_CPU 1000000ul
#include <util/delay.h>


void blinkLed(int n);

int main(void)
{
	DDRC = 0b00100000;
	DDRD = 0b00000100;
	
	PORTD = 0b00000100;
	
	//blinkLed(10);
	while (1) {
		if(PIND & (1 << PD5)){
			blinkLed(3);
		}
		if (PIND & (1 << PD3)){
			blinkLed(1);
		}
		_delay_ms(5);
    }
}

void blinkLed(int n){
	for(int i = 0; i < n; i++){
		 PORTC = 0b00100000;
		 _delay_ms(300);
		 PORTC = 0b00000000;
		 _delay_ms(300);
	}
}

