//
//  BeatWave.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#ifndef __SmoothLightVer1__BeatWave__
#define __SmoothLightVer1__BeatWave__

#include <iostream>
#include "math.h"

#include "ofMain.h"
#include "BoundingBox2D.h"
#include "LightPattern.h"

class BeatWave : public LightPattern {
public:
    void setup(ofVec2f startPosition, ofVec2f direction, float speed, int width, int height, BoundingBox2D bb);
    
    virtual void init(float time);
    virtual void step(float time);
    virtual void draw(ofFbo &fbo);
    virtual bool isDead();

    // BeatWave config params
    ofColor color;
    float speed;
    int barWidth, barHeight;
    BoundingBox2D bBox;
    ofVec2f pos, dir;
};

#endif /* defined(__SmoothLightVer1__BeatWave__) */
