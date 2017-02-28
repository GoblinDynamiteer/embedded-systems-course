#define PIN_IR 8

void setup(){
    pinMode(PIN_IR, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    morseS();
    morseO();
    morseS();
    digitalWrite(PIN_IR, LOW);
    delay(1000);
}

void morseS(){
    short_c();
    delay(100);
    short_c();
    delay(100);
    short_c();
    delay(100);
}

void morseO(){
    long_c();
    delay(100);
    long_c();
    delay(100);
    long_c();
    delay(100);
}

void long_c(void){
    digitalWrite(PIN_IR, HIGH);
    delay(1000);
    digitalWrite(PIN_IR, LOW);
}

void short_c(void){
    digitalWrite(PIN_IR, HIGH);
    delay(400);
    digitalWrite(PIN_IR, LOW);
}
