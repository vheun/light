#include "testApp.h"

#define BUFFER_SIZE (256)

#define FFT_SMOOTHED_FALLOFF (0.96f)
#define USE_DATA_NORMALIZATION (false)
#define USE_FFT_NORMALIZATION (false)
#define USE_SMOOTHED_FFT (true)
#define USE_DB_SPECTRUM_FFT (false)

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetCircleResolution(80);
	ofBackground(54, 54, 54);
 
    initSoundStream();
    initFFT();
    
}

void testApp::initSoundStream() {
	// 0 output channels,
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	//soundStream.listDevices();
	
	//if you want to set a different device id
	//soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
	
	int bufferSize = BUFFER_SIZE;
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	mix.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}


void testApp::initFFT() {
    
    fft = ofxFft::create(BUFFER_SIZE, OF_FFT_WINDOW_HAMMING);
    numBands = fft->getBinSize();
    
    // the fft needs to be smoothed out, so we create an array of floats
    // for that purpose:
    fftSmoothed = new float[numBands];
    dbFFT = new float[numBands];
    
    for (int i = 0; i < numBands; i++){
        fftSmoothed[i] = 0;
    }
    
    useDataNormalization = USE_DATA_NORMALIZATION;
    useFFTNormalization = USE_FFT_NORMALIZATION;
}

//--------------------------------------------------------------
void testApp::update(){
	//lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    
	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
    // Update all FFT info
    updateFFT();
}

void testApp::updateFFT() {
    // Calculate the fft
    fft->setSignal(&mix[0]);
	currentFFT = fft->getAmplitude();
    
	// Put the FFT into a "smoothed" array, by taking maximums, as peaks and then smoothing downward
    float minVal = FLT_MAX;
    float maxVal = FLT_MIN;
    float maxDbSpectrum = 0;
    
    normalizeFFTData(currentFFT);

    
	for (int i = 0;i < numBands; ++i){
		
		// let the smoothed calue sink to zero:
		fftSmoothed[i] *= FFT_SMOOTHED_FALLOFF;
		
		// take the max, either the smoothed or the incoming:
		//if (fftSmoothed[i] < currentFFT[i]) fftSmoothed[i] = currentFFT[i];
        
        float db = 20.0 *log10(1.0 + currentFFT[i]);
        if (fftSmoothed[i] < db) fftSmoothed[i] = db;

        
        //if (fftSmoothed[i] < minVal) { minVal = fftSmoothed[i]; }
        //if (fftSmoothed[i] > maxVal) { maxVal = fftSmoothed[i]; }
        
        // Convert to power spectrum
        if (USE_SMOOTHED_FFT) {
            //dbFFT[i] = 20*log10(fftSmoothed[i] + 1e-30);
            //dbFFT[i] = 20*log10(1.0 *(fftSmoothed[i] + 1));
            //dbFFT[i] = powf(fftSmoothed[i], 0.5);
            //dbFFT[i] = 20.0 * powf(fftSmoothed[i], 2.0);
            //dbFFT[i] = 10.0 *log10( powf(fftSmoothed[i], 2.0) + 1);
            dbFFT[i] = 10.0 *log10(1.0 + fftSmoothed[i]);
        } else {
            dbFFT[i] = 20*log10(currentFFT[i] + 1e-30);
        }
        
        if (dbFFT[i] > maxDbSpectrum) { maxDbSpectrum = dbFFT[i]; }
	}
    
    
    //printf("minVal %f maxVal %f \n", minVal, maxVal);
    
    /*
    float spec_range = 50.0f;
    for (int i = 0;i < numBands; ++i){
        dbFFT[i] -= maxDbSpectrum;
        dbFFT[i] = (ofClamp(dbFFT[i], -spec_range, 0) + spec_range ) / spec_range;
    }
     */
    
    
    
    // Calculate the FFT centroid
    float centroidStep = 1.0f/numBands;
    for (int i = 0; i < numBands; ++i) {
        
    }
}


//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(225);
	//ofDrawBitmapString("AUDIO INPUT EXAMPLE", 32, 32);
	//ofDrawBitmapString("press 's' to unpause the audio\n'e' to pause the audio", 31, 92);
	ofNoFill();

    drawChannels(32, 680);
    drawAverageVolume(0,0);
    drawFFT(0,0);
	
	drawCounter++;
	
    drawStreamInfo();
}

