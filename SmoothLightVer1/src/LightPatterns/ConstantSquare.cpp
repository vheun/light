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

void ConstantSquare::draw(ofPixels &pixels) {
    int width = pixels.getWidth();
    int height = pixels.getHeight();
    
    // Use a samller square set of colored pixels to render the square.
    // TODO (KoolJBlack): make this more efficient
    ofPixels square;
    square.allocate(size, size, 3);
    square.setColor(color);
    square.pasteInto(pixels, pos.x, pos.y);
}

bool ConstantSquare::isDead() {
    return false;
}

//--------------------------------------------------------------
void ConstantSquare::RegisterKeyEventProvider(KeyEventProvider &provider) {
    keyEventProvider = &provider;
}

