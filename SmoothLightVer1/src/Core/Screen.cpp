//
//  Screen.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//
#include "Screen.h"

#define COLOR_DEPTH (3)

Screen::Screen() {
}

Screen::~Screen() {
    
}

//--------------------------------------------------------------

void Screen::initScreen() {
    // Layout bulider sets pixel and screen dimensions
    OneStringTestLayout layoutBuilder;
    layoutBuilder.buildLayout();
    pixelStripStrings = layoutBuilder.getLayoutStripStrings();
    BoundingBox2D bBox = layoutBuilder.getLayoutBoundingBox();
    setSize((bBox.getWidth()), bBox.getHeight());

    // Clear the screen on every draw loop
    isClear = true;
}

void Screen::setSize(int w, int h) {
    width = w;
    height = h;
    
    // Allocate the frame buffer object and clear pixels
    fbo.allocate(w, h, GL_RGBA);
    clear();
    
    // Allocate space for internal pixel buffer
    pixels.allocate(w, h, OF_PIXELS_RGB);
}

void Screen::drawLights(const vector<LightPattern*> &lightPatterns){
    // Clear the screen if set
    if (isClear) {
        clear();
    }
    
    // Start the fbo. All draw calls will be drawn to this
    fbo.begin();
    
    for (vector<LightPattern*>::const_iterator it = lightPatterns.begin(); it != lightPatterns.end(); ++it) {
        LightPattern* pattern = *it;
        // Draw lightPattern to pixels
        pattern->draw(fbo);
    }
    
    // End the fbo
    fbo.end();
    
    // Copy to pixels
    fbo.readToPixels(pixels);
}

void Screen::clear() {
    fbo.begin();
    ofClear(0,0,0, 255);
    fbo.end();
}

//--------------------------------------------------------------

int Screen::getWidth() {
    return width;
}

int Screen::getHeight() {
    return height;
}

const ofPixels & Screen::getPixels() {
    return pixels;
}

void Screen::setClearScreen(bool c) {
    isClear = c;
}

//--------------------------------------------------------------
const pixel_strip_strings_list& Screen::getPixelStripStrings() {
    return pixelStripStrings;
}

