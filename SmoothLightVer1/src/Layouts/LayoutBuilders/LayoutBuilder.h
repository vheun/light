//
//  LayoutBuilder.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/24/14.
//
//

#ifndef SmoothLightVer1_LayoutBuilder_h
#define SmoothLightVer1_LayoutBuilder_h

#include "PixelStripString2D.h"
#include "BoundingBox2D.h"

class LayoutBuilder {
public:
    virtual void buildLayout() = 0;
    
    const pixel_strip_strings_list &getLayoutStripStrings() {
        return pixelStripStrings;
    }
    
    const BoundingBox2D &getLayoutBoundingBox() {
        return bBox;
    }
protected:
    pixel_strip_strings_list pixelStripStrings;
    BoundingBox2D bBox;
};

#endif
