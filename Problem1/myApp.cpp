/*This program was made to controll all four on board LEDs using a class
* The program will use all four LEDs having them do the same action
*    This program uses all four LEDS and can be executed in four ways:
*         makeLEDs on
*         makeLEDs off
*         makeLEDs flash  (flash at time delay intervals)
*         makeLEDs status (get the trigger status)
* Example invocation of this application is ./myApp.cpp on
* This will turn all four LEDs on
*/




#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "derek_LED.h"

using namespace std;

int main(int argc, char* argv[]){
   if(argc!=2){
     cout << " Usage is ./myApp <command>" << endl;
     cout << " command is one of: on, off, flash or status" << endl;
     cout << " e.g. ./myApp flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   for(int i=0; i<=3; i++){
      if(cmd=="on")leds[i].turnOn();
      else if(cmd=="off")leds[i].turnOff();
      else if(cmd=="flash")leds[i].flash("100"); //default is "50"
      else if(cmd=="status")leds[i].outputState();
      else{ cout << "Invalid command!" << endl; }
    }
    cout << "Finished the makeLEDs program" << endl;
    return 0;
}
