#include <avr/io.h>

//#define F_CPU 1000000ul
#include <util/delay.h>

void blinkLed(int n);
int checkPin(int pin);

/*	 Row pins	*/
enum {	ROW1_PIN = (0b00000100), 
		ROW2_PIN = (0b10000000), 
		ROW3_PIN = (0b01000000)
		};
		
/*	 Column pins	*/
enum {	COL1_PIN = PD3,
		COL2_PIN = PD1,
		COL3_PIN = PD5
	};
	
int main(void){
	DDRC = 0b00100000; //LED Output
	DDRD = 0b11000100;
	
	int columnPin[4] = {0, COL1_PIN, COL2_PIN, COL3_PIN};
	int rowPin[4] = {0, ROW1_PIN, ROW2_PIN, ROW3_PIN};
	
	//blinkLed(10);
	while(1){
		int num = 1;
		for(int j = 1; j <= 3; j++){
			 PORTD = rowPin[j];
			 _delay_ms(10);
			for(int i = 1; i <= 3; i++){
				if(checkPin(columnPin[i]))	{blinkLed(num);	}
				num++;
			}
		}
	}
}

void blinkLed(int n){
	for(int i = 0; i < n; i++){
		 PORTC = 0b00100000;
		 _delay_ms(200);
		 PORTC = 0b00000000;
		 _delay_ms(200);
	}
}

int checkPin(int pin){
	return (PIND & (1 << pin));
}