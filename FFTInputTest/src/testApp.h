#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    // Init methods
    void initSoundStream();
    void initFFT();
    
    // Update methods
    void updateFFT();
	
    // Draw methods
    void drawChannels(int x, int y);
    void drawAverageVolume(int x, int y);
    void drawFFT(int x, int y);
    void drawStreamInfo();

    // Util methods
    float calcRootMeanSquared(float * input, int bufferSize, int nChannels);
    
    // SoundStream members
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int bufferCounter;
    int drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    //FFT Members
    float * fftSmoothed;
    int nBandsToGet;
};
