//
//  LightPattern.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "LightPattern.h"

LightPattern::LightPattern(float time) {
    startTime = time;
}

LightPattern::~LightPattern() {
    
}

//--------------------------------------------------------------

void LightPattern::step(float time) {
    
}

void LightPattern::draw(ofPixels &pixels) {
    int width = pixels.getWidth();
    int height = pixels.getHeight();
    //TODO(KoolJBlack): implement this.
}