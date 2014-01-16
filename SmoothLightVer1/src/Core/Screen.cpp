//
//  Screen.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//
#include "Screen.h"


Screen::Screen(int windowWidth, int windowHeight): width(windowWidth), height(windowHeight)  {
    pixels.allocate(width, height, 3);
}

Screen::~Screen() {
    
}

//--------------------------------------------------------------

void Screen::initScreen() {
    // Clear all pixels at start
    clear();
    // Clear the screen on every draw loop
    isClear = true;
    
    // Create the pixel strip strings and pixel strips
    //TODO(KoolJBlack): Place this functionality elsewhere.
    pixel_strip_list pixelStrips;
    pixelStrips.push_back(PixelStrip2D(ofPoint(54,0), ofPoint(0,0), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(0,1), ofPoint(54,1), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(54,2), ofPoint(0,2), 54));
    pixelStrips.push_back(PixelStrip2D(ofPoint(0,3), ofPoint(54,3), 54));
    PixelStripString2D pixelStripString;
    pixelStripString.initStripString(pixelStrips, "192.168.1.54", 8888);
    pixelStripStrings.push_back(pixelStripString);
    
}

void Screen::drawLights(const vector<LightPattern*> &lightPatterns){
    // Clear the screen if set
    if (isClear) {
        clear();
    }
    
    for (vector<LightPattern*>::const_iterator it = lightPatterns.begin(); it != lightPatterns.end(); ++it) {
        LightPattern* pattern = *it;
        // Draw lightPattern to pixels
        pattern->draw(pixels);
    }
}

void Screen::clear() {
    pixels.setColor(ofColor(0,0,0));
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

