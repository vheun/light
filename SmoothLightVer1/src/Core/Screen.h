//
//  Screen.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__Screen__
#define __SmoothLightVer1__Screen__

#include <iostream>
#include <vector.h>

#include "ofMain.h"
#include "LightPattern.h"
#include "LightStrip.h"

class Screen {
public:
    Screen(int windowWidth, int windowHeight);
    ~Screen();
    /**
     Initialize light strips and pixels. 
     */
    void initScreen();
    /**
     Render given light patterns to screen with light strips
     */
    void drawLights(const vector<LightPattern*> &lightPatterns);
    
    void clear();
    
    int getWidth();
    int getHeight();
    const ofPixels& getPixels();
    
    void setClearScreen(bool c);
    
private:
    // Screen representation members
    int width, height;
    vector<LightStrip> lightStrips;
    ofPixels pixels;
    
    bool isClear;
    
};

#endif /* defined(__SmoothLightVer1__Screen__) */
