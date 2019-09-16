#pragma once

//Sending signals to Watchdog
//Requires ofxOsc addon
/*Usage:

See example of BAT-file in example-usage (there are example for Pure Data).

in ofApp::update()
   WATCHDOG.update(12370, 2);	//Update watchod; params are OSC port and period in seconds

in ofApp::exit()
  //Ideally, you should just send exit signal when exiting, but it's not come from oF...
  //WATCHDOG.send_exit();		
  //So, terminate it manually - close BAT-file
  system("taskkill /im cmd.exe /f");

*/

#include "ofMain.h"


struct Watchdog {
	//Call this each ofApp::update() to regularly send messages to Watchdog
	void update(int port, float period_sec);
	
	//Call this when normal exiting to disable Watchdog
	void send_exit(int port);
protected:
	float time_ = -10000;

	void send(int port, const string &command);
};

extern Watchdog WATCHDOG;

