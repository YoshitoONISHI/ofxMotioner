//
//  ofxMotionerSkeleton.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotionerSkeleton.h"

OFX_MOTIONER_NAMESPACE_BEGIN

#pragma mark ___________________________________________________________________
Skeleton::Skeleton() :
timestamp(0.0f),
mName("")
{
    createTree();
}

#pragma mark ___________________________________________________________________
vector<Node> &Skeleton::getJoints()
{
    return mJoints;
}

const vector<Node> &Skeleton::getJoints() const
{
    return mJoints;
}

Node &Skeleton::getJoint(int id)
{
    return mJoints.at(id);
}

const Node &Skeleton::getJoint(int id) const
{
    return mJoints.at(id);
}

#pragma mark ___________________________________________________________________
int Skeleton::getNumJoints() const
{
    return mJoints.size();
}

#pragma mark ___________________________________________________________________
void Skeleton::setName(const string &name)
{
    mName = name;
}

const string &Skeleton::getName() const
{
    return mName;
}

#pragma mark ___________________________________________________________________
void Skeleton::createTree()
{
    mJoints.clear();
    mJoints.assign(NUM_JOINTS, Node());
    
    mJoints.at(JOINT_ABDOMEN).setParent(mJoints.at(JOINT_HIPS));
    {
        mJoints.at(JOINT_CHEST).setParent(mJoints.at(JOINT_ABDOMEN));
        {
            mJoints.at(JOINT_NECK).setParent(mJoints.at(JOINT_CHEST));
            {
                mJoints.at(JOINT_HEAD).setParent(mJoints.at(JOINT_NECK));
            }
        }
    }
    mJoints.at(JOINT_LEFT_COLLAR).setParent(mJoints.at(JOINT_ABDOMEN));
    {
        mJoints.at(JOINT_LEFT_SHOULDER).setParent(mJoints.at(JOINT_LEFT_COLLAR));
        {
            mJoints.at(JOINT_LEFT_ELBOW).setParent(mJoints.at(JOINT_LEFT_SHOULDER));
            {
                mJoints.at(JOINT_LEFT_WRIST).setParent(mJoints.at(JOINT_LEFT_ELBOW));
                {
                    mJoints.at(JOINT_LEFT_HAND).setParent(mJoints.at(JOINT_LEFT_WRIST));
                }
            }
        }
    }
    
    mJoints.at(JOINT_RIGHT_COLLAR).setParent(mJoints.at(JOINT_ABDOMEN));
    {
        mJoints.at(JOINT_RIGHT_SHOULDER).setParent(mJoints.at(JOINT_RIGHT_COLLAR));
        {
            mJoints.at(JOINT_RIGHT_ELBOW).setParent(mJoints.at(JOINT_RIGHT_SHOULDER));
            {
                mJoints.at(JOINT_RIGHT_WRIST).setParent(mJoints.at(JOINT_RIGHT_ELBOW));
                {
                    mJoints.at(JOINT_RIGHT_HAND).setParent(mJoints.at(JOINT_RIGHT_WRIST));
                }
            }
        }
    }
    
    mJoints.at(JOINT_LEFT_HIP).setParent(mJoints.at(JOINT_HIPS));
    {
        
        mJoints.at(JOINT_LEFT_KNEE).setParent(mJoints.at(JOINT_LEFT_HIP));
        {
            mJoints.at(JOINT_LEFT_ANKLE).setParent(mJoints.at(JOINT_LEFT_KNEE));
            {
                mJoints.at(JOINT_LEFT_TOE).setParent(mJoints.at(JOINT_LEFT_ANKLE));
            }
        }
    }
    
    mJoints.at(JOINT_RIGHT_HIP).setParent(mJoints.at(JOINT_HIPS));
    {
        mJoints.at(JOINT_RIGHT_KNEE).setParent(mJoints.at(JOINT_RIGHT_HIP));
        {
            mJoints.at(JOINT_RIGHT_ANKLE).setParent(mJoints.at(JOINT_RIGHT_KNEE));
            {
                mJoints.at(JOINT_RIGHT_TOE).setParent(mJoints.at(JOINT_RIGHT_ANKLE));
            }
        }
    }
}

OFX_MOTIONER_NAMESPACE_END
