#include "ofApp.h"

void testApp::setup() {
    ofSetFrameRate(30);
    obj.set(300, 50, 100, 200);
}

void testApp::draw() {
    stringstream s;
    s << "oF version: " << ofGetVersionInfo() << endl;
    s << "isMouseOver: " << obj.isMouseOver() << endl;
    s << "isMousePressed(0): " << obj.isMousePressed(0) << endl;
    s << "isMousePressed(1): " << obj.isMousePressed(1) << endl;
    s << "isMousePressed(2): " << obj.isMousePressed(2) << endl;
    s << "getStateChangeMillis(): " << obj.getStateChangeMillis() << endl;
    s << "FPS: " << ofGetFrameRate() << endl;
    
    ofSetColor(0);
    ofDrawBitmapString(s.str(), 10, 30);
}
