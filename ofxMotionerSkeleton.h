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

OFX_MOTIONER_NAMESPACE_BEGIN

class Skeleton {
    friend SkeletonPtr copySkeleton(const SkeletonPtr rhs);
public:
    Skeleton();
    virtual ~Skeleton() {}
    Skeleton(const Skeleton& rhs);
    Skeleton& operator = (const Skeleton& rhs);
    
    vector<Node> &getJoints();
    const vector<Node> &getJoints() const;
    
    Node &getJoint(int id);
    const Node &getJoint(int id) const;
    
    int getNumJoints() const;
    
    void setName(const string &name);
    const string &getName() const;
    
    float timestamp;
    
private:
    Skeleton& copy(const Skeleton& rhs);
    void createTree();
    
    vector<Node> mJoints;
    string mName;
    
};

SkeletonPtr copySkeleton(const SkeletonPtr rhs);

template<class NodeClass>
void createTree(vector<NodeClass>& joints)
{
    joints.clear();
    joints.assign(NUM_JOINTS, Node());
    
    joints.at(JOINT_ABDOMEN).setParent(joints.at(JOINT_HIPS));
    {
        joints.at(JOINT_CHEST).setParent(joints.at(JOINT_ABDOMEN));
        {
            joints.at(JOINT_NECK).setParent(joints.at(JOINT_CHEST));
            {
                joints.at(JOINT_HEAD).setParent(joints.at(JOINT_NECK));
            }
        }
    }
    joints.at(JOINT_LEFT_COLLAR).setParent(joints.at(JOINT_ABDOMEN));
    {
        joints.at(JOINT_LEFT_SHOULDER).setParent(joints.at(JOINT_LEFT_COLLAR));
        {
            joints.at(JOINT_LEFT_ELBOW).setParent(joints.at(JOINT_LEFT_SHOULDER));
            {
                joints.at(JOINT_LEFT_WRIST).setParent(joints.at(JOINT_LEFT_ELBOW));
                {
                    joints.at(JOINT_LEFT_HAND).setParent(joints.at(JOINT_LEFT_WRIST));
                }
            }
        }
    }
    
    joints.at(JOINT_RIGHT_COLLAR).setParent(joints.at(JOINT_ABDOMEN));
    {
        joints.at(JOINT_RIGHT_SHOULDER).setParent(joints.at(JOINT_RIGHT_COLLAR));
        {
            joints.at(JOINT_RIGHT_ELBOW).setParent(joints.at(JOINT_RIGHT_SHOULDER));
            {
                joints.at(JOINT_RIGHT_WRIST).setParent(joints.at(JOINT_RIGHT_ELBOW));
                {
                    joints.at(JOINT_RIGHT_HAND).setParent(joints.at(JOINT_RIGHT_WRIST));
                }
            }
        }
    }
    
    joints.at(JOINT_LEFT_HIP).setParent(joints.at(JOINT_HIPS));
    {
        
        joints.at(JOINT_LEFT_KNEE).setParent(joints.at(JOINT_LEFT_HIP));
        {
            joints.at(JOINT_LEFT_ANKLE).setParent(joints.at(JOINT_LEFT_KNEE));
            {
                joints.at(JOINT_LEFT_TOE).setParent(joints.at(JOINT_LEFT_ANKLE));
            }
        }
    }
    
    joints.at(JOINT_RIGHT_HIP).setParent(joints.at(JOINT_HIPS));
    {
        joints.at(JOINT_RIGHT_KNEE).setParent(joints.at(JOINT_RIGHT_HIP));
        {
            joints.at(JOINT_RIGHT_ANKLE).setParent(joints.at(JOINT_RIGHT_KNEE));
            {
                joints.at(JOINT_RIGHT_TOE).setParent(joints.at(JOINT_RIGHT_ANKLE));
            }
        }
    }
}

OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__Skeleton__) */
