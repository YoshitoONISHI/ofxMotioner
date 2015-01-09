//
//  ofxMotionerNode.h
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#ifndef __ofxMotioner__Node__
#define __ofxMotioner__Node__

#include "ofMain.h"
#include "ofxMotionerConstants.h"

OFX_MOTIONER_NAMESPACE_BEGIN

#pragma mark ___________________________________________________________________
struct Node : public ofNode {
    Node();
    virtual ~Node() {}
    
    void customDraw();
    
    string name;
    int id;
    float size;
};

#pragma mark ___________________________________________________________________
struct NodeFinder {
    NodeFinder(const string &name);
    NodeFinder(int id);
    
    bool operator ()(const Node &n);
    
    enum Mode { NAME, ID, };
    
    string name;
    int id;
    Mode mode;
};

typedef vector<ofxMotioner::Node> NodeVec;

OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__Node__) */
