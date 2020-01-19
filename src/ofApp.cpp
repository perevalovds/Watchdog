#include "ofApp.h"

extern vector<string> ARGS;

//--------------------------------------------------------------
void ofApp::setup(){
	cout << "----------------------------------------------" << endl;
	cout << "WatchDog 1.2 by Denis Perevalov, Digital Vitality Studio" << endl;
	cout << "command line has two arguments: OSC port and wait time" << endl;
	cout << "Program listen OSC messages. If no message arrived at given seconds," << endl;
	cout << "it closes (and normally causes restart due BAT file you are prepared" << endl;
	cout << "NOTE:  OSC message '/exit' causes exit code 1 - it's signal not to restart" << endl;
	//cout << "Press Esc to close program" << endl;
	cout << "----------------------------------------------" << endl;

	//Disabling ESC because it is sent to other oF apps!!!
	ofSetEscapeQuitsApp(false);	

	port_ = 12370;
	wait_time_ = 10;
	if (ARGS.size() < 3) {
		cout << "(Not enough command line arguments, so used defaults)" << endl;
	}
	else {
		port_ = ofToInt(ARGS[1]);
		wait_time_ = ofToFloat(ARGS[2]);
	}
	cout << "oscPortIn=" << port_ << ", waitSec=" << wait_time_ << endl;
	cout << "Now we opening port " << port_ << " for listening. If program crashes," 
	<< endl
	<< "it means that port is busy by another application, so change the port by command line argument..." << endl;
	osc_receiver_.setup(port_);
}

//--------------------------------------------------------------
void ofApp::update(){
	float time = ofGetElapsedTimef();
	bool received = false;
	while (osc_receiver_.hasWaitingMessages()) {
		ofxOscMessage m;
		osc_receiver_.getNextMessage(m);
		received = true;
		string address = m.getAddress();
		//cout << endl << "message " << address << endl;
		if (address == "/exit") {
			cout << "Watchdog received /exit signal, so exit without restarting" << endl;
			OF_EXIT_APP(1);
		}
	}
	if (received) {
		cout << ".";
		time_ = time;
	}
	if (time > time_ + wait_time_) {
		cout << endl;
		cout << "No OSC messages, Watchdog is exiting now (to restart your application)..." << endl;
		ofExit(0);
	}

	int sleep_ms = 250;	//Time for sleeping (so FPS=4)
	ofSleepMillis(sleep_ms);
}

//--------------------------------------------------------------

