//
//  KeyboardInput.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef __SmoothLightVer1__KeyboardInput__
#define __SmoothLightVer1__KeyboardInput__

#include <iostream>

#include "ofMain.h"
#include "Input.h"

typedef bool KeyboardInputKeyEvent;

class KeyboardInput : public Input {
public:
    KeyboardInput(string newId);
    
    virtual void initInput();
    virtual void updateInput();
    virtual void clearEventQueue();
    
    // Key event listener methods
    void keyPressed(ofKeyEventArgs &args);
    void keyReleased(ofKeyEventArgs &args);
    
    // Input data providers
    KeyboardInputKeyEvent getKeyEvent();
private:
    bool isKeyEvent;
    
};
#endif /* defined(__SmoothLightVer1__KeyboardInput__) */
