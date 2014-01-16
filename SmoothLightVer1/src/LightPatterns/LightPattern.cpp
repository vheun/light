//
//  LightPattern.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "LightPattern.h"


//--------------------------------------------------------------

void LightPattern::init(float time) {
    startTime = time;
}


void LightPattern::step(float time) {
    
}

void LightPattern::draw(ofFbo &fbo) {
    int width = fbo.getWidth();
    int height = fbo.getHeight();
}

bool LightPattern::isDead() {
    return false;
}