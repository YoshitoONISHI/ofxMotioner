//
//  ofxMotionerSkeleton.h
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#ifndef __ofxMotioner__Skeleton__
#define __ofxMotioner__Skeleton__

#include "ofMain.h"

#include "ofxMotionerConstants.h"
#include "ofxMotionerNode.h"


namespace ofxMotioner {
    
    class Skeleton {
    public:
        Skeleton();
        vector<Node> &getJoints();
        const vector<Node> &getJoints() const;
        
        Node &getJoint(int id);
        const Node &getJoint(int id) const;
        
        int getNumJoints() const;
        
        void setName(const string &name);
        const string &getName() const;
        
        float timestamp;
        
    private:
        void createTree();
        
        vector<Node> mJoints;
        string mName;
        
    };
    
}

#endif /* defined(__ofxMotioner__Skeleton__) */
