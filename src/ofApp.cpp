#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    bShowTimeline = true;
    
	timeline.setup();
	timeline.setFrameRate(30);
	timeline.setDurationInFrames(570);
	timeline.setLoopType(OF_LOOP_NORMAL);

    timeline.addCurves("Triangle Scale", ofRange(0, 100));
    timeline.addCurves("Triangle Rotation", ofRange(0, 720));
    
    timeline.play();
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float tScale = timeline.getValue("Triangle Scale");
    float tRotation = timeline.getValue("Triangle Rotation");
    
    ofPushMatrix();
        ofNoFill();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotate(tRotation);
        drawEquilateralTriangle(ofPoint(0, 0), ofGetWidth()/4);
    ofPopMatrix();
    
    if(bShowTimeline) {
        timeline.draw();
    }
}


void ofApp::drawEquilateralTriangle(ofPoint center, float radius) {
    
    // NOT EQUILATERAL YET
    ofPoint p1 = ofPoint(center.x, center.y-radius);
    ofPoint p2 = ofPoint(radius, center.y+radius);
    ofPoint p3 = ofPoint(-radius, center.y+radius);
    
    ofTriangle(p1, p2, p3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 't') {
        bShowTimeline = !bShowTimeline;
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
