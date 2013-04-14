//
//  ofxMotionerConstants.h
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#ifndef __ofxMotioner__Constants__
#define __ofxMotioner__Constants__

#include "ofMain.h"

namespace ofxMotioner {
    
    class Skeleton;
    
    typedef ofPtr<Skeleton> SkeletonPtr;
    typedef map<string, ofPtr<Skeleton> > SkeletonMap;
    
    /// skeleton joints
    //--------------------
    enum JointType {
		JOINT_HIPS              = 0,
		JOINT_ABDOMEN           = 1,
		JOINT_CHEST             = 2,
		JOINT_NECK              = 3,
		JOINT_HEAD              = 4, /// end site
        
		JOINT_LEFT_HIP          = 5,
		JOINT_LEFT_KNEE         = 6,
		JOINT_LEFT_ANKLE        = 7,
		JOINT_LEFT_TOE          = 8, /// end site
        
		JOINT_RIGHT_HIP         = 9,
		JOINT_RIGHT_KNEE        = 10,
		JOINT_RIGHT_ANKLE       = 11,
		JOINT_RIGHT_TOE         = 12, /// end site
        
		JOINT_LEFT_COLLAR       = 13,
		JOINT_LEFT_SHOULDER     = 14,
		JOINT_LEFT_ELBOW        = 15,
		JOINT_LEFT_WRIST        = 16,
		JOINT_LEFT_HAND         = 17, /// end site
        
		JOINT_RIGHT_COLLAR      = 18,
		JOINT_RIGHT_SHOULDER    = 19,
		JOINT_RIGHT_ELBOW       = 20,
		JOINT_RIGHT_WRIST       = 21,
		JOINT_RIGHT_HAND        = 22, /// end site
        
		NUM_JOINTS              = 23,
	};
    
    extern const int N_END_SITE;
    extern const int END_SITE[];
    
    extern const string OSC_ADDR;
    
    extern float TIME_OUT_DUR;
}

#endif /* defined(__ofxMotioner__Constants__) */
