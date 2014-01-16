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
    newKeyEvent = false;
    
    // Register for keyboard events
    ofRegisterKeyEvents(this);
}

void KeyboardInput::updateInput() {
    
}

void KeyboardInput::clearEventQueue() {
    newKeyEvent = false;
}

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &args){
    int key = args.key;
    keyEventArgs = args;
    newKeyEvent = true;
}

void KeyboardInput::keyReleased(ofKeyEventArgs &args){
    int key = args.key;

}

//--------------------------------------------------------------

const KeyEvent& KeyboardInput::getKeyEvent() {
    return keyEventArgs;
}

const KeyEventIndicator& KeyboardInput::hasKeyEvent() {
    return newKeyEvent;
}
