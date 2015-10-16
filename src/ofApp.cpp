#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    bShowTimeline = true;
    
	typeface.loadFont("fonts/UnicaOne-Regular.ttf", 50, true, true);
	typeface.setLineHeight(22.0f);
	typeface.setLetterSpacing(1.037);
    
//    shader.setGeometryInputType(GL_LINES);
//    shader.setGeometryOutputCount(1024);
//    shader.setGeometryOutputType(GL_LINE_STRIP);
    shader.load("shaders/shader");

    center = ofPoint(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    
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
    gui.add(triangleZ.setup("Triangle Z", 0.0, -5000.0, 1000.0));
    gui.add(moireSpacing.setup("Moire Spacing", 1.0, 1.0, 45.0));
    gui.add(moireAmount.setup("Moire Amount", 1.0, 1.0, 100.0));
    
    
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
    ofClear(0);
//    float tScale = timeline.getValue("Triangle Scale");
//    float tRotation = timeline.getValue("Triangle Rotation");
    
//    rotations.push_back(tRotation);
    
//    for(int i = 0; i < rotations.size() ;i++) {

//        ofRotate(rotations[i]);

        float radius = 2*(ofGetHeight()/5);
    

        shader.begin();
    
            ofNoFill();

    
            for(int i = 0; i < abs(moireAmount); i++) {
            
                ofPushMatrix();
                ofSetColor(255, 255, 255, 0.5);

                ofTranslate(center);

                ofPoint p1 = ofPoint(cos(ofDegToRad(0-90))*radius, sin(ofDegToRad(0-90))*radius, triangleZ);
                ofPoint p2 = ofPoint(cos(ofDegToRad(120-90))*radius, sin(ofDegToRad(120-90))*radius, triangleZ);
                ofPoint p3 = ofPoint(cos(ofDegToRad(240-90))*radius, sin(ofDegToRad(240-90))*radius, triangleZ);
            
        
                ofPushMatrix();
                    ofRotate(i*moireAmount*moireSpacing, 0, 0, 1);
                    ofTriangle(p1, p2, p3);
                ofPopMatrix();
                ofPopMatrix();
                
                ofLine(ofPoint(ofGetWidth()/2, 0, 0), p1 + center);
                ofLine(ofPoint(ofGetWidth(), ofGetHeight(), 0), p2 + center);
                ofLine(ofPoint(0, ofGetHeight(), 0), p3 + center);
            }
    
    

        shader.end();

        ofSetColor(255);
        typeface.drawStringCentered("LEVEL 1", center.x, center.y);
    
    if(bShowTimeline) {
//        timeline.draw();
    }
    
    
    gui.draw();
}


//void ofApp::drawEquilateralTriangle(ofPoint center, float radius) {
//    
//    // NOT EQUILATERAL YET
//    // sin(angle) = y/r
//    // y = sin(angle)/r
//    ofPoint p1 = ofPoint(cos(ofDegToRad(0))*radius, sin(ofDegToRad(0))*radius);
//    ofPoint p2 = ofPoint(cos(ofDegToRad(120))*radius, sin(ofDegToRad(120))*radius);
//    ofPoint p3 = ofPoint(cos(ofDegToRad(240))*radius, sin(ofDegToRad(240))*radius);
//    
//    
//    printf("%f %f %f %f %f %f", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
//    
//    ofTriangle(p1, p2, p3);
//}

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
    center = ofPoint(x, y, 0);
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
