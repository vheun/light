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

//--------------------------------------------------------------

typedef ofKeyEventArgs KeyEvent;
typedef bool KeyEventIndicator;

class KeyEventProvider {
public:
    virtual const KeyEvent& getKeyEvent() = 0;
    virtual const KeyEventIndicator& hasKeyEvent() = 0;
};

class KeyEventListener {
public:    
    virtual void registerKeyEventProvider(KeyEventProvider &provider) {
        keyEventProvider = &provider;
    }
protected:
    KeyEventProvider *keyEventProvider;
};

//--------------------------------------------------------------

class KeyboardInput : public Input, public KeyEventProvider {
public:
    KeyboardInput(string newId);
    
    virtual void initInput();
    virtual void updateInput();
    virtual void clearEventQueue();
    
    // Key event listener methods
    void keyPressed(ofKeyEventArgs &args);
    void keyReleased(ofKeyEventArgs &args);
    
    // KeyEvent Functions
    virtual const KeyEvent &getKeyEvent();
    virtual const KeyEventIndicator &hasKeyEvent();
private:
    ofKeyEventArgs keyEventArgs;
    KeyEventIndicator newKeyEvent;
    
};
#endif /* defined(__SmoothLightVer1__KeyboardInput__) */
