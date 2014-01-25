//
//  SinMoveShape.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#include "SinMoveShape.h"

//#define _USE_MATH_DEFINES // For using M_PI

void SinMoveShape::init(float time) {
    color = ofColor(100,100,255);
    speed = 1.0f;
}


void SinMoveShape::step(float time) {
    sinStep = (sin(time * speed) + 1.0f)/2.0f;
}

void SinMoveShape::draw(ofFbo &fbo) {
    int width = fbo.getWidth();
    int height = fbo.getHeight();
    float radius = height/2;
    
    float xPos = (width - radius) * sinStep + radius/2.0f;
    
    ofSetColor(color);
    ofCircle(xPos , radius, radius);
}

bool SinMoveShape::isDead() {
    return false;
}