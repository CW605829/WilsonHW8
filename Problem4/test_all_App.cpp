/* This code tests the classes GPIO,LED, and analogIn
* This code will go through and make objects of each LED and pin p8.16 and p9.12
* as well as analog pin 0
* the code will go through turn on LED 1 and 3 flash LED 2
* the code will then read the analog pin 0
* the code will then read p8.16 and turn p9.12 high if the button is pressed
* example invocation is ./tester with no command line arguments
*/



#include<iostream>
#include "derek_LED.h"
#include "GPIO.h"
#include "analogIn.h"

using namespace std;
using namespace exploringBB;

int main(int argc, char* argv[]){
  LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
  leds[1].turnOff();
  leds[2].turnOff();
  leds[3].turnOff();
  leds[0].turnOff();
  leds[1].turnOn();
  leds[3].turnOn();
  leds[2].flash("100");
  AnalogIn pin0(0);
  int ADC = pin0.readAdcSample();
  cout << "The current value of pin0 is " << ADC << endl;
  GPIO inGPIO(46);
  GPIO outGPIO(60);
  inGPIO.setDirection(INPUT);
  inGPIO.setEdgeType(RISING);
  outGPIO.setDirection(OUTPUT);
  cout << "GPIO(46) has value: " << inGPIO.getValue() << endl;
  if(inGPIO.getValue()==1){
    outGPIO.setValue(HIGH);
  }
}
