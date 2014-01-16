#pragma once

#include "ofxNetwork.h"
#include "ofMain.h"

using std::string;

#define STRIP_COUNT (4)
#define STRIP_LENGTH (54)
#define COLOR_DEPTH (3)
#define PIXEL_COUNT (STRIP_LENGTH * STRIP_COUNT)


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

    ofxUDPManager udpConnection;
    string ip       = "192.168.1.54";  // the remote IP address
    int port        = 8888;    // the destination port
    
    // Strip Config
    //int PIXEL_COUNT = STRIP_LENGTH * STRIP_COUNT;
    char pixels[PIXEL_COUNT * COLOR_DEPTH];
    int pixelsLength = PIXEL_COUNT * COLOR_DEPTH;
    
    ofTrueTypeFont  mono;
    ofTrueTypeFont  monosm;
    vector<ofPoint> stroke;
    
    void initPixelPattern(int locSeed);
    void rotatePixels();
};

