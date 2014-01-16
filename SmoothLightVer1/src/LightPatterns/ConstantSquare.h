//
//  ConstantSquare.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef __SmoothLightVer1__ConstantSquare__
#define __SmoothLightVer1__ConstantSquare__

#include <iostream>

#include "LightPattern.h"
#include "KeyboardInput.h"

class ConstantSquare : public LightPattern, public KeyEventListener {
public:
    ConstantSquare();
    ~ConstantSquare();
    
    virtual void init(float time);
    virtual void step(float time);
    virtual void draw(ofPixels &pixels);
    virtual bool isDead();
    
    // KeyEvent listener methods
    virtual void RegisterKeyEventProvider(KeyEventProvider &provider);
    
    // Square config params
    ofPoint pos;
    int size;
    ofColor color;
private:
    KeyEventProvider *keyEventProvider;
};

#endif /* defined(__SmoothLightVer1__ConstantSquare__) */
