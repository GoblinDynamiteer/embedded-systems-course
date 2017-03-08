
/*    Elevator project

    Dylan Saleh
    Johan Kämpe
    Mjukvaruutecklare inbyggda system
    Kurs Programmering av inbyggda system

    Coding project that simulates an elevator.

    Delays are used in the code to simulate
    elevator car movement.

    Todo:
        Break down code into functions
        Add emergency stop / signal
        Elevator care movement Queue
        Simulate motor

   */


#include <Button.h> // for button handling

/*   Placeholder elevator car sensor, for current floor    */
int elevatorCurrentFloor = 3;

/*    Pinout for LEDs and buttons
        callButton:     Button outside of elevator shaft that
                        calls the elevator car to the floor.
        callLED:        LED-signal to indicate that the elevator
                        car is queued to go to that floor.
        elevButtons:    Buttons inside to elevator car, used to move
                        the car to another floor.
        elevLED         LEDs used to indicate on what floor the elevator
                        car is currently at.
 */
enum {pincallButton1, pincallButton2, pincallButton3,
    pincallLED1, pincallLED2, pincallLED3,
    pinelevButton1, pinelevButton2, pinelevButton3,
    pinelevLED1, pinelevLED2, pinelevLED3
};

/*    Init buttons   */
Button callButton1(pincallButton1);
Button callButton2(pincallButton2);
Button callButton3(pincallButton3);
Button elevButton1(pinelevButton1);
Button elevButton2(pinelevButton2);
Button elevButton3(pinelevButton3);

/*    Function prototypes   */
int elevatorFloorPosition();
void moveElevatorToFloor(int floor);
void callElevatorToFloor(int floor);

/*   Moves elevator car to passed floor    */
void moveElevatorToFloor(int floor){
    /*   If elevator var is not already at the correct floor,
        set elevator car positon to the passed floor number */
    if(floor != elevatorFloorPosition()){
        elevatorCurrentFloor = floor;
    }
    delay(1000);
    /*   Turn of LEDs that indicate elevator car position    */
    digitalWrite(pinelevLED1, LOW);
    digitalWrite(pinelevLED2, LOW);
    digitalWrite(pinelevLED3, LOW);
    /*   Turn on LED for new elevator car floor positon    */
    if(floor == 1){
        digitalWrite(pinelevLED1, HIGH);
    }
    else if(floor == 2){
        digitalWrite(pinelevLED2, HIGH);
    }
    else{
        digitalWrite(pinelevLED3, HIGH);
    }
}

/*    Returns elevetor car floor position   */
int elevatorFloorPosition(){
    return elevatorCurrentFloor;
}

/*    Function that calls elevator to a floor.   */
void callElevatorToFloor(int floor){
    /*   Turn of LEDs   */
    digitalWrite(pincallLED1, LOW);
    digitalWrite(pincallLED2, LOW);
    digitalWrite(pincallLED3, LOW);
    /*    Turn on correct callLED   */
    if(floor == 1){
        digitalWrite(pincallLED1, HIGH);
    }
    else if(floor == 2){
        digitalWrite(pincallLED2, HIGH);
    }
    else{
        digitalWrite(pincallLED3, HIGH);
    }
    delay(1000);
    /*   Moves the elevator car to the correct floor and turn off callLEDs   */
    moveElevatorToFloor(floor);
    delay(500);
    digitalWrite(pincallLED1, LOW);
    digitalWrite(pincallLED2, LOW);
    digitalWrite(pincallLED3, LOW);
}

void setup(){
    /*   Set pinmode for LED pins and start buttons    */
    pinMode(pincallLED1, OUTPUT);
    pinMode(pincallLED2, OUTPUT);
    pinMode(pincallLED3, OUTPUT);
    pinMode(pinelevLED1, OUTPUT);
    pinMode(pinelevLED2, OUTPUT);
    pinMode(pinelevLED3, OUTPUT);
    callButton1.begin();
    callButton2.begin();
    callButton3.begin();
    elevButton1.begin();
    elevButton2.begin();
    elevButton3.begin();
}

void loop(){
    /*   loop for elevator call buttons    */
    if(callButton1.pressed()){
        callElevatorToFloor(1);
    }
    else if(callButton2.pressed()){
        callElevatorToFloor(2);
    }
    else if(callButton3.pressed()){
        callElevatorToFloor(3);
    }

    /*   loop for elevator buttons    */
    if(elevButton1.pressed()){
        moveElevatorToFloor(1);
    }
    else if(elevButton2.pressed()){
        moveElevatorToFloor(2);
    }
    else if(elevButton3.pressed()){
        moveElevatorToFloor(3);
    }
}
