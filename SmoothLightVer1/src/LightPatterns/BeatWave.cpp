//
//  BeatWave.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#include "BeatWave.h"

void BeatWave::setup(ofVec2f startPosition, ofVec2f direction, float startSpeed, int width, int height, BoundingBox2D bb) {
    pos = startPosition;
    dir = direction.normalize();
    speed = startSpeed;
    barWidth = width;
    barHeight = height;
    bBox = bb;
}

void BeatWave::init(float time) {
    color = ofColor(100,100,255);
}

void BeatWave::step(float time) {
    pos += (dir * speed);
}

void BeatWave::draw(ofFbo &fbo) {
    int width = fbo.getWidth();
    int height = fbo.getHeight();

    ofSetColor(color);
    ofPushMatrix();
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofTranslate(pos.x, pos.y);
    ofRotateZ(dir.angle(ofVec2f(0.0f,1.0f)));
    ofRect(ofPoint(0,0), barWidth, barHeight);
    
    ofPopStyle();
    ofPopMatrix();
}

bool BeatWave::isDead() {
    return !bBox.isPointInside(ofPoint(pos));
    //return false;
}