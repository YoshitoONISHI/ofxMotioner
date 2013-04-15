//
//  ofxMotionerConstants.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotionerConstants.h"

namespace ofxMotioner {
    
    const int N_END_SITE = 5;
    
    const int END_SITE[N_END_SITE] =
    {
        JOINT_HEAD,
        JOINT_LEFT_TOE,
        JOINT_RIGHT_TOE,
        JOINT_LEFT_HAND,
        JOINT_RIGHT_HAND,
    };

    const string OSC_ADDR = "/ram/skeleton";
    
    float TIME_OUT_DUR = 0.5f;
}