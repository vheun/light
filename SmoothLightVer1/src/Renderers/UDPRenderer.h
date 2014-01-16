//
//  UDPRenderer.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef __SmoothLightVer1__UDPRenderer__
#define __SmoothLightVer1__UDPRenderer__

#include <iostream>

#include "ofxNetwork.h"
#include "Screen.h"
#include "Renderer.h"
#include "PixelStripString2D.h"

class UDPRenderer: public Renderer {
public:
    //UDPRenderer();
    //~UDPRenderer();
    
    virtual void initRenderer();
    virtual void renderScreen(Screen &screen);
private:
    ofxUDPManager udpConnection;
};

#endif /* defined(__SmoothLightVer1__UDPRenderer__) */
