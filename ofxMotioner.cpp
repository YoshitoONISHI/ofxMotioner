//
//  ofxMotioner.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotioner.h"

namespace ofxMotioner {
    
    static ofxOscReceiver oscReceiver;
    static map<string, SkeletonPtr > skeletons;
    
    static void updateWithOscMessage(ofxOscMessage &m);
    
    ofEvent<EventArgs> drawSkeletonEvent;;
    
    
    void setup(int oscIncomingPort)
    {
        skeletons.clear();
        oscReceiver.setup(oscIncomingPort);
    }
    
    void update()
    {
        while (oscReceiver.hasWaitingMessages()) {
            ofxOscMessage m;
            oscReceiver.getNextMessage(&m);
            updateWithOscMessage(m);
        }
        
        SkeletonMap::iterator it = skeletons.begin();
        
        while (it != skeletons.end()) {
            SkeletonPtr skl = it->second;
                    
            if (ofGetElapsedTimef() - skl->timestamp >= 1.0) {
                skeletons.erase(it++);
            }
            else {
                ++it;
            }
        }
    }
    
    void draw()
    {
        static EventArgs args;
        
        for (SkeletonMap::iterator it = skeletons.begin(); it!=skeletons.end(); ++it) {
            args.skeleton = it->second;
            ofNotifyEvent(drawSkeletonEvent, args);
        }
    }
    
    void debugDraw()
    {
        for (SkeletonMap::iterator it = skeletons.begin(); it!=skeletons.end(); ++it) {
            drawSkeleton(DRAW_SKELETON_BASIC, it->second);
        }
    }
    
    void updateWithOscMessage(ofxOscMessage &m)
    {
        if (m.getAddress() == OSC_ADDR) {
            
            const string name = m.getArgAsString(0);
            
            if (skeletons.find(name)==skeletons.end()) {
                SkeletonPtr newSkl = SkeletonPtr(new Skeleton);
                newSkl->setName(name);
                skeletons.insert(make_pair(name, newSkl));
            }
            
            SkeletonPtr skl = skeletons[name];
            
            const int nNodes = m.getArgAsInt32(1);
            
            for (int i = 0; i < nNodes; i++) {
                const string name = m.getArgAsString(i * 8 + 0 + 2);
                const float vx = m.getArgAsFloat(i * 8 + 1 + 2);
                const float vy = m.getArgAsFloat(i * 8 + 2 + 2);
                const float vz = m.getArgAsFloat(i * 8 + 3 + 2);
                const float angle = m.getArgAsFloat(i * 8 + 4 + 2);
                const float ax = m.getArgAsFloat(i * 8 + 5 + 2);
                const float ay = m.getArgAsFloat(i * 8 + 6 + 2);
                const float az = m.getArgAsFloat(i * 8 + 7 + 2);
                
                const ofVec3f position(vx, vy, vz);
                const ofVec3f axis(ax, ay, az);
                const ofQuaternion quat(angle, axis);
                
                Node &node = skl->getJoint(i);
                
                node.id = i;
                if (node.name != name)
                    node.name = name;
                node.setGlobalPosition(position);
                node.setGlobalOrientation(quat);
            }
            
            const float timeStamp = m.getArgAsFloat(2 + nNodes * 8);
            skl->timestamp = ofGetElapsedTimef();
        }
    }
    
    void drawSkeleton(DrawSkeletonType drawType, SkeletonPtr skl)
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
        ofDrawBitmapString(skl->getName(), ofPoint(0.0f, joints.at(JOINT_HEAD).size));
        ofPopMatrix();
        
        glPopAttrib();
        ofPopStyle();
        ofPopMatrix();
        
    }
    
    
    
}