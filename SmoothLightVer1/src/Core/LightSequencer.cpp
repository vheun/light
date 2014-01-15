//
//  LightSequencer.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "LightSequencer.h"

void LightSequencer::initSequencer(float time, input_map inps) {
    startTime = time;
    inputs = inps;
    
    // Create one test light pattern
    ConstantSquare * square = new ConstantSquare();
    square->pos = ofPoint(0,0);
    square->size = 4;
    square->color = ofColor(255,0,0);
    lightPatterns.push_back(square);
}

void LightSequencer::updatePatterns(float time) {
    for (vector<LightPattern*>::iterator it = lightPatterns.begin(); it != lightPatterns.end(); ++it) {
        LightPattern* pattern = *it;
        if (pattern->isDead()) {
            it = lightPatterns.erase(it);
        } else {
            pattern->step(time);
        }
    }
}


void LightSequencer::processState(float time) {
    // No state to process
}

void LightSequencer::sequenceBehavior(float time) {
    // No new behavior to sequence
}

//--------------------------------------------------------------

const vector<LightPattern*> & LightSequencer::getLightPatterns() {
    return lightPatterns;
}






//--------------------------------------------------------------
