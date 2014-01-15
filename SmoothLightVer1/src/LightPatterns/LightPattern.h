//
//  LightPattern.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__LightPattern__
#define __SmoothLightVer1__LightPattern__

#include <iostream>

#include "ofMain.h"

class LightPattern {
public:
    LightPattern(float time);
    ~LightPattern();
    
    void step(float time);
    virtual void draw(ofPixels &pixels);
private:
    float startTime;
    
};

#endif /* defined(__SmoothLightVer1__LightPattern__) */
