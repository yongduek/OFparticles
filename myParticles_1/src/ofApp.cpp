#include "ofApp.h"
#include "myParticle.h"

std::vector<myParticle> vparticles;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,50); // black
    
    for (int i=0; i<40; i++)
        vparticles.push_back(myParticle(ofGetWidth()/2, 100));
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0; i<vparticles.size(); i++)
        vparticles[i].update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<vparticles.size(); i++)
        vparticles[i].draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    for (int i=0; i<30; i++)
        vparticles.push_back(myParticle(x,y));
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
