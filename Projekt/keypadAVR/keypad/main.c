/*	Keypad to AVR
	Atmega328p
	12 key keypad
	3x4 buttons
	*/


#include <avr/io.h>

/*	 Defined in project properties	*/
//#define F_CPU 1000000ul
#include <util/delay.h>

#define ROWS 3 // 4
#define COLS 3

void blinkLed(int n);
int checkPin(int pin);

/*	 Row pins - for toggling output	*/
enum {	ROW1_PIN = (0b00000100), 
		ROW2_PIN = (0b10000000), 
		ROW3_PIN = (0b01000000)
		};
		
/*	 Column pins - for checking input	*/
enum {	COL1_PIN = PD3,
		COL2_PIN = PD1,
		COL3_PIN = PD5
	};
	
int main(void){
	DDRC = 0b00100000; //LED Output
	DDRD = 0b11000100; //Column pins output
	
	int columnPin[3] = {COL1_PIN, COL2_PIN, COL3_PIN};
	int rowPin[3] = {ROW1_PIN, ROW2_PIN, ROW3_PIN};
	
	while(1){
		int num = 1;
		/*	 Set row output	*/
		for(int j = 0; j < ROWS; j++){
			 PORTD = rowPin[j];
			 _delay_ms(10);
			/*	 Check column input	*/
			for(int i = 0; i < COLS; i++){
				if(checkPin(columnPin[i])){
					blinkLed(num);
				}
				num++;
			}
		}
	}
}

/*	 Blink led n times	*/
void blinkLed(int n){
	for(int i = 0; i < n; i++){
		 PORTC = 0b00100000;
		 _delay_ms(200);
		 PORTC = 0b00000000;
		 _delay_ms(200);
	}
}

/*	 Check digital input on pin, returns 1 / 0	*/
int checkPin(int pin){
	return (PIND & (1 << pin));
}