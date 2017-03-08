/*    GDC 2000
    Electrical Garage Control


    Johan Kämpe
    Mjukvaruutvecklare inbyggda system
    kurs: Programmering av inbyggda system
   */


enum {DOWN, UP}; // 0 1
enum {OFF, ON}; // 0 1
enum {CLOSED, OPEN}; // 0 1

#define btnOpenDoor 13 // pin for open button
#define btnCloseDoor 12 //pin for close button
#define servoDoor 9 //pin for servo
#define breakerUpper 11 //pin for upper door breaker
#define breakerLower 10 //pin for lower door breaker
#define SENSOR_TRIGGER_MIN 500 //Minimum value for safety sensor trigger

/*   Pulse widths for servo, opening and closing door    */
#define SERVO_PULSE_DOWN 2000
#define SERVO_PULSE_UP 1000
#define SERVO_PULSE_CYCLES 6000

bool doorState = CLOSED;
int sensorDoor = A3; //pin for door safety sensoer
int indicatorLED = A4; //pin for indicator LED

/*   Function prototypes    */
void operateDoor(int upDown);
void setIndicatorLED(int onOff);
int safetySensor();
int checkBreaker(int upLow);

void setup(){
    pinMode(servoDoor, OUTPUT);
    pinMode(sensorDoor, INPUT);
    pinMode(indicatorLED, OUTPUT);
}

void loop(){
    /*   Down button is pressed and door state is open    */
    if (digitalRead(btnCloseDoor) &&
        doorState == OPEN){
            setIndicatorLED(ON);
            /*   Operate door while safety sensor is not triggering,
                and the lower door breaker isn't triggered */
                while(safetySensor() && !checkBreaker(DOWN)){
                    operateDoor(DOWN);
                }
            doorState = CLOSED;
            setIndicatorLED(OFF);
    }
    /*   Up button is pressed and door state is closed    */
    else if (digitalRead(btnOpenDoor) &&
        doorState == CLOSED){
            setIndicatorLED(ON);
            /*   Operate door while safety sensor is not triggering,
                and the upper door breaker isn't triggered */
            while(safetySensor() && !checkBreaker(UP)){
                operateDoor(UP);
            }
            doorState = OPEN;
            setIndicatorLED(OFF);
    }
}

void operateDoor(int upDown){
    /*  Servo pulse width determines direction */
    int pulseWidth;
    if(upDown == UP){
        pulseWidth = SERVO_PULSE_UP;
    }
    else if(upDown == DOWN){
        pulseWidth = SERVO_PULSE_DOWN;
    }
    /*    Send pulses to servo    */
    for(int i = 0; i < SERVO_PULSE_CYCLES; i++){
        /*    Break servo movement if safety sensor trigger   */
        if(safetySensor()){
            break;
        }
        digitalWrite(servoDoor, HIGH);
        delayMicroseconds(pulseWidth);
        digitalWrite(servoDoor, LOW);
        delay(50);
    }
}
/*  Set the indicator LED on or off */
void setIndicatorLED(int onOff){
    digitalWrite(indicatorLED, onOff);
}
/*   Checks safety sensor, return 1 if below trigger limit    */
int safetySensor(){
    return (analogRead(sensorDoor) < SENSOR_TRIGGER_MIN);
}

/*    Checks upper and lower breakers   */
int checkBreaker(int upLow){
    if(upLow = UP){
        return digitalRead(breakerUpper);
    }
    else if(upLow = DOWN){
        return digitalRead(breakerLower);
    }
}
