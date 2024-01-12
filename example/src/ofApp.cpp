#include "ofApp.h"

void testApp::setup() {
    //ofSetFrameRate(30);
    obj1.set(200, 150, 50, 50);
    obj2.set(300, 150, 50, 50);
}

void testApp::draw() {
    stringstream s;
    s << "obj1 isMouseOver: " << obj1.isMouseOver() << endl;
    s << "obj1 isMousePressed(0): " << obj1.isMousePressed(0) << endl;
    s << "obj1 isMousePressed(1): " << obj1.isMousePressed(1) << endl;
    s << "obj1 isMousePressed(2): " << obj1.isMousePressed(2) << endl;
    s << "obj1 getStateChangeMillis(): " << obj1.getStateChangeMillis() << endl;
    s << "-------------------------------------------------" << endl;
    s << "obj2 isMouseOver: " << obj2.isMouseOver() << endl;
    s << "obj2 isMousePressed(0): " << obj2.isMousePressed(0) << endl;
    s << "obj2 isMousePressed(1): " << obj2.isMousePressed(1) << endl;
    s << "obj2 isMousePressed(2): " << obj2.isMousePressed(2) << endl;
    s << "obj2 getStateChangeMillis(): " << obj2.getStateChangeMillis() << endl;
    s << "-------------------------------------------------" << endl;
    s << "V: " << ofGetVersionInfo() << " FPS: " << (int)ofGetFrameRate() << endl;
    
    ofSetColor(0);
    ofDrawBitmapString(s.str(), 10, 30);
}
