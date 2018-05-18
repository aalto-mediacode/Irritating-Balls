#include "Mover.h"
#include "Synth.h"
#include "ofxEasingFunc.h"




//--------------------------------------------------------------
void Mover::setup(ofVec2f origin){
    
    location = origin;
    maxSpeed=5;
    velocity.set(ofRandom(-maxSpeed,maxSpeed), ofRandom(-maxSpeed,maxSpeed));
    radius=50;
    
    

}

//--------------------------------------------------------------
void Mover::update(){
    location = location+velocity;
    float safespace = ((radius/2)+1);
    
    if(location.x<0+(radius/2)+safespace || location.x>ofGetWidth()-(radius/2)-safespace){
        velocity.x=velocity.x*-1;

    } else if(location.y<0+(radius/2)+safespace || location.y>ofGetHeight()-(radius/2)-safespace) {
        velocity.y=velocity.y*-1;

    };

    counter = counter+0.1;
    
}

//--------------------------------------------------------------
void Mover::draw(){
    
    ofFill();
    ofSetColor(255);
    ofDrawCircle(location, radius);
    ofSetColor(0);
    ofDrawCircle(location, (radius-3));

    

    


}
