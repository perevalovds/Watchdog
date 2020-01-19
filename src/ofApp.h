#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();

		int port_;
		float wait_time_;

		ofxOscReceiver osc_receiver_;
		float time_;	//last time received message
};
