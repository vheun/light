//
//  Screen2DRenderer.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef __SmoothLightVer1__Screen2DRenderer__
#define __SmoothLightVer1__Screen2DRenderer__

#include <iostream>

#include "ofMain.h"
#include "Renderer.h"

class Screen2DRenderer: public Renderer {
public:
    Screen2DRenderer(int width, int height);
    ~Screen2DRenderer();
    
    virtual void initRenderer();
    virtual void renderScreen(Screen &screen);
private:
    int screenWidth, screenHeight;
    
    const int CIRCLE_RADIUS = 20.0f;
    const ofColor BACKGROUND_COLOR = ofColor(100, 100, 150);
};

#endif /* defined(__SmoothLightVer1__Screen2DRenderer__) */
