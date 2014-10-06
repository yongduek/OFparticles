//
//  myParticle.h
//  myParticles
//
//  Created by Yongduek Seo on 2014. 10. 6..
//
//

#ifndef __myParticles__myParticle__
#define __myParticles__myParticle__

#include <stdio.h>
#include <vector>
#include <ofMain.h>

#define MAX_LIFE_SPAN  100

class myParticle {

public:

    float updateTime;
    float mRadius;
    int   mLifeSpan;
    float mLifeTime, mTimeElapsed;
    ofColor mColor;
    unsigned mAlpha;
    
    float   mass;    // kilogram
    ofVec2f p, v, a; // position, velocity, acceleration
    
    ofVec2f pp;
    std::vector<ofVec2f> trajectory;
    
    //    myParticle() {}
    myParticle(float x, float y) { setup (x, y); }
    
    void setup(float x=-1, float y=-1);
    void update();
    void draw();
    bool dead();
};


#endif /* defined(__myParticles__myParticle__) */
