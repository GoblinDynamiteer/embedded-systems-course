#include <Button.h>

/*   Placeholder elevator car sensor, for floor    */
int elevatorCurrentFloor = 3;

enum {pincallButton1, pincallButton2, pincallButton3,
    pincallLED1, pincallLED2, pincallLED3,
    pinelevButton1, pinelevButton2, pinelevButton3,
    pinelevLED1, pinelevLED2, pinelevLED3
};


Button callButton1(pincallButton1);
Button callButton2(pincallButton2);
Button callButton3(pincallButton3);
Button elevButton1(pinelevButton1);
Button elevButton2(pinelevButton2);
Button elevButton3(pinelevButton3);

int elevatorFloorPosition();
void moveElevatorToFloor(int floor);
void callElevatorToFloor(int floor);

void moveElevatorToFloor(int floor){
    if(floor != elevatorFloorPosition()){
        elevatorCurrentFloor = floor;
    }
    delay(1000);
    digitalWrite(pinelevLED1, LOW);
    digitalWrite(pinelevLED2, LOW);
    digitalWrite(pinelevLED3, LOW);
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

int elevatorFloorPosition(){
    return elevatorCurrentFloor;
}

void callElevatorToFloor(int floor){

    digitalWrite(pincallLED1, LOW);
    digitalWrite(pincallLED2, LOW);
    digitalWrite(pincallLED3, LOW);
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
    moveElevatorToFloor(floor);
    delay(500);
    digitalWrite(pincallLED1, LOW);
    digitalWrite(pincallLED2, LOW);
    digitalWrite(pincallLED3, LOW);
}

void setup(){
    Serial.begin(9600);
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
    if(callButton1.pressed()){
        callElevatorToFloor(1);
    }
    else if(callButton2.pressed()){
        callElevatorToFloor(2);
    }
    else if(callButton3.pressed()){
        callElevatorToFloor(3);
    }

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
