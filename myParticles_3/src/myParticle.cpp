//
//  myParticle.cpp
//  myParticles
//
//  Created by Yongduek Seo on 2014. 10. 6..
//
//

#include "myParticle.h"

void myParticle::setup(float x, float y) {
    updateTime = ofGetElapsedTimeMillis();
    
    if (x==-1 && y==-1)
        p = ofVec2f (ofGetWidth()/2,10);
    else
        p = ofVec2f (x,y);
    
    v = ofVec2f (ofRandom(-200., 200.), ofRandom(-500.,100)); // pixels/second
    a = ofVec2f (0, 9800/20); // pixels/second^2
                              // gravity: 9.8 meter/sec^2 = 9800 mili-meter/sec^2
    mass = 1.;
    
    mRadius = ofRandom (4, 20);
    mLifeSpan = mLifeTime = ofRandom(MAX_LIFE_SPAN); // seconds.
    mTimeElapsed = 0;
    mColor = ofColor(ofRandom(200,255), ofRandom(200,255), ofRandom(200,255));
    
    cerr << "v0=" << v << " a0=" << a << endl;
    
    trajectory.push_back(p);
}

void myParticle::update() {
    if (this->dead()) return;
    
    // time update
    float time = ofGetElapsedTimeMillis();
    
    float dt = (time - updateTime)/1000.;
    updateTime = time;
    
    // life left
    mLifeSpan -= dt;
    mTimeElapsed += dt;
    //        mAlpha = ofMap(mLifeSpan, 0, MAX_LIFE_SPAN, 0, 255);
    mAlpha = 255.*(exp(mTimeElapsed/mLifeTime));
    
    // motion update
    v = v + a * dt;
    p = p + v * dt + .5*a*dt*dt;
    
    trajectory.push_back(p);
    
    ofVec2f dp = (p - pp)/dt;
    pp = p;
    
    cerr
    << "life= " << mLifeSpan
    << "  dt= " << dt
    << "  a=" << a
    << "  v=" << v
    << "  p=" << dp << endl;
}; //

void myParticle::draw() {
    if (this->dead()) return;
    
    ofEnableAlphaBlending();
    
    // trajectory
    ofSetColor (mColor, mAlpha);
    ofCircle(trajectory[0][0], trajectory[0][1], 2);
    for (int i=1; i<trajectory.size(); i++) {
        unsigned lineWidth = 50.*(trajectory.size()-i)/trajectory.size() * ((float)mLifeSpan/MAX_LIFE_SPAN);
        ofSetLineWidth(lineWidth);
        ofLine(trajectory[i-1], trajectory[i]);
        //ofCircle(trajectory[i], 2);
    }
    
    // current position
    ofSetColor (mColor, mAlpha);
    ofCircle (p.x, p.y, mRadius);
    
    ofDisableAlphaBlending();
};

bool myParticle::dead() {
    return mLifeSpan<=0;
}

