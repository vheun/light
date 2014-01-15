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
    virtual void init(float time);
    virtual void step(float time);
    virtual void draw(ofPixels &pixels);
    /**
     Indicates if this pattern is finished. This method is called regularly on
     every pattern update cycle to determine which patterns are to be
     removed form the cycle.
     */
    virtual bool isDead();
protected:
    float startTime;
    
};

#endif /* defined(__SmoothLightVer1__LightPattern__) */
