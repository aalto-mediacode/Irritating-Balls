#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "Mover.h"
#include "Synth.h"

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
   // void collisionDetection(int i);
   
    void mousePressed(int x, int y, int button);
   
    
    void audioOut(float * output, int bufferSize, int nChannels);
    
    int bufferSize;
    int sampleRate;
    
    //maxiOsc mySine, myOtherSine;
    
    //vector <Mover> myMover;
    vector <Synth> mySynth;
    ofVec2f mouse; //important default thing
    float distance;
    //int moverAmount;
    
};
