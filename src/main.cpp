#include "ofMain.h"
#include "ofApp.h"
#include "ofAppNoWindow.h"


//Command line arduments
vector<string> ARGS;

//for usage in ofApp.cpp - write there:
//extern vector<string> ARGS;

//========================================================================
int main(int argc, char *argv[]) {
	ARGS.resize(argc);
	for (int i = 0; i < argc; i++) {
		ARGS[i] = argv[i];
		//cout << "---" << ARGS[i] << endl;
	}

	//Windowless application
	// if you want to see the window	
	// comment these two lines 
	ofAppNoWindow window;
	ofSetupOpenGL(&window, 800, 400, OF_WINDOW);

	// and uncomment this line
	// ofSetupOpenGL(300, 300, OF_WINDOW);
	ofRunApp(new ofApp());

}
