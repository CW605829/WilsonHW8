/* This application will create a object from the class AnalogIn
*The object will be used to show the value on the chosen analog pin  
*The pin tested through example will be analog pin 0
*The functions used in this application and other functions are in AnalogIn
*can be found in analogIn.h and implemented in analogIn.cpp
* example invocation is ./test_analog 0 this makes an object that connects to
* analog pin 0
*/



#include <iostream>
#include <sstream>
#include <fstream>
#include "analogIn.h"

using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

int main(int argc, char* argv[]){
  AnalogIn pin0(atoi(argv[1]));
  cout << "The default value of pin0 is " << pin0.getNumber() << endl;
  int ADC = pin0.readAdcSample();
  cout << "The new value of pin0 is " << ADC << endl;

}
