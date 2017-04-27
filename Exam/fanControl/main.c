/*
 * fanControl.c
 *
 * Created: 2017-04-27
 * Author : Johan Kämpe
 */

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

/*   Fan speeds    */
#define OFF 0
#define MAX_SPEED 10
enum{
    LED1_PIN = PD2, //index 0
    LED2_PIN = PD3, //index 1
    LED3_PIN = PD4, //index 2
    LED4_PIN = PD5, //index 3
    LED5_PIN = PD6, //index 4
    LED6_PIN = PD7, //index 5
    LED7_PIN = PB0, //index 6
    LED8_PIN = PB1, //index 7
    LED9_PIN = PB2, //index 8
    LED10_PIN = PB4 //index 9
    };

int ledPins[10] = {
    LED1_PIN,
    LED2_PIN,
    LED3_PIN,
    LED4_PIN,
    LED5_PIN,
    LED6_PIN, //index 5
    LED7_PIN, //index 6
    LED8_PIN,
    LED9_PIN,
    LED10_PIN //index 9
};
int fanRunning = 0;
#define MIN_DUTY_CYCLE (255 * 0.25)
#define DUTY_CYCLE_STEPS ((255 - MIN_DUTY_CYCLE) / 10)
#define FAN_PIN PB3 //Arduino pin D11 - OC2A PWM
//#define ON_BUTTON PC0
//#define OFF_BUTTON PC1 // EV SWAP

#define ON_BUTTON PC1
#define OFF_BUTTON PC0 // EV SWAP

int checkPin(int pin);
void setLedIndicator(int n);
void setFanSpeed(int n);

int main(void){
    //DDRC &= ~(1 << ON_BUTTON);
    //DDRC &= ~(1 << OFF_BUTTON);
    DDRC = (0b00000000); //Read
    PORTC = 0xFF;
    DDRD = (0b11111111); //Write
    DDRB = (0b11111111); //Write
    //DDRB |= (1<<LED8_PIN) | (1<<LED9_PIN) | (1<<LED10_PIN) | (1<<FAN_PIN);
    int fanSpeed = OFF;
    int updateSetting = 0;
    /*  Test leds */
    for(int i = 1; i <= 10; i++){
        setLedIndicator(i);
        _delay_ms(200);
    }
    _delay_ms(1000);
    /*   Main loop    */
    while (1){
        if(!checkPin(ON_BUTTON)){
            if(fanSpeed != MAX_SPEED){
                fanSpeed++;
                updateSetting = 1;
           }
        }

        else if(!checkPin(OFF_BUTTON)){
            if(fanSpeed != OFF){
                fanSpeed--;
                updateSetting = 1;
            }
        }

        if(updateSetting){
            setFanSpeed(fanSpeed);
            setLedIndicator(fanSpeed);
            updateSetting = 0;
            _delay_ms(200);
        }
    }
}

/*	 Check digital input on pin, returns 1 / 0	*/
int checkPin(int pin){
    int check = (PINC & (1 << pin));
	//return (PINC & (1 << pin));
    return (check > 0);
}

/*   Set fan speed via PWM?! */
void setFanSpeed(int n){
    uint8_t dutyCycle;
    dutyCycle = n * DUTY_CYCLE_STEPS + MIN_DUTY_CYCLE;
    if(!n){
        DDRB &= ~(1 << FAN_PIN);
        dutyCycle = 0x00;
        fanRunning = 0;
    }
    if(n == 1 && !fanRunning){
        DDRB |= (1 << FAN_PIN);
        _delay_ms(700);
        fanRunning = 1;
    }
    if(n == MAX_SPEED){
        dutyCycle = 255;
    }
    OCR2A = dutyCycle; //0-255
    TCCR2A |= (1 << COM2A1);
    // set none-inverting mode
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    // set fast PWM Mode
    TCCR2B |= (1 << CS21);
    // set prescaler to 8 and starts PWM
}

void setLedIndicator(int n){
    /*   Set LEDs off    */
    PORTD = 0x00;
    PORTB &= (0b11101000);

    /*    Skip loop   */
    if(n == OFF){
        return;
    }
    /*  Set LEDs on     */
    for(int i = 0; i < n; i++){
        if(i < 6){
            PORTD |= (1 << ledPins[i]);
        }
        else{
            PORTB |= (1 << ledPins[i]);
        }
    }
}
