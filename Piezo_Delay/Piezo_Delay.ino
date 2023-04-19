#include <TimerOne.h>
int cnt = 0;
const int BUZZER = 10;

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);
  for (int i = 1; i < 6; i++) {
    for (int j = 1; j < 6; j++) {
      delay(200*i);
      Timer1.setPwmDuty(BUZZER, 100*i);
      Timer1.setPeriod(1000000 / 262);
      delay(200);
      cnt++;
      Serial.print("COUNT : ");
      Serial.println(cnt);
      Timer1.setPwmDuty(BUZZER, 0);
    }
    delay(1000);
  }
}

void loop() {
}