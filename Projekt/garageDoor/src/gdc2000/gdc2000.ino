
enum {DOWN, UP}; // 0 1
enum {OFF, ON}; // 0 1
enum {CLOSED, OPEN}; // 0 1

#define btnOpenDoor 13 // pin for open button
#define btnCloseDoor 12 //pin for close button
#define servoDoor 9 //pin for servo
#define breakerUpper 11 //pin for upper door breaker
#define breakerLower 10 //pin for lower door breaker
#define SENSOR_TRIGGER_MIN 500 //Minimum value for safety sensor trigger
#define SERVO_PULSE_CYCLES 6000

/*   Pulse widths for servo, opening and closing door    */
#define SERVO_PULSE_DOWN 2000
#define SERVO_PULSE_UP 1000


bool doorState = CLOSED;
int sensorDoor = A3; //pin for door safety sensoer
int indicatorLED = A4; //pin for indicator LED

/*   Function prototypes    */
void operateDoor(int upDown);
void setIndicatorLED(int onOff);

void setup() {
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
            while(analogRead(sensorDoor) < SENSOR_TRIGGER_MIN
                && !digitalRead(breakerLower)){
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
            while(analogRead(sensorDoor) < SENSOR_TRIGGER_MIN
                && !digitalRead(breakerUpper)){
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
        digitalWrite(servoDoor, HIGH);
        delayMicroseconds(pulseWidth);
        digitalWrite(servoDoor, LOW);
        delay(50);
    }
}
/*  Set the indicator LED on or off */
void setIndicatorLED(int onOff){
    digitalWrite(A4, onOff);
}
