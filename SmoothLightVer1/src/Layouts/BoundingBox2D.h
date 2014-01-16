//
//  BoundingBox2D.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/16/14.
//
//

#ifndef SmoothLightVer1_BoundingBox2D_h
#define SmoothLightVer1_BoundingBox2D_h

#include "ofMain.h"
#include "PixelStrip2D.h"

struct BoundingBox2D {
public:
    /**
     Sets this bounding box size to cover all pixels within a list of pixel strips.
     */
    void coverPixelStrips(pixel_strip_list pixelStrips) {
        ofPoint p1 = pixelStrips[0].p1;
        ofPoint p2 = pixelStrips[0].p2;
        if (p1.x < p2.x) {
            minX = p1.x;
            maxX = p2.x;
        } else {
            minX = p2.x;
            maxX = p1.x;
        }
        if (p1.y < p2.y) {
            minY = p1.y;
            maxY = p2.y;
        } else {
            minY = p2.y;
            maxY = p1.y;
        }
        
        if (pixelStrips.size()  == 1) {
            return;
        }
        for (pixel_strip_it it = pixelStrips.begin() + 1; it != pixelStrips.end(); ++it) {
            PixelStrip2D pixelStrip = *it;
            ofPoint tempP1 = pixelStrip.p1;
            ofPoint tempP2 = pixelStrip.p2;
            // Test (min x)
            if (tempP1.x < minX) { minX = tempP1.x;}
            if (tempP2.x < minX) { minX = tempP2.x;}
            // Test (max x)
            if (tempP1.x > maxX) { maxX = tempP1.x;}
            if (tempP2.x > maxX) { maxX = tempP2.x;}
            // Test (min y)
            // Test (min x)
            if (tempP1.y < minY) { minY = tempP1.y;}
            if (tempP2.y < minY) { minY = tempP2.y;}
            // Test (max y)
            if (tempP1.y > maxY) { maxY = tempP1.y;}
            if (tempP2.y > maxY) { maxY = tempP2.y;}
        }
    }
    
    int getWidth() {
        return maxX - minX + 1;
    }
    
    int getHeight() {
        return maxY - minY + 1;
    }

private:
    int  minX, minY, maxX, maxY;
    
};


#endif
