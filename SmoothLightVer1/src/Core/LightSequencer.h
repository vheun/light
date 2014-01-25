//
//  LightSequencer.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__LightSequencer__
#define __SmoothLightVer1__LightSequencer__

#include <iostream>
#include <vector.h>

#include "ofMain.h"
#include "Input.h"

// LightPattern Includes
#include "LightPattern.h"
#include "ConstantSquare.h"
#include "SinMoveShape.h"
#include "BeatWave.h"

class LightSequencer : private KeyEventListener {
public:
    LightSequencer();
    ~LightSequencer();
    
    virtual void initSequencer(float time, input_map &inps, int width, int height);
    /**
     Updates each pattern controlled by this sequence. Removes patterns that
     are finished from the update cycle
     */
    virtual void updatePatterns(float time);
    /**
     Processes all inputs and updates the sequence state.
     */
    virtual void processState(float time);
    /**
     Sequences the next step in lighting behavior based on updated state and
     elapsed time
     */
    virtual void sequenceBehavior(float time);
    
    const vector<LightPattern*> &getLightPatterns();
    
protected:
    int screenWidth, screenHeight;
    input_map inputs;
    float startTime;
    vector<LightPattern*> lightPatterns;
};

#endif /* defined(__SmoothLightVer1__LightSequencer__) */
