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

namespace ofxMotioner {

    //------------------------------------------------------------------------------------
    struct Node : public ofNode {
        Node();
        void customDraw();
        
        string name;
        int id;
        float size;
    };
    
    //------------------------------------------------------------------------------------
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
}

#endif /* defined(__ofxMotioner__Node__) */
