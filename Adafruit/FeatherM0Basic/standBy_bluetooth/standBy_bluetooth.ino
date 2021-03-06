#define INTREVAL (3)
#define VBATPIN A7

#include <RTCZero.h>

#define PIN_TSW (5)
#define PIN_LED (6)

RTCZero rtcZERO;
unsigned long aCounter = 0;
int alarmSS = 0;

void onTSW() {
  aCounter = 0;
}

void setup()
{
  Serial1.begin(115200);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  pinMode(PIN_TSW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_TSW), onTSW, FALLING);

  rtcZERO.begin();
  alarmSS = rtcZERO.getSeconds();
  rtcZERO.attachInterrupt(alarmSR);
  rtcZERO.enableAlarm(rtcZERO.MATCH_SS);
}

void loop()
{
  float measuredvbat = analogRead(VBATPIN);
  measuredvbat *= 2;    // we divided by 2, so multiply back
  measuredvbat *= 3.3;  // Multiply by 3.3V, our reference voltage
  measuredvbat /= 1024; // convert to voltage

  String line = "at " + String(aCounter) + " " + "VB=" + String(measuredvbat,2);
  Serial1.println(line);
//  
  rtcZERO.setAlarmSeconds(alarmSS = (alarmSS + INTREVAL) % 60);
  rtcZERO.standbyMode();
}

void alarmSR() // alarm Service Routine
{
  digitalWrite(PIN_LED, (aCounter) % 2);
  aCounter++;
}
