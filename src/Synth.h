#pragma once

#include "ofMain.h"
#include "Mover.h"
#include "ofxMaxim.h"

#define NUM_SYNTHS 4

class Synth{
    
private:
    
   bool firstInit;
    
public:
    
    //Synth();
    void setup(ofVec2f mouse, int synthID);
    void update();
    void draw();
    
    float signalOut();

    vector <Mover> myMover;
    float myFreq, myOtherFreq;
    maxiOsc mySine, myOtherSine;
    
    ofVec2f freqRange[NUM_SYNTHS];
    int ID;
};
