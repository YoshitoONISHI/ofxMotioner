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

template <class Node>
void drawSkeleton(ofPtr<SkeletonBase<Node> > skl,
                  DrawSkeletonType drawType = DRAW_SKELETON_BASIC);

SkeletonMap& getSkeletons();

struct EventArgs {
    SkeletonPtr skeleton;
};

extern ofEvent<EventArgs> setupSkeletonEvent;
extern ofEvent<EventArgs> updateSkeletonEvent;
extern ofEvent<EventArgs> drawSkeletonEvent;
extern ofEvent<EventArgs> exitSkeletonEvent;

template <class Node>
void drawSkeleton(ofPtr<SkeletonBase<Node> > skl,
                  DrawSkeletonType drawType)
{
    ofPushMatrix();
    ofPushStyle();
    glPushAttrib(GL_ENABLE_BIT);
    
    ofSetDrawBitmapMode(OF_BITMAPMODE_MODEL_BILLBOARD);
    
    vector<Node> &joints = skl->getJoints();
    
    ofNoFill();
    
    for (size_t i=0; i<joints.size(); i++) {
        
        ofSetColor(ofColor::magenta);
        
        ofSetLineWidth(1.0f);
        Node &n = skl->getJoint(i);
        n.draw();
        
        if (!n.getParent()) continue;
        
        ofSetColor(ofColor::cyan);
        ofLine(n.getGlobalPosition(), n.getParent()->getGlobalPosition());
    }
    
    ofPushMatrix();
    ofSetColor(ofColor::yellow);
    ofMultMatrix(joints.at(JOINT_HEAD).getGlobalTransformMatrix());
    ofDrawBitmapString(skl->getName(),
                       ofPoint(0.0f, joints.at(JOINT_HEAD).size));
    ofPopMatrix();
    
    glPopAttrib();
    ofPopStyle();
    ofPopMatrix();
}

OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__ofxMotioner__) */
