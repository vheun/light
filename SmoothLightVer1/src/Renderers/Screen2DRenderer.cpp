//
//  Screen2DRenderer.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#include "Screen2DRenderer.h"

Screen2DRenderer::Screen2DRenderer(int width, int height) : screenWidth(width), screenHeight(height) {
    
}

Screen2DRenderer::~Screen2DRenderer() {
    
}

//--------------------------------------------------------------

void Screen2DRenderer::initRenderer() {
    
}

void Screen2DRenderer::renderScreen(Screen &screen) {
    // Get screen info
    int width = screen.getWidth();
    int height = screen.getHeight();
    float xStep = float(screenWidth)/width;
    float yStep = float(screenHeight)/height;
    ofPixels pixels = screen.getPixels();
    
    // Set drawing params
    ofBackground(BACKGROUND_COLOR);
    ofFill();
    
    // Render pixels to screen
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            ofSetColor(pixels.getColor(x,y));
            ofCircle(x * xStep + xStep/2, y * yStep + yStep/2, CIRCLE_RADIUS);
        }
    }
}