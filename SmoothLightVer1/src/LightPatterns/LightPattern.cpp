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

void LightPattern::draw(ofPixels &pixels) {
    int width = pixels.getWidth();
    int height = pixels.getHeight();
}

bool LightPattern::isDead() {
    return false;
}