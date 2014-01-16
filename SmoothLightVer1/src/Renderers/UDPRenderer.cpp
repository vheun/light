//
//  UDPRenderer.cpp
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/15/14.
//
//

#include "UDPRenderer.h"

//--------------------------------------------------------------

void UDPRenderer::initRenderer() {
    udpConnection.Create();

}

void UDPRenderer::renderScreen(Screen &screen) {
    // Get screen info
    pixel_strip_strings_list pixelStripStrings = screen.getPixelStripStrings();
    ofPixels pixels = screen.getPixels();

    // Render pixels to screen by iterating through each pixel strip string,
    // assembling the data for that pixel strip string, then sending that
    // data via UDP
    for (pixel_strip_strings_it it = pixelStripStrings.begin(); it != pixelStripStrings.end(); ++it) {
        PixelStripString2D pixelStripString = *it;
        pixel_strip_list pixelStrips = pixelStripString.getPixelStrips();
        
        // Vector for holding calculated strip pixel colors
        vector<char> stripPixels;
        
        for (pixel_strip_it itt = pixelStrips.begin(); itt != pixelStrips.end(); ++itt) {
            PixelStrip2D pixelStrip = *itt;
            // Find the pixels for the strip

        }
        
        // Send pixels out UDP
        char* output = &stripPixels[0];
        udpConnection.Send(output,stripPixels.size());

    }
}