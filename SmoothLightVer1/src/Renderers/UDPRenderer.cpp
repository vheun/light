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
        vector<char> stripPixelsOutput;
        
        // Loop through each pixel strip. Add to output list.
        for (pixel_strip_it itt = pixelStrips.begin(); itt != pixelStrips.end(); ++itt) {
            PixelStrip2D pixelStrip = *itt;
            // Find the pixels for the strip
            ofVec2f p1(pixelStrip.p1);
            ofVec2f p2(pixelStrip.p2);
            p2 = p2 - p1;
            //p2.normalize();
            ofVec2f mid;
            float step = 1.0f/(pixelStrip.pixelCount);
            for (float i = 0; i < pixelStrip.pixelCount; ++i) {
                mid = p1 + (p2 * step * i);
                // Find pixel color from pixels list, then add each color to strip pixel array
                ofColor pixelColor = pixels.getColor(int(mid.x), int(mid.y));
                stripPixelsOutput.push_back(pixelColor.r);
                stripPixelsOutput.push_back(pixelColor.b);
                stripPixelsOutput.push_back(pixelColor.g);
            }
        }
        // Send pixels out UDP
        char* output = &stripPixelsOutput[0];
        udpConnection.Connect(pixelStripString.getIp().c_str(), pixelStripString.getPort());
        udpConnection.Send(output,stripPixelsOutput.size());
    }
}