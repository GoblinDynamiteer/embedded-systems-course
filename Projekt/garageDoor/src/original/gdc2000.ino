bool up = false;
bool dn = up;
int sns = A0;
int l1 = 11;
int l0 = 10;
void setup() {
  
pinMode(9, OUTPUT);
pinMode(A0, INPUT);
pinMode(A4, OUTPUT);
}

void loop() {
  pinMode(9, OUTPUT);
  if (analogRead(sns) != 500)
  {
  if (dn == true)
      {
        for (int i = 0; i< 2000; i++)
        {
          if (digitalRead(l1) != true)
          {
            digitalWrite(9, HIGH);
            delayMicroseconds(1000);
            digitalWrite(9, LOW);
            delay(50);
            digitalWrite(9, HIGH);
            delayMicroseconds(1000);
            digitalWrite(9, LOW);
            delay(50);
            digitalWrite(9, HIGH);
            delayMicroseconds(1000);
            digitalWrite(9, LOW);
            delay(50);
          }
        }
        dn = false;
      }
  
    if (digitalRead(13) == HIGH)
      {
        up = true;
      }
    if ((dn != false) || (up == true))
      {
        digitalWrite(A4, HIGH);
      }
      
      if (digitalRead(12) == HIGH)
      {
        dn = true;
      }
      if (up == true)
      {
        for (int i = 0; i< 2000; i++)
        {
          if (digitalRead(10) == false)
          {
            digitalWrite(9, HIGH);
            delayMicroseconds(2000);
            digitalWrite(9, LOW);
            delay(50);
            digitalWrite(9, HIGH);
            delayMicroseconds(2000);
            digitalWrite(9, LOW);
            delay(50);
            digitalWrite(9, HIGH);
            delayMicroseconds(2000);
            digitalWrite(9, LOW);
            delay(50);
          }
          
        }
        up = false;
      }
  }
}
      
      

    

