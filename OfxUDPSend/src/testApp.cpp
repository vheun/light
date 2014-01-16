#include "testApp.h"

#define RECONNECT_TIME 400

//--------------------------------------------------------------
void testApp::setup(){
	// we don't want to be running to fast
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    //create the socket and set to send to 127.0.0.1:11999
	udpConnection.Create();
	//udpConnection.Connect("127.0.0.1",6000);
	udpConnection.Connect(ip.c_str(),port);
	udpConnection.SetNonBlocking(true);

    for (int i = 0; i < STRIP_COUNT; ++i) {
        int loc0 = (i * STRIP_LENGTH);
        int loc1 = (i * STRIP_LENGTH) + 26;
        initPixelPattern(loc0);
        initPixelPattern(loc1);
    }

}

void testApp::initPixelPattern(int locSeed) {
    int loc;
    loc = (locSeed + 0) * COLOR_DEPTH;
    pixels[loc + 0] = 255; // red
    pixels[loc + 1] = 0; // green
    pixels[loc + 2] = 0; // blue
    
    loc = (locSeed + 1) * COLOR_DEPTH;
    pixels[loc + 0] = 255; // red
    pixels[loc + 1] = 255; // green
    pixels[loc + 2] = 0; // blue
    
    loc = (locSeed + 2) * COLOR_DEPTH;
    pixels[loc + 0] = 0; // red
    pixels[loc + 1] = 255; // green
    pixels[loc + 2] = 0; // blue
    
    loc = (locSeed + 3) * COLOR_DEPTH;
    pixels[loc + 0] = 0; // red
    pixels[loc + 1] = 255; // green
    pixels[loc + 2] = 255; // blue
    
    loc = (locSeed + 4) * COLOR_DEPTH;
    pixels[loc + 0] = 0; // red
    pixels[loc + 1] = 0; // green
    pixels[loc + 2] = 255; // blue
    
    loc = (locSeed + 5) * COLOR_DEPTH;
    pixels[loc + 0] = 255; // red
    pixels[loc + 1] = 0; // green
    pixels[loc + 2] = 255; // blue
}


//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    /*
	ofSetColor(20, 20, 20);
	ofDrawBitmapString("openFrameworks UDP Send Example ", 15, 30);
    ofDrawBitmapString("drag to draw", 15, 50);
	for(unsigned int i=1;i<stroke.size();i++){
		ofLine(stroke[i-1].x,stroke[i-1].y,stroke[i].x,stroke[i].y);
	}
     */
    
    // Update pixel pattern
    rotatePixels();
    
    // Send to strip
    //string output(pixels);
    //printf("$s \n", output);
    udpConnection.Send(pixels,pixelsLength);

}

void testApp::rotatePixels() {
    char first0 = pixels[0];
    char first1 = pixels[1];
    char first2 = pixels[2];
    for (int i = 0; i < PIXEL_COUNT - 1; ++i) {
        int loc0 = i * COLOR_DEPTH + 0;
        int loc1 = i * COLOR_DEPTH + 1;
        int loc2 = i * COLOR_DEPTH + 2;
        pixels[loc0] = pixels[loc0 + COLOR_DEPTH];
        pixels[loc1] = pixels[loc1 + COLOR_DEPTH];
        pixels[loc2] = pixels[loc2 + COLOR_DEPTH];
    }
    pixels[pixelsLength - 3 + 0] = first0;
    pixels[pixelsLength - 3 + 1] = first1;
    pixels[pixelsLength - 3 + 2] = first2;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){


}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	stroke.push_back(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	stroke.clear();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	string message="";
	for(unsigned int i=0; i<stroke.size(); i++){
		message+=ofToString(stroke[i].x)+"|"+ofToString(stroke[i].y)+"[/p]";
	}
	//udpConnection.Send(message.c_str(),message.length());
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
