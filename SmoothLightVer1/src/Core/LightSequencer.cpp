//
//  LightSequencer.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "LightSequencer.h"

void LightSequencer::initSequencer() {
     startTime = ofGetElapsedTimef();
    
    // Create one test light pattern
    //lightPatterns.push_back(LightPattern());
}

void LightSequencer::updatePatterns(float time) {
}


void LightSequencer::processState(float time) {
    
}

void LightSequencer::sequenceBehavior(float time) {
    
}

//--------------------------------------------------------------

const vector<LightPattern> & LightSequencer::getLightPatterns() {
    return lightPatterns;
}






//--------------------------------------------------------------
