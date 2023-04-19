const int interruptPin = 8;//인터럽트핀
extern volatile unsigned long timer0_millis; //타이머변수
unsigned long timeVal = 0; //이전시간
unsigned long millisTime = 0; //현재시간

int d1, d2, d3, d4;//자리 숫자
boolean state = false;//타이머 동작 제어 

void setup()
{
  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), switchFn, FALLING);

  timeVal=0;
}

void loop()
{
  if(state==true){ //카운트 시작
    if(millis()-timeVal>=1000){ //1초단위로 시작
      timeVal=millis();
      millisTime = millis()/1000;
      d1 = millisTime%10; //1의 자리
      d2 = (millisTime/10)%10;//10의 자리
      d3 = (millisTime/100)%10;//100의 자리
      d4 = (millisTime/1000)%10;//1000의 자리

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
  timer0_millis=0; //타이머변수 리셋
  timeVal=0;
}