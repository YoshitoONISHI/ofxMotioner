//
//  ofxMotionerUtils.h
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#ifndef __ofxMotioner__Utils__
#define __ofxMotioner__Utils__

#include <iostream>
#include <string>
#include "ofxMotionerConstants.h"

OFX_MOTIONER_NAMESPACE_BEGIN

std::string getJointName(int index);
int getJointIndex(const std::string &name);

bool isEndSite(int nodeId);

OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__Utils__) */
