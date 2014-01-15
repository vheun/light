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

