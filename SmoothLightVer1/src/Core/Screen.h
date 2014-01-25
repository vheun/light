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
#include "PixelStripString2D.h"
#include "BoundingBox2D.h"

// Laytout Includes
#include "OneStringTestLayout.h"

class Screen {
public:
    Screen();
    ~Screen();
    /**
     Initialize light strips and pixels. 
     */
    void initScreen();
    /**
     Set the size and width of the light pixels to draw to
     */
    void setSize(int w, int h);
    /**
     Render given light patterns to screen with light strips
     */
    void drawLights(const vector<LightPattern*> &lightPatterns);
    /**
     Clears all of the pixels in this screen to a default color;
     */
    void clear();
    
    // Member accessors
    int getWidth();
    int getHeight();
    const ofPixels& getPixels();
    void setClearScreen(bool c);
    
    const pixel_strip_strings_list& getPixelStripStrings();
    
private:
    // Screen representation members
    int width, height;
    pixel_strip_strings_list pixelStripStrings;
    ofFbo fbo;
    ofPixels pixels;
    
    bool isClear;
    
};

#endif /* defined(__SmoothLightVer1__Screen__) */
