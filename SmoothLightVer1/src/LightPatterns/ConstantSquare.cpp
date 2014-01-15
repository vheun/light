//
//  ConstantSquare.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#include "ConstantSquare.h"

void ConstantSquare::init(float time) {
    startTime = time;
}


void ConstantSquare::step(float time) {
    
}

void ConstantSquare::draw(ofPixels &pixels) {
    int width = pixels.getWidth();
    int height = pixels.getHeight();
}

bool ConstantSquare::isDead() {
    return false;
}