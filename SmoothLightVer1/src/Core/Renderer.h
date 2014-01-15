//
//  Renderer.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__Renderer__
#define __SmoothLightVer1__Renderer__

#include <iostream>

#include "Screen.h"

class Renderer {
public:
    virtual void initRenderer();
    virtual void renderScreen(Screen &screen);
private:
};

#endif /* defined(__SmoothLightVer1__Renderer__) */
