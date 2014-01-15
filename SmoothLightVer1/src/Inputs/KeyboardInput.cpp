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
    // Register for keyboard events
    ofRegisterKeyEvents(this);
}

void KeyboardInput::updateInput() {
    
}

//--------------------------------------------------------------
void KeyboardInput::keyPressed(ofKeyEventArgs &args){
    int key = args.key;
    
}

//--------------------------------------------------------------
void KeyboardInput::keyReleased(ofKeyEventArgs &args){
    int key = args.key;

}

