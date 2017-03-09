
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
        Simulate door opening
        Simulate door locks

   */


#include <Button.h> // for button handling

/*   Placeholder sensors   */
int elevatorCurrentFloor = 3;
int emergencyStopEngaged = 0;
int emergencySignalEngaged = 0;
int motorRunning = 0;
unsigned long timer; //for motor/elevator car simulation

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
enum {pincallButton1, pincallButton23 /*  CHANGE TO BUTTON 2!!!! */, pincallButton3,
    pincallLED1, pincallLED2, pincallLED3,
    pinelevButton1, pinelevButton2, pinelevButton3,
    pinelevLED1, pinelevLED2, pinelevLED3
};

/*  Misc macros   */
enum {FALSE, TRUE};

#define NUM_FLOORS 3
#define pincallButton2 12 //REMOVE!!!!!
#define CAR_MOVEMENT_TIME 2000 //for motor/elevator car simulation

/*    Init buttons   */
Button callButton1(pincallButton1);
Button callButton2(pincallButton2);
Button callButton3(pincallButton3);
Button elevButton1(pinelevButton1);
Button elevButton2(pinelevButton2);
Button elevButton3(pinelevButton3);

/*   Elevator car queue  */
int carQueue[NUM_FLOORS];

/*    Function prototypes   */
/*    Elevator car function prototypes */
int elevatorFloorPosition();
void moveElevatorToFloor(int floor);
int getButtons(void);

/*   Safety function prototypes  */
int isEmergencyStopEngaged(void);
int isEmergencySignalEngaged(void);


/*   LED function prototypes  */
void setIndicatorLED(int floor);
void setCallButtonLEDOn(int floor);
void setCallButtonLEDOff(int floor);

/*   Elevator car queue function prototypes  */
void addToCarQueue(int floor);
void handleCarQueue(void);
void removeFromCarQueue(int floor);


/*   Moves elevator car to passed floor    */
void moveElevatorToFloor(int floor){
    /*   If elevator var is not already at the correct floor,
        set elevator car positon to the passed floor number */
    if(floor != elevatorFloorPosition()){
        elevatorCurrentFloor = floor;
    }
    setIndicatorLED(floor);
    setCallButtonLEDOff(floor);
}

/*   Add floor to elevator car queue  */
void addToCarQueue(int floor){
  for(int i = 0; i < NUM_FLOORS; i++){
    /*  Don't add floor already in queue   */
    if((carQueue[i] == 0) && (carQueue[i] != floor)){
      Serial.print("Adding floor to queue: ");
      Serial.println(floor);
      carQueue[i] = floor;
      break;
    }
  }
}

/*   Remove floor from car queue,
  elevator has arrived at this floor  */
void removeFromCarQueue(int floor){
  for(int i = 0; i < NUM_FLOORS; i++){
    if(carQueue[i] == floor){
      carQueue[i] = 0;
    }
  }
}

/*     */
void handleCarQueue(void){
  int nextFloor = 0;
  for(int i = 0; i < NUM_FLOORS; i++){
    if(carQueue[i] != 0){
      nextFloor = carQueue[i];
      break;
    }
  }
  if(nextFloor != 0){
    Serial.print("Going to floor: ");
    Serial.println(nextFloor);
    moveElevatorToFloor(nextFloor);
    removeFromCarQueue(nextFloor);
  }
}

/*  Turns elevator car indicator LED on   */
void setIndicatorLED(int floor){
  /*   Turn off LEDs that indicate elevator car position    */
  for(int ledPin = pinelevLED1;
      ledPin < pinelevLED1 + NUM_FLOORS; ledPin++){
        digitalWrite(ledPin, LOW);
  }
  /*   Turn on LED for new elevator car floor positon    */
      digitalWrite(pinelevLED1 + floor - 1, HIGH);
}

/*  Turns call button indicator LED on   */
void setCallButtonLEDOn(int floor){
      digitalWrite(pincallLED1 + floor - 1, HIGH);
}

/*  Turns call button indicator LED on   */
void setCallButtonLEDOff(int floor){
      digitalWrite(pincallLED1 + floor - 1, LOW);
}

/*    Returns elevetor car floor position   */
int elevatorFloorPosition(){
    return elevatorCurrentFloor;
}

/*  Returns 1/0 for emergency stop status   */
int isEmergencyStopEngaged(void){
  return emergencyStopEngaged;
}

/*  Returns 1/0 for emergency signal status   */
int isEmergencySignalEngaged(void){
  return emergencySignalEngaged;
}

void setup(){
    /*   Set pinmode for LED pins and start buttons    */
    for(int i = 0; i < NUM_FLOORS; i++){
      pinMode(pincallLED1 + i, OUTPUT);
      pinMode(pinelevLED1 + i, OUTPUT);
      /*  NULL elevator car queue   */
      carQueue[i] = 0;
    }
    /*   Elevator car start floor, middle of building  */
    carQueue[0] = NUM_FLOORS / 2 + 0.5;
    callButton1.begin();
    callButton2.begin();
    callButton3.begin();
    elevButton1.begin();
    elevButton2.begin();
    elevButton3.begin();
    Serial.begin(9600);
}

void loop(){
  if(isEmergencyStopEngaged() != 1){
    if(motorRunning == 0){
      motorRunning = 1;
      timer = millis();
      handleCarQueue();
    }
    if(millis() - timer > CAR_MOVEMENT_TIME){
      motorRunning = 0;
    }
    int gotoFloor = getButtons();
    if(gotoFloor != 0){
      addToCarQueue(gotoFloor);
    }
  }
}

/*   Checks elevator car buttons and call buttons
    returns corresponding floor to move elevator car to */
int getButtons(void){
  int gotoFloor = 0;
  /*   Elevator call buttons    */
  if(callButton1.pressed() == TRUE){  gotoFloor = 1;  }
  if(callButton2.pressed() == TRUE){  gotoFloor = 2;  }
  if(callButton3.pressed() == TRUE){  gotoFloor = 3;  }

  /*  Lights call button LED, if pressed   */
  if(gotoFloor != 0){ setCallButtonLEDOn(gotoFloor);  }

  /*   Elevator car buttons    */
  if(elevButton1.pressed() == TRUE){  gotoFloor = 1;  }
  if(elevButton2.pressed() == TRUE){  gotoFloor = 2;  }
  if(elevButton3.pressed() == TRUE){  gotoFloor = 3;  }

  return gotoFloor;
}
