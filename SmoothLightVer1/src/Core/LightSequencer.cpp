//
//  LightSequencer.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "LightSequencer.h"

LightSequencer::LightSequencer() {
    
}

LightSequencer::~LightSequencer() {
    // Free all light patterns
    for (vector<LightPattern*>::iterator it = lightPatterns.begin(); it != lightPatterns.end(); ++it) {
        delete *it;
    }
    lightPatterns.clear();
}


//--------------------------------------------------------------

void LightSequencer::initSequencer(float time, input_map &inps, int width, int height) {
    startTime = time;
    inputs = inps;
    
    screenWidth = width;
    screenHeight = height;
    
    // Create one test light pattern
    ConstantSquare * square = new ConstantSquare();
    square->pos = ofPoint(0,0);
    square->size = 4;
    square->color = ofColor(255,0,0);
    KeyboardInput *keyboardInput = (KeyboardInput*) inputs["KeyboardInput"];
    square->registerKeyEventProvider(*keyboardInput);
    lightPatterns.push_back(square);
    
    // Create circle test pattern
    SinMoveShape * moveShape = new SinMoveShape();
    moveShape->init(time);
    moveShape->speed = 5.0f;
    lightPatterns.push_back(moveShape);
    
    // Register sequencer to listen to keyboard input
    registerKeyEventProvider(*keyboardInput);
}

void LightSequencer::updatePatterns(float time) {
    for (vector<LightPattern*>::iterator it = lightPatterns.begin(); it < lightPatterns.end(); ++it) {
        LightPattern* pattern = *it;
        if (pattern->isDead()) {
            delete pattern;
            it = lightPatterns.erase(it);
        } else {
            pattern->step(time);
        }
    }
}

void LightSequencer::processState(float time) {
    // On every new key input, create a new wave
    if (keyEventProvider->hasKeyEvent()) {
        BeatWave* wave = new BeatWave();
        ofVec2f startPos(0, screenHeight/2);
        ofVec2f direction(1.0f, 0);
        float speed = 3.0f;
        int width = 10;
        int height = 2;
        BoundingBox2D bBox;
        bBox.setWidthFromOrigin(screenWidth);
        bBox.setHeightFromOrigin(screenHeight);
        wave->setup(startPos, direction, speed, width, height, bBox);
        lightPatterns.push_back(wave);
    }
}

void LightSequencer::sequenceBehavior(float time) {
    // No new behavior to sequence
}

//--------------------------------------------------------------

const vector<LightPattern*> & LightSequencer::getLightPatterns() {
    return lightPatterns;
}

//--------------------------------------------------------------
void LightSequencer::registerKeyEventProvider(KeyEventProvider &provider) {
    keyEventProvider = &provider;
}