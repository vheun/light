//
//  ConstantSquare.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#include "ConstantSquare.h"

ConstantSquare::ConstantSquare() {
    
}

ConstantSquare::~ConstantSquare() {
    
}

//--------------------------------------------------------------

void ConstantSquare::init(float time) {
    startTime = time;
}


void ConstantSquare::step(float time) {
    // Randomize color if there is a keyBoardInput event
    if (keyEventProvider->hasKeyEvent()) {
        color = ofColor(ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
    }
    
}

void ConstantSquare::draw(ofFbo &fbo) {
    int width = fbo.getWidth();
    int height = fbo.getHeight();
    
    ofSetColor(color);
    ofRect(pos, size, size);
}

bool ConstantSquare::isDead() {
    return false;
}



