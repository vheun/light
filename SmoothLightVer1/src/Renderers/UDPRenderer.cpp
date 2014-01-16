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

    // Render pixels to screen
    for (pixel_strip_strings_it it = pixelStripStrings.begin(); it != pixelStripStrings.end(); ++it) {
        PixelStripString2D pixelStripString = *it;
        pixel_strip_list pixelStrips = pixelStripString.getPixelStrips();
        
        for (pixel_strip_it itt = pixelStrips.begin(); itt != pixelStrips.end(); ++itt) {
            PixelStrip2D pixelStrip = *itt;
            char stripPixels[pixelStrip.pixelCount];
            
            // Find the pixels for the strip
            
            // Send pixels out UDP
            udpConnection.Send(stripPixels,pixelStrip.pixelCount);
        }

    }
}