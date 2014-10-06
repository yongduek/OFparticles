// use ofMesh,sprites to render particles
//

#include "ofApp.h"
#include "myParticle.h"

const int nParticles = 50;
std::vector<myParticle> vparticles;
ofMesh mesh;
ofImage texture;

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,50); // black

    ofDisableArbTex();
    texture.loadImage("spark.png");
//    texture.loadImage("grad.png");
    
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_POINTS);

    for (int i=0; i< nParticles; i++)
        vparticles.push_back(myParticle(ofGetWidth()/2, 100));

}

//--------------------------------------------------------------
void ofApp::update(){

    mesh.clear();
    for (int i=0; i<vparticles.size(); i++) {
        vparticles[i].update();
        if (!vparticles[i].dead()) {
            mesh.addVertex(vparticles[i].p);// setVertex(i, vparticles[i].p);
            mesh.addColor(vparticles[i].mColor);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    for (int i=0; i<vparticles.size(); i++)
//        vparticles[i].draw();
    
//    ofEnableAlphaBlending();
    ofEnablePointSprites();
    
    glPointSize(30);
    texture.getTextureReference().bind();
    mesh.drawFaces();
    
    ofDisablePointSprites();
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
