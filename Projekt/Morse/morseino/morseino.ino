/*   Programmering av inbyggda system
 *  "Morse"
 *   Send letters as morse code via LED/IR-LED
*/

#define PIN_IR 8

void sendMorse(char text[]);

void setup(){
    pinMode(PIN_IR, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    digitalWrite(PIN_IR, LOW);
    sendMorse("sos");
}

/*    Send text string as morse code */
void sendMorse(char text[]){
    for(int i = 0; i < strlen(text); i++){
        Serial.print(text[i]);
        switch(tolower(text[i])){
            case 's':
                morseS();
                break;
            case 'o':
                morseO();
                break;
            default:
                break;
        }
    }
    Serial.println("_");
}

/*    Ouput of letter S in morse code   */
void morseS(){
    short_c();
    short_c();
    short_c();
    delay(2000);
}

/*    Ouput of letter O in morse code   */
void morseO(){
    long_c();
    long_c();
    long_c();
    delay(2000);
}

/*    Send "long"   */
void long_c(void){
    digitalWrite(PIN_IR, HIGH);
    delay(1000);
    digitalWrite(PIN_IR, LOW);
}

/*    Send "short"   */
void short_c(void){
    digitalWrite(PIN_IR, HIGH);
    delay(400);
    digitalWrite(PIN_IR, LOW);
}
