//
//  PixelStripString.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#ifndef SmoothLightVer1_PixelStripString2D_h
#define SmoothLightVer1_PixelStripString2D_h

#include <vector>

#include "PixelStrip2D.h"

using std::string;

class PixelStripString2D {
public:
    void initStripString(pixel_strip_list strips, string newIp, int newPort ){
        pixelStrips = strips;
        ip = newIp;
        port = newPort;
    }
    
    const pixel_strip_list &getPixelStrips() {
        return pixelStrips;
    }
    
    const string &getIp() {
        return ip;
    }
    
    const int &getPort() {
        return port;
    }
private:
    pixel_strip_list pixelStrips;
    string ip;
    int port;
};

typedef vector<PixelStripString2D> pixel_strip_strings_list;
typedef vector<PixelStripString2D>::iterator pixel_strip_strings_it;

#endif
