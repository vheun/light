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
SmoothCore::SmoothCore(): screen(LIGHT_SCREEN_WIDTH, LIGHT_SCREEN_HEIGHT) {
    cout << "is this run" << endl;
    renderer = new TwoDimensionalScreenRenderer(ofGetWindowWidth(), ofGetWindowHeight());
}

SmoothCore::~SmoothCore() {
    
}

//--------------------------------------------------------------

void SmoothCore::initCore() {
    // Set member variables
    
    // Init all inputs
    initInputs();
    
    // Init the light sequencer
    initLightSequencer();
    
    // Init the screen
    initScreen();
    
    // Init the renderer
    initRenderer();
}

void SmoothCore::updateCore() {
    // Update all inputs
    for (vector<Input*>::iterator it = inputs.begin() ; it != inputs.end(); ++it) {
        Input* inp = *it;
        inp->updateInput();
    }
    
    // Advance LightSequencer
    lightSequencer.updatePatterns();
    lightSequencer.processState();
    lightSequencer.sequenceBehavior();
}

void SmoothCore::drawCore() {
    ofBackground(100, 100, 130);
    
    // Draw LightPatterns on screen
    screen.drawLights(lightSequencer.lightPatterns);
    
    // Render the screen
    renderer->renderScreen(screen);
}

//--------------------------------------------------------------

void SmoothCore::initInputs() {
    // Add one input for now...
    Input* input = new Input();
    input->initInput();
    inputs.push_back(input);
}

void SmoothCore::initLightSequencer() {
    lightSequencer.initSequencer();
}

void SmoothCore::initScreen() {
    screen.initScreen();
}

void SmoothCore::initRenderer() {
    renderer->initRenderer();
}

