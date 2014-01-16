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
    // Create the pixel strip strings and pixel strips
    //TODO(KoolJBlack): Place this functionality elsewhere.
    pixel_strip_list pixelStrips;
    pixelStrips.push_back(PixelStrip2D(ofPoint(53,0), ofPoint(0,0), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(0,1), ofPoint(53,1), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(53,2), ofPoint(0,2), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(0,3), ofPoint(53,3), 54));
    PixelStripString2D pixelStripString;
    pixelStripString.initStripString(pixelStrips, "192.168.1.54", 8888);
    pixelStripStrings.push_back(pixelStripString);
 
    // Bounding box for all pixel strips
    BoundingBox2D bBox;
    bBox.coverPixelStrips(pixelStrips);
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
    //pixels.setColor(ofColor(0,0,0));
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

