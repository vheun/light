//
//  SinMoveShape.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#ifndef __SmoothLightVer1__SinMoveShape__
#define __SmoothLightVer1__SinMoveShape__

#include <iostream>
#include "math.h"

#include "LightPattern.h"

class SinMoveShape : public LightPattern {
public:
    virtual void init(float time);
    virtual void step(float time);
    virtual void draw(ofFbo &fbo);
    virtual bool isDead();

    float sinStep;
    ofColor color;
    float speed;
};


#endif /* defined(__SmoothLightVer1__SinMoveShape__) */
