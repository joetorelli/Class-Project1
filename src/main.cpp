#include <Arduino.h>
#include <EEPROM.h>
void ShowLed(int Pin, int DelayPeriod, bool LedStatus);
// Set LED_BUILTIN if it is not defined by Arduino framework
// #define LED_BUILTIN 2

bool LedStatus = false;
int Period = 400;
int GlobalVar = 0;

void setup()
{

  Serial.begin(115200);
  Serial.println("Start");

  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // write a 0 to all 512 bytes of the EEPROM
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);
}

void loop()
{
  Serial.println("yyy");

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED_BUILTIN, HIGH);
  // wait for a second
  delay(1000);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED_BUILTIN, LOW);
  // wait for a second
  delay(1000);

  Serial.write('A');

  int LocalVar = 0;
  ShowLed(LED_BUILTIN, Period, LedStatus);
  LedStatus = !LedStatus;
  GlobalVar++;
  LocalVar++;
  Serial.print("LocalVar= ");
  Serial.println(LocalVar);
}

void ShowLed(int Pin, int DelayPeriod, bool LedStatus)
{
  int FunctionVar = 0;
  if (LedStatus)
  {
    digitalWrite(Pin, HIGH);
  }
  else
  {
    digitalWrite(Pin, LOW);
  }
  delay(Period);
  FunctionVar++;
  Serial.print("FuncVar= ");
  Serial.println(FunctionVar);
}