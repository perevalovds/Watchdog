#include "ofApp.h"

extern vector<string> ARGS;

//--------------------------------------------------------------
void ofApp::setup(){
	cout << "----------------------------------------------" << endl;
	cout << "WatchDog 1.1 by Denis Perevalov, eamuseum.com" << endl;
	cout << "command line has two arguments: OSC port and wait time" << endl;
	cout << "Program listen OSC messages. If no message arrived at given seconds," << endl;
	cout << "it closes (and normally causes restart dua BAT file you are prepared" << endl;
	cout << "NOTE:  OSC message '/exit' causes exit code 1 - it's signal not to restart" << endl;
	cout << "Press Esc to close program" << endl;
	cout << "----------------------------------------------" << endl;

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
		if (m.getAddress() == "/exit") {
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
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
