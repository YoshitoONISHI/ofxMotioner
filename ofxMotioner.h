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
#include "ofxOscMessage.h"

OFX_MOTIONER_NAMESPACE_BEGIN

enum DrawSkeletonType {
    DRAW_SKELETON_BASIC,
    //DRAW_SKELETON_SHADED,
};

void updateWithOscMessage(ofxOscMessage &m);
void update();
void draw();
void debugDraw();
void drawSkeleton(SkeletonPtr skl,
                  DrawSkeletonType drawType = DRAW_SKELETON_BASIC);

SkeletonMap& getSkeletons();

struct EventArgs {
    SkeletonPtr skeleton;
};

extern ofEvent<EventArgs> setupSkeletonEvent;
extern ofEvent<EventArgs> updateSkeletonEvent;
extern ofEvent<EventArgs> drawSkeletonEvent;
extern ofEvent<EventArgs> exitSkeletonEvent;


OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__ofxMotioner__) */
