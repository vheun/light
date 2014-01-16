//
//  SmoothCore.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#include "SmoothCore.h"

#define LIGHT_SCREEN_WIDTH (54)
#define LIGHT_SCREEN_HEIGHT (4)


//SmoothCore::SmoothCore(): screen(ofGetWindowWidth(), ofGetWindowHeight()) {
SmoothCore::SmoothCore() {
    //cout << "is this run" << endl;
    screenRenderer = new Screen2DRenderer(ofGetWindowWidth(), ofGetWindowHeight());
    udpRenderer = new UDPRenderer();
}

SmoothCore::~SmoothCore() {
    
}

//--------------------------------------------------------------

void SmoothCore::initCore() {
    // Set member variables
    
    // Init all inputs
    initInputs();
    
    // Init light sequencer
    initLightSequencer();
    
    // Init the screen
    initScreen();
    
    // Init the renderer
    initRenderer();
}

void SmoothCore::updateCore() {
    // Update all inputs
    for (input_it it = inputs.begin() ; it != inputs.end(); ++it) {
        Input* inp = it->second;
        inp->updateInput();
    }
    
    // Advance LightSequencer
    float time = ofGetElapsedTimef();
    lightSequencer.updatePatterns(time);
    lightSequencer.processState(time);
    lightSequencer.sequenceBehavior(time);
    
    // Clear all input events
    inputEventsClear();
}

void SmoothCore::drawCore() {
    ofBackground(100, 100, 130);
    
    // Draw LightPatterns on screen
    screen.drawLights(lightSequencer.getLightPatterns());
    
    // Render the screen
    screenRenderer->renderScreen(screen);
    udpRenderer->renderScreen(screen);
}

//--------------------------------------------------------------

void SmoothCore::initInputs() {
    // Add one input for now...
    Input* input = new KeyboardInput("KeyboardInput");
    input->initInput();
    //inputs.push_back(input);
    inputs[input->getId()] = input;
}

void SmoothCore::initLightSequencer() {
    float time = ofGetElapsedTimef();
    lightSequencer.initSequencer(time, inputs);
}

void SmoothCore::initScreen() {
    screen.initScreen();
}

void SmoothCore::initRenderer() {
    screenRenderer->initRenderer();
    udpRenderer->initRenderer();
}

//--------------------------------------------------------------
void SmoothCore::inputEventsClear() {
    // Update all inputs
    for (input_it it = inputs.begin() ; it != inputs.end(); ++it) {
        Input* inp = it->second;
        inp->clearEventQueue();
    }
}




