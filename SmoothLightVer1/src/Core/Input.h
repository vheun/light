//
//  Input.h
//  SmoothLightVer1
//
//  Created by Kojo Acquah on 1/10/14.
//
//

#ifndef __SmoothLightVer1__Input__
#define __SmoothLightVer1__Input__

#include <iostream>
#include <vector.h>
#include <tr1/unordered_map>

using std::string;

class Input {
public:
    virtual void initInput() = 0;
    virtual void updateInput() = 0;
    /**
     Clears any input events queued
     */
    virtual void clearEventQueue();
    /**
     Returns string used to uniquely identify each instance of an Input object.
     */
    const string &getId();
protected:
    string id;
};

typedef std::tr1::unordered_map<string,Input*> input_map;
typedef std::tr1::unordered_map<string,Input*>::iterator input_it;
//typedef vector<Input*>::iterator input_it;

#endif /* defined(__SmoothLightVer1__Input__) */
