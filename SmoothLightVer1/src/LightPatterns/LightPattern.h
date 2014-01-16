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
    /**
     Initializes light pattern state.
     */
    virtual void init(float time) = 0;
    /**
     Advances the light pattern by a time step. Light pattern internal state
     is updated here.
     */
    virtual void step(float time) = 0;
    /**
     Draws this light pattern to a 2D screen's pixels
     */
    virtual void draw(ofPixels &pixels) = 0;
    /**
     Indicates if this pattern is finished. This method is called regularly on
     every pattern update cycle to determine which patterns are to be
     removed form the cycle.
     */
    virtual bool isDead() = 0;
protected:
    float startTime;
    
};

#endif /* defined(__SmoothLightVer1__LightPattern__) */
