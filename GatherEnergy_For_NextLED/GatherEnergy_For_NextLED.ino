#include <TimerOne.h>

const int LED1 = 6;
const int LED2 = 9;
const int LED3 = 10;
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(LED2, 0);
  Timer1.pwm(LED3, 0);
  Timer1.setPeriod(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int t_high=0;t_high<=1023;t_high++) {
    Timer1.setPwmDuty(LED2, t_high);
    delay(1);
    if (t_high == 1023){
      cnt++;
    }
  }
  if (cnt > 0){
    Timer1.setPwmDuty(LED3, 100*cnt);
    if (cnt == 10){
      cnt = 0;
      Timer1.setPwmDuty(LED3, 0);
    }
  }
}
