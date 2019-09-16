#include "Watchdog.h"
#include "ofxOsc.h"

Watchdog WATCHDOG;

//--------------------------------------------------------------
void Watchdog::update(int port, float period_sec) {
	float time = ofGetElapsedTimef();
	if (time >= time_ + period_sec) {
		time_ = time;
		send(port, "/bang");
	}
}

//--------------------------------------------------------------
void Watchdog::send_exit(int port) {
	send(port, "/exit");
}

//--------------------------------------------------------------
void Watchdog::send(int port, const string &command) {
	ofxOscMessage m;
	m.setAddress(command);
	ofxOscSender sender;
	sender.setup("localhost", port);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
