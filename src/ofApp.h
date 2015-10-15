#pragma once

#include "ofMain.h"
#include "ofxTimeline.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
    
        bool bShowTimeline;
    
//        ofxTimeline timeline;
    
        vector<float> rotations;
    
		ofTrueTypeFont  highwayGothic;
    
        ofxPanel gui;
        ofxFloatSlider triangleRadius;
        ofxFloatSlider moireSpacing;
        ofxFloatSlider moireAmount;
    
    
		void setup();
		void update();
		void draw();
    
        void drawEquilateralTriangle(ofPoint center, float radius);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
