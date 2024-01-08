/********  Test sample for ofxInteractiveObject                                ********/
/********  Make sure you open your console to see all the events being output  ********/


#pragma once

#include "ofxMSAInteractiveObject.h"

#define        IDLE_COLOR        0xFFFFFF
#define        OVER_COLOR        0x00FF00
#define        DOWN_COLOR        0xFF0000


class MyTestObject : public ofxMSAInteractiveObject {
public:
    bool isDragged;
    glm::vec2 dragPoint;

    void setup() {
        printf("MyTestObject::setup() - hello!\n");
        enableMouseEvents();
        enableKeyEvents();
        isDragged = false;
    }
    
    void exit() {
        printf("MyTestObject::exit() - goodbye!\n");
    }
    
    
    void update() {
        if (isDragged) setPosition(ofGetMouseX() - dragPoint.x, ofGetMouseY() - dragPoint.y);
    }

    void draw() {
        if (isMousePressed() || isDragged) ofSetHexColor(DOWN_COLOR);
        else if (isMouseOver()) ofSetHexColor(OVER_COLOR);
        else ofSetHexColor(IDLE_COLOR);
        
        ofRect(x, y, width, height);
    }

    virtual void onRollOver(int x, int y) {
        printf("MyTestObject::onRollOver(x: %i, y: %i)\n", x, y);
    }
    
    virtual void onRollOut() {
        printf("MyTestObject::onRollOut()\n");
    }
    
    virtual void onMouseMove(int x, int y){
        printf("MyTestObject::onMouseMove(x: %i, y: %i)\n", x, y);
    }
    
    virtual void onDragOver(int x, int y, int button) {
        printf("MyTestObject::onDragOver(x: %i, y: %i, button: %i)\n", x, y, button);
    }
    
    virtual void onDragOutside(int x, int y, int button) {
        printf("MyTestObject::onDragOutside(x: %i, y: %i, button: %i)\n", x, y, button);
    }
    
    virtual void onPress(int x, int y, int button) {
        printf("MyTestObject::onPress(x: %i, y: %i, button: %i)\n", x, y, button);
        dragPoint.x = getRelMouseX();
        dragPoint.y = getRelMouseY();
        isDragged = true;
    }
    
    virtual void onRelease(int x, int y, int button) {
        printf("MyTestObject::onRelease(x: %i, y: %i, button: %i)\n", x, y, button);
        //if (isDragged) setPosition(x-dragPoint.x, y-dragPoint.y);
        isDragged = false;
    }
    
    virtual void onReleaseOutside(int x, int y, int button) {
        printf("MyTestObject::onReleaseOutside(x: %i, y: %i, button: %i)\n", x, y, button);
		//if (isDragged) setPosition(x - dragPoint.x, y - dragPoint.y);
		isDragged = false;
    }

    virtual void keyPressed(int key) {
        printf("MyTestObject::keyPressed(key: %i)\n", key);
    }
    
    virtual void keyReleased(int key) {
        printf("MyTestObject::keyReleased(key: %i)\n", key);
    }
    
};