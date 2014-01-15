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

class ConstantSquare : public LightPattern {
public:
    virtual void init(float time);
    virtual void step(float time);
    virtual void draw(ofPixels &pixels);
    virtual bool isDead();
protected:
    
};

#endif /* defined(__SmoothLightVer1__ConstantSquare__) */
