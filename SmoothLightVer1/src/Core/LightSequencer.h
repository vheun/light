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
#include "LightPattern.h"

class LightSequencer {
public:
    void initSequencer();
    
    void updatePatterns();
    /**
     Processes all inputs and updates the sequence state.
     */
    void processState();
    void sequenceBehavior();
    
    vector<LightPattern> lightPatterns;
private:
    
    

    
};

#endif /* defined(__SmoothLightVer1__LightSequencer__) */
