//
//  PixelStrip2D.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef SmoothLightVer1_PixelStrip2D_h
#define SmoothLightVer1_PixelStrip2D_h

#include "ofMain.h"

typedef ofPoint Pixel2D;

struct PixelStrip2D {
    PixelStrip2D(ofPoint pp1, ofPoint pp2, int pCount): p1(pp1), p2(pp2), pixelCount(pCount) {};
    
    ofPoint p1;
    ofPoint p2;
    int pixelCount;
};

typedef vector<PixelStrip2D> pixel_strip_list;
typedef vector<PixelStrip2D>::iterator pixel_strip_it;

#endif
