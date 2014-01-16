//
//  KeyboardInput.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#include "KeyboardInput.h"

KeyboardInput::KeyboardInput(string newId) {
    id = newId;
}


void KeyboardInput::initInput() {
    // Clear events
    isKeyEvent = false;
    
    // Register for keyboard events
    ofRegisterKeyEvents(this);
}

void KeyboardInput::updateInput() {
    
}

void KeyboardInput::clearEventQueue() {
    isKeyEvent = false;
}

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &args){
    int key = args.key;
    isKeyEvent = true;
}

void KeyboardInput::keyReleased(ofKeyEventArgs &args){
    int key = args.key;

}

//--------------------------------------------------------------

bool KeyboardInput::getKeyEvent() {
    return isKeyEvent;
}
