//
//  ofxMotioner.h
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#ifndef __ofxMotioner__ofxMotioner__
#define __ofxMotioner__ofxMotioner__

#include "ofxMotionerConstants.h"
#include "ofxMotionerUtils.h"
#include "ofxMotionerNode.h"
#include "ofxMotionerSkeleton.h"

#include "ofMain.h"
#include "ofxOscReceiver.h"

namespace ofxMot = ofxMotioner;

namespace ofxMotioner {
    
    void setup(int oscIncomingPort = 10000);
    void update();
    void draw();
    void debugDraw();
    
    enum DrawSkeletonType {
        DRAW_SKELETON_BASIC,
        //DRAW_SKELETON_SHADED,
    };
    
    void drawSkeleton(DrawSkeletonType drawType, SkeletonPtr skl);
    
    struct EventArgs {
        SkeletonPtr skeleton;
    };
    
    extern ofEvent<EventArgs> setupSkeletonEvent;
    extern ofEvent<EventArgs> updateSkeletonEvent;
    extern ofEvent<EventArgs> drawSkeletonEvent;
    extern ofEvent<EventArgs> exitSkeletonEvent;
    
}

#endif /* defined(__ofxMotioner__ofxMotioner__) */
