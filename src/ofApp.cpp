#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    bShowTimeline = true;
    
	highwayGothic.loadFont("fonts/HWYGOTH.TTF", 20, true, true);
	highwayGothic.setLineHeight(22.0f);
	highwayGothic.setLetterSpacing(1.037);
    
    shader.setGeometryInputType(GL_LINES);
    shader.setGeometryOutputCount(1024);
    shader.setGeometryOutputType(GL_LINE_STRIP);
    shader.load("shaders/shader");


    printf("Max number verices: %i", shader.getGeometryMaxOutputCount());
    
    
//	timeline.setup();
//	timeline.setFrameRate(30);
//	timeline.setDurationInFrames(570);
//	timeline.setLoopType(OF_LOOP_NONE);
//
//    timeline.addCurves("Triangle Scale", ofRange(1, ofGetWidth()));
//    timeline.addCurves("Triangle Rotation", ofRange(0, 720));
//    
//    timeline.play();
    
    
//    if(timeline.isDone()) {
        // delete rotations array?
//    }
    
    gui.setup();
    gui.add(triangleRadius.setup("Triangle Radius", ofGetHeight()/3, 0.0, ofGetWidth()));
    gui.add(moireSpacing.setup("Moire Spacing", 1, 0, 360));
    gui.add(moireAmount.setup("Moire Amount", 10, 0, 1024));

    ofBackground(0);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

   shader.begin();
        shader.setUniform4f(
            "iMouse"
            , mouseX
            , mouseY
            , 0.0
            , 0.0
        );
        shader.setUniform3f(
            "iResolution"
            , ofGetWidth()
            , ofGetHeight()
            , 0.0
        );
        shader.setUniform1f(
            "iGlobalTime"
            , ofGetElapsedTimef()
        );// elapsed time
        shader.setUniform1i(
            "moireSpacing"
            , moireSpacing
        );
        shader.setUniform1i(
            "moireAmount"
            , moireAmount
        );
    shader.end();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    float tScale = timeline.getValue("Triangle Scale");
//    float tRotation = timeline.getValue("Triangle Rotation");
    
//    rotations.push_back(tRotation);
    
//    for(int i = 0; i < rotations.size() ;i++) {

    ofPushMatrix();
        ofSetColor(255);
        ofNoFill();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//        ofRotate(rotations[i]);

        float radius = triangleRadius;
        
        ofPoint p1 = ofPoint(cos(ofDegToRad(0-90))*radius, sin(ofDegToRad(0-90))*radius);
        ofPoint p2 = ofPoint(cos(ofDegToRad(120-90))*radius, sin(ofDegToRad(120-90))*radius);
        ofPoint p3 = ofPoint(cos(ofDegToRad(240-90))*radius, sin(ofDegToRad(240-90))*radius);
    
        ofLine(ofPoint(0, -ofGetHeight()/2), p1);
        ofLine(ofPoint(ofGetWidth()/2, ofGetHeight()/2), p2);
        ofLine(ofPoint(-ofGetWidth()/2, ofGetHeight()/2), p3);
    
        shader.begin();
            ofTriangle(p1, p2, p3);
        shader.end();

//        drawEquilateralTriangle(ofPoint(0, 0), tScale);
    ofPopMatrix();
//    }
    
//    ofPushMatrix();
//        ofSetColor(255);
//        string title = "vespers";
//        ofRectangle bounds = highwayGothic.getStringBoundingBox(title, 0, 0);
//        highwayGothic.drawString("vespers", ofGetWidth()/2 - bounds.x/2, ofGetHeight()/2-bounds.y/2);
//    ofPopMatrix();

    if(bShowTimeline) {
//        timeline.draw();
    }
    
    
    gui.draw();
}


void ofApp::drawEquilateralTriangle(ofPoint center, float radius) {
    
    // NOT EQUILATERAL YET
    // sin(angle) = y/r
    // y = sin(angle)/r
    ofPoint p1 = ofPoint(cos(ofDegToRad(0))*radius, sin(ofDegToRad(0))*radius);
    ofPoint p2 = ofPoint(cos(ofDegToRad(120))*radius, sin(ofDegToRad(120))*radius);
    ofPoint p3 = ofPoint(cos(ofDegToRad(240))*radius, sin(ofDegToRad(240))*radius);
    
    
    printf("%f %f %f %f %f %f", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
    
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
