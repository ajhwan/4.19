const int interruptPin = 2; //PWM
extern volatile unsigned long timer0_millis; 
unsigned long timeVal = 0;
unsigned long millisTime = 0; 

int d1, d2, d3, d4;
boolean state = false;

void setup()
{
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), switchFn, FALLING);

  timeVal=0;
}

void loop()
{
  if(state==true){ 
    if(millis()-timeVal>=1000){ 
      timeVal=millis();
      millisTime = millis()/1000;
      d1 = millisTime%10; 
      d2 = (millisTime/10)%10;
      d3 = (millisTime/100)%10;
      d4 = (millisTime/1000)%10;

      Serial.print(d4);
      Serial.print(" : ");
      Serial.print(d3);
      Serial.print(" : ");
      Serial.print(d2);
      Serial.print(" : ");
      Serial.println(d1);       
    }
  } 
}

void switchFn(){
  state=!state;
  timer0_millis=0;
  timeVal=0;
}
