#include "Synth.h"

//Synth::Synth(){firstInit = false;}

//--------------------------------------------------------------

void Synth::setup(ofVec2f mouse, int synthID){
    
 if (firstInit == false){
        myFreq = 0;
        myOtherFreq = 0;
        firstInit = true;
    }
    

    Mover newMover; //create new Mover object
    newMover.setup(mouse); //run its setup with mouse as origin
    myMover.push_back(newMover); //add it to the vector
    
    freqRange[0] = ofVec2f(0,500);
    freqRange[1] = ofVec2f(250,750);
    freqRange[2] = ofVec2f(500,1000);
    freqRange[3] = ofVec2f(750,1250);
    
    ID = synthID;

}
//--------------------------------------------------------------
void Synth::update(){
    for(int i=0; i<myMover.size();i++){
        myMover[i].update();
    }
    if(myMover.size()>1) {
        float myDist =myMover[0].location.distance(myMover[1].location);
        myFreq = ofMap(myDist,0,1500,freqRange[ID].x,freqRange[ID].y);
    }
    
    if(myMover.size()>2){
       myOtherFreq = myMover[1].location.distance(myMover[2].location);
    }
    
    
}
//--------------------------------------------------------------
void Synth::draw(){
    for(int i=0; i<myMover.size();i++){
        
        if(i>0){
            ofSetColor(255);
            ofDrawLine(myMover[i].location,myMover[i-1].location);
            
            ofNoFill();
            ofPushMatrix();
            ofTranslate(-(ofGetWidth()/2), 0);
            ofBeginShape();
            
            for (int i = 0; i < ofGetWidth()+(ofGetWidth()/2); i++){
                float x = i;
                float noise = ofSignedNoise(i/myFreq);
                float y = ofMap(noise, 0,1, ofGetHeight()/2, myOtherFreq*1.1);
                ofVertex(x,y);
            } ofEndShape();
            ofPopMatrix();

    }

    }
    
     for(int i=0; i<myMover.size();i++){
         myMover[i].draw();
     }
    
}
//--------------------------------------------------------------
float Synth::signalOut(){
   
    if(ID==0){
        double signal = mySine.triangle(myFreq+(myOtherSine.saw(myOtherFreq/5)*300));
        return signal;
    } else if (ID==1) {
        double signal = mySine.sinewave(myFreq+(myOtherSine.phasor(myOtherFreq/10)*500));
        return signal;
    } else if (ID==2) {
        double signal = mySine.saw(myFreq+(myOtherSine.saw(myOtherFreq/20)*500))*0.8;
        return signal;
    } else if (ID==3) {
        double signal = mySine.phasor(myFreq+(myOtherSine.phasor(myOtherFreq/20)*500));
        return signal;
    }
    
}
