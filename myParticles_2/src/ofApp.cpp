#include "ofApp.h"

/***
 http://www.kamend.com/2011/11/point-sprites-in-openframeworks/
 
 Since, I could not find any tutorial on using GL_POINT_SPRITES in OF007, I decided to write one. 
 In short, you could use ofVboMesh with setMode(OF_PRIMITIVE_POINTS) to draw point sprites using a
 texture by your choice, but have in mind that the texture has to be power-of-two sized, so before 
 loading your images you must call ofDisableArbTex();
***/

const int numParticles = 100;
ofVboMesh mesh; // ofMesh does the same
ofMesh meshSpark;
ofImage texture;
ofImage textureSpark;

//--------------------------------------------------------------
void ofApp::setup(){
    
    // setup
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    meshSpark.clear();
    meshSpark.setMode(OF_PRIMITIVE_POINTS);
    
    mesh.clear();
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for(int i=0;i<numParticles;i++) {
        
        {
        ofVec2f p = ofVec2f(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
        mesh.addVertex(p);
        mesh.addColor(ofColor(ofRandom(250,255),ofRandom(0,255),ofRandom(0,255)));
        }
        
        {
        ofVec2f p = ofVec2f(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()));
        meshSpark.addVertex(p);
        meshSpark.addColor(ofColor(ofRandom(250,255),ofRandom(0,255),ofRandom(0,255)));
        }
    }
    
    ofDisableArbTex();
    texture.loadImage("grad.png");
    textureSpark.loadImage("spark.png");

//    glPointSize(128);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i=0;i<numParticles;i++) {
        ofVec2f p = mesh.getVertex(i);
        
        p.x += ofRandomf() * 1;
        p.y += ofRandomf() * 1;
        
        mesh.setVertex(i, p);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    
    ofEnableAlphaBlending();
    ofEnablePointSprites();
    
    glPointSize(30);
    texture.getTextureReference().bind();
    mesh.drawFaces();

    textureSpark.getTextureReference().bind();
    glPointSize(ofRandom(20,50));
    meshSpark.draw();
    
    ofDisablePointSprites();
    
    glBegin(GL_POINTS);
    glVertex2d(100, 100);
    glEnd();
}

// EOF //