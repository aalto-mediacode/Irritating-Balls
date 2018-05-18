#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    
    //GRAPHICS
    
    ofSetCircleResolution(100);
    ofSetLineWidth(2);
    ofEnableSmoothing();
    ofBackground(0);
    
    //SOUND
    
    sampleRate     = 44100; /* Sampling Rate */
    bufferSize    = 512; /* Buffer Size */
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    
    //END OF THE SETUP
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
    
}
//--------------------------------------------------------------
void ofApp::update(){

    mouse.set(mouseX, mouseY);
    for(int i=0; i<mySynth.size();i++){
        mySynth[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i=0; i<mySynth.size();i++){
        mySynth[i].draw();
    }
    
}
//--------------------------------------------------------------

void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
   
    
    for (int i = 0; i < bufferSize; i++){

        float mixer=1.0/(float(mySynth.size()*0.75));
        double signal=0;
        
        for(int k = 0; k < mySynth.size(); k++) {
            signal += (mySynth[k].signalOut())*mixer;
        }
        
        
        output[i*nChannels] = signal;
        output[i*nChannels +1] = signal;
                
    }
}

//--------------------------------------------------------------

 /*  void ofApp::collisionDetection(int i){
 for(int k=0;k<i;k++){
        float distance = myMover[i].location.distance(myMover[k].location);
        if(distance<myMover[i].radius*2){
            myMover[i].velocity*=-1;
            myMover[k].velocity*=-1;
        }
    }
  }
  */

//--------------------------------------------------------------

void ofApp::mousePressed(int x, int y, int button){
    if(mySynth.size()<=4){
        int synthID = mySynth.size()-1;
        mouse.set(x,y);
        
        if(mySynth.size()>0 &&
            mySynth[synthID].myMover.size()<3){
            mySynth[synthID].setup(mouse,synthID);//add mover
            
    } else if (mySynth.size()<4){
        Synth newSynth;
        newSynth.setup(mouse, synthID);//add mover
        mySynth.push_back(newSynth);
    }
    }
}
