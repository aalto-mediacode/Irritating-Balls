#pragma once

#include "ofMain.h"

class Mover{
    
    public:
        void setup(ofVec2f origin);
        void update();
        void draw();
    
    ofVec2f location;
    ofVec2f velocity;
    float radius;
    float counter;
    float maxSpeed;
    
};
