//
//  OneStringTestLayout.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#ifndef __SmoothLightVer1__OneStringTestLayout__
#define __SmoothLightVer1__OneStringTestLayout__

#include <iostream>
#include "LayoutBuilder.h"

class OneStringTestLayout : public LayoutBuilder {
public:
    void buildLayout() {
        // Create the pixel strip strings and pixel strips
        pixel_strip_list pixelStrips;
        pixelStrips.push_back(PixelStrip2D(ofPoint(53,0), ofPoint(0,0), 54));
        pixelStrips.push_back(PixelStrip2D(ofPoint(0,1), ofPoint(53,1), 54));
        pixelStrips.push_back(PixelStrip2D(ofPoint(53,2), ofPoint(0,2), 54));
        pixelStrips.push_back(PixelStrip2D(ofPoint(0,3), ofPoint(53,3), 54));
        PixelStripString2D pixelStripString;
        pixelStripString.initStripString(pixelStrips, "192.168.1.54", 8888);
        pixelStripStrings.push_back(pixelStripString);
        
        // Bounding box for all pixel strips
        //BoundingBox2D bBox;
        bBox.coverPixelStrips(pixelStrips);
    }
};

#endif /* defined(__SmoothLightVer1__OneStringTestLayout__) */
