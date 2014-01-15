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

class KeyboardInput : public Input {
public:
    KeyboardInput(string newId);
    
    virtual void initInput();
    virtual void updateInput();
    
    // Key event listener methods
    void keyPressed(ofKeyEventArgs &args);
    void keyReleased(ofKeyEventArgs &args);
private:
    
};
#endif /* defined(__SmoothLightVer1__KeyboardInput__) */
