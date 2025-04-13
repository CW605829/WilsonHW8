/*This program was made to controll all four on board LEDs using a class
* The program will use all four LEDs having them do the same action
*    This program uses all four LEDS and can be executed in five  ways:
*         makeLEDs on
*         makeLEDs off
*         makeLEDs flash  (flash at time delay intervals)
*         makeLEDs status (get the trigger status)\
*         makeLEDs blink n (n is the number of time it will blink)
* Example invocation of this application is ./myblink.cpp on
* This will turn all four LEDs on
*/




#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "derek_LED.h"

using namespace std;

int main(int argc, char* argv[]){
   if(argc!=2 && argc!=4){
     cout << " Usage is ./myblink <command>" << endl;
     cout << " command is one of: on, off, flash or status" << endl;
     cout << " e.g. ./myblink flash" << endl;
     cout << " e.g. ./myblink blink (num of LED) (number) " << "The number put will be the amount of blinks"  << endl;
   }
   if(argc==2){
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
   }
   else if(argc==4){
    cout << "Starting the makeLEDs program" << endl;
    string cmd(argv[1]);
    LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
        if(cmd=="blink")leds[atoi(argv[2])].blink(atoi(argv[3]));
    cout << "Finished the makeLEDs program" << endl;
    return 0;
  }
}
