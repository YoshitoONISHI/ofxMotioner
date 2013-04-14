//
//  ofxMotionerUtils.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotionerUtils.h"
#include "ofxMotionerConstants.h"

using namespace std;

namespace ofxMotioner {

    //------------------------------------------------------------------------------------
    string getJointName(int index)
    {
        if (index==JOINT_HIPS)				return "JOINT_HIPS";
        if (index==JOINT_ABDOMEN)			return "JOINT_ABDOMEN";
        if (index==JOINT_CHEST)				return "JOINT_CHEST";
        if (index==JOINT_NECK)				return "JOINT_NECK";
        if (index==JOINT_HEAD)				return "JOINT_HEAD";
        if (index==JOINT_LEFT_HIP)			return "JOINT_LEFT_HIP";
        if (index==JOINT_LEFT_KNEE)			return "JOINT_LEFT_KNEE";
        if (index==JOINT_LEFT_ANKLE)		return "JOINT_LEFT_ANKLE";
        if (index==JOINT_LEFT_TOE)			return "JOINT_LEFT_TOE";
        if (index==JOINT_RIGHT_HIP)			return "JOINT_RIGHT_HIP";
        if (index==JOINT_RIGHT_KNEE)		return "JOINT_RIGHT_KNEE";
        if (index==JOINT_RIGHT_ANKLE)		return "JOINT_RIGHT_ANKLE";
        if (index==JOINT_RIGHT_TOE)			return "JOINT_RIGHT_TOE";
        if (index==JOINT_LEFT_COLLAR)		return "JOINT_LEFT_COLLAR";
        if (index==JOINT_LEFT_SHOULDER)		return "JOINT_LEFT_SHOULDER";
        if (index==JOINT_LEFT_ELBOW)		return "JOINT_LEFT_ELBOW";
        if (index==JOINT_LEFT_WRIST)		return "JOINT_LEFT_WRIST";
        if (index==JOINT_LEFT_HAND) 		return "JOINT_LEFT_HAND";
        if (index==JOINT_RIGHT_COLLAR) 		return "JOINT_RIGHT_COLLAR";
        if (index==JOINT_RIGHT_SHOULDER) 	return "JOINT_RIGHT_SHOULDER";
        if (index==JOINT_RIGHT_ELBOW) 		return "JOINT_RIGHT_ELBOW";
        if (index==JOINT_RIGHT_WRIST) 		return "JOINT_RIGHT_WRIST";
        if (index==JOINT_RIGHT_HAND)		return "JOINT_RIGHT_HAND";
        
        return "unknown joint index";
    }
    
    //------------------------------------------------------------------------------------
    int getJointIndex(const string &name)
    {
        if (name=="JOINT_HIPS")				return JOINT_HIPS;
        if (name=="JOINT_ABDOMEN")			return JOINT_ABDOMEN;
        if (name=="JOINT_CHEST")			return JOINT_CHEST;
        if (name=="JOINT_NECK")				return JOINT_NECK;
        if (name=="JOINT_HEAD")				return JOINT_HEAD;
        if (name=="JOINT_LEFT_HIP")			return JOINT_LEFT_HIP;
        if (name=="JOINT_LEFT_KNEE")		return JOINT_LEFT_KNEE;
        if (name=="JOINT_LEFT_ANKLE")		return JOINT_LEFT_ANKLE;
        if (name=="JOINT_LEFT_TOE")			return JOINT_LEFT_TOE;
        if (name=="JOINT_RIGHT_HIP")		return JOINT_RIGHT_HIP;
        if (name=="JOINT_RIGHT_KNEE")		return JOINT_RIGHT_KNEE;
        if (name=="JOINT_RIGHT_ANKLE")		return JOINT_RIGHT_ANKLE;
        if (name=="JOINT_RIGHT_TOE")		return JOINT_RIGHT_TOE;
        if (name=="JOINT_LEFT_COLLAR")		return JOINT_LEFT_COLLAR;
        if (name=="JOINT_LEFT_SHOULDER")	return JOINT_LEFT_SHOULDER;
        if (name=="JOINT_LEFT_ELBOW")		return JOINT_LEFT_ELBOW;
        if (name=="JOINT_LEFT_WRIST")		return JOINT_LEFT_WRIST;
        if (name=="JOINT_LEFT_HAND") 		return JOINT_LEFT_HAND;
        if (name=="JOINT_RIGHT_COLLAR") 	return JOINT_RIGHT_COLLAR;
        if (name=="JOINT_RIGHT_SHOULDER") 	return JOINT_RIGHT_SHOULDER;
        if (name=="JOINT_RIGHT_ELBOW") 		return JOINT_RIGHT_ELBOW;
        if (name=="JOINT_RIGHT_WRIST") 		return JOINT_RIGHT_WRIST;
        if (name=="JOINT_RIGHT_HAND")		return JOINT_RIGHT_HAND;
        
        return -1;
    }
    
    /// General utils
    //------------------------------------------------------------------------------------
    bool isEndSite(int nodeId)
    {
        for (int i=0; i<N_END_SITE; i++)
            if (nodeId == END_SITE[i])
                return true;
        return false;
    }
    
}