void testApp::drawChannels(int x, int y) {
    const int MIDDLE_SPACE = 20;
    const int CHANNEL_WIDTH = 256 * 2;
    const int CHANNEL_HEIGHT = 100;
    const float CHANNEL_GAIN = 180.0f;
    const int SAMPLE_DRAW_LENGHT = 2;
    
	// draw the left channel:
	ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Left Channel", 4, 18);
    
    ofSetLineWidth(1);
    ofRect(0, 0, CHANNEL_WIDTH, CHANNEL_HEIGHT);
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (unsigned int i = 0; i < left.size(); i++){
        ofVertex(i*SAMPLE_DRAW_LENGHT, CHANNEL_HEIGHT/2 -left[i] * CHANNEL_GAIN);
    }
    ofEndShape(false);
    
    ofPopMatrix();
	ofPopStyle();
    
	// draw the right channel:
	ofPushStyle();
    ofPushMatrix();
    ofTranslate(x + left.size()*SAMPLE_DRAW_LENGHT + MIDDLE_SPACE, y, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Right Channel", 4, 18);
    
    ofSetLineWidth(1);
    ofRect(0, 0, CHANNEL_WIDTH, CHANNEL_HEIGHT);
    
    ofSetColor(245, 58, 135);
    ofSetLineWidth(3);
    
    ofBeginShape();
    for (unsigned int i = 0; i < right.size(); i++){
        ofVertex(i*SAMPLE_DRAW_LENGHT, CHANNEL_HEIGHT/2 -right[i] * CHANNEL_GAIN);
    }
    ofEndShape(false);
    
    ofPopMatrix();
	ofPopStyle();
}

void testApp::drawAverageVolume(int x, int y) {
    // draw the average volume:
	ofPushStyle();
    ofPushMatrix();
    ofTranslate(565, 170, 0);
    
    ofSetColor(225);
    ofDrawBitmapString("Scaled average vol (0-100): " + ofToString(scaledVol * 100.0, 0), 4, 18);
    ofRect(0, 0, 400, 400);
    
    ofSetColor(245, 58, 135);
    ofFill();
    ofCircle(200, 200, scaledVol * 190.0f);
    
    //lets draw the volume history as a graph
    ofBeginShape();
    for (unsigned int i = 0; i < volHistory.size(); i++){
        if( i == 0 ) ofVertex(i, 400);
        
        ofVertex(i, 400 - volHistory[i] * 70);
        
        if( i == volHistory.size() -1 ) ofVertex(i, 400);
    }
    ofEndShape(false);
    
    ofPopMatrix();
	ofPopStyle();
}

void testApp::drawFFT(int x, int y) {
    const int WIDTH = 800;
    const int HEIGHT = 400;
    const float SCALE = 200.0f;
    
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(x, y, 0);
    
    ofSetLineWidth(1);
    ofRect(0, 0, WIDTH, HEIGHT);
    
	// draw the fft resutls:
	ofSetColor(255,255,255);
    
    float * fftData;
    if (USE_SMOOTHED_FFT) {
        fftData = fftSmoothed;
    } else {
        fftData = currentFFT;
    }
    
    if (USE_DB_SPECTRUM_FFT) {
        fftData = dbFFT;
    }
	
	float width = float(WIDTH) / numBands;
	for (int i = 0;i < numBands; i++){
		// (we use negative height here, because we want to flip them
		// because the top corner is 0,0)
		ofRect(i*width, HEIGHT,width,-(fftData[i] * SCALE));
	}
    
    ofPopMatrix();
	ofPopStyle();
    
}


void testApp::drawStreamInfo() {
    ofSetColor(225);
	string reportString = "buffers received: "+ofToString(bufferCounter)+"\ndraw routines called: "+ofToString(drawCounter)+"\nticks: " + ofToString(soundStream.getTickCount());
	ofDrawBitmapString(reportString, 32, 589);
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    // Set the left, right, and mix for the audio
    for (int i = 0; i < bufferSize; i++){
		left[i]	= input[i*2]*0.5;
		right[i] = input[i*2+1]*0.5;
        mix[i] = left[i] + right[i] / 2.0f;
    }

    normalizeData(left);
    normalizeData(right);
    normalizeData(mix);
    
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * calcRootMeanSquared(input, bufferSize, nChannels);
	
	bufferCounter++;
}

void testApp::normalizeData(vector<float>& data) {
    if(useDataNormalization) {
        float maxValue = 0;
        for(int i = 0; i < data.size(); i++) {
            if(abs(data[i]) > maxValue) {
                maxValue = abs(data[i]);
            }
        }
        if (maxValue == 0) {
            return;
        }
        for(int i = 0; i < data.size(); i++) {
            data[i] /= maxValue;
        }
    }
}

void testApp::normalizeFFTData(float * fftData) {
    if(useFFTNormalization) {
        float maxValue = 0;
        for(int i = 0; i < numBands; i++) {
            if(abs(fftData[i]) > maxValue) {
                maxValue = abs(fftData[i]);
            }
        }
        if (maxValue == 0) {
            return;
        }
        for(int i = 0; i < numBands; i++) {
            fftData[i] /= maxValue;
        }
    }
}

float testApp::calcRootMeanSquared(float * input, int bufferSize, int nChannels) {
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
		//left[i]		= input[i*2]*0.5;
		//right[i]	= input[i*2+1]*0.5;
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :)
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :)
	curVol = sqrt( curVol );
    
    return curVol;
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if( key == 's' ){
		soundStream.start();
	}
	
	if( key == 'e' ){
		soundStream.stop();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
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

