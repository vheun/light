//
//  SmoothCore.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__SmoothCore__
#define __SmoothLightVer1__SmoothCore__

#include <iostream>



#include "ofMain.h"
// Core Imports
#include "Input.h"
#include "LightSequencer.h"
#include "Screen.h"
#include "Renderer.h"
// Inputs
#include "KeyboardInput.h"
// Renderers
#include "Screen2DRenderer.h"


class SmoothCore {
public:
    SmoothCore();
    ~SmoothCore();
    
    void initCore();
    void updateCore();
    void drawCore();
    
private:
    // Init functions
    void initInputs();
    void initLightSequencer();
    void initScreen();
    void initRenderer();
    
    // Core Members
    //vector<Input*> inputs;
    input_map inputs;
    LightSequencer lightSequencer;
    Screen screen;
    Renderer* renderer;
};

#endif /* defined(__SmoothLightVer1__SmoothCore__) */
