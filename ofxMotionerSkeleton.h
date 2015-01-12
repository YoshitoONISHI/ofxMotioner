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

template<class NodeType> class SkeletonBase;

typedef SkeletonBase<Node> Skeleton;
typedef ofPtr<Skeleton> SkeletonPtr;
typedef map<string, ofPtr<Skeleton> > SkeletonMap;


template<class NodeType>
ofPtr<SkeletonBase<NodeType> > copySkeleton(const ofPtr<SkeletonBase<NodeType> > rhs);

template<class NodeType>
class SkeletonBase {
public:
    typedef ofPtr<SkeletonBase<NodeType> > Ptr;
    
    static Ptr create();
    
    SkeletonBase();
    virtual ~SkeletonBase();
    SkeletonBase(const SkeletonBase& rhs);
    SkeletonBase& operator = (const SkeletonBase& rhs);
    
    vector<NodeType> &getJoints();
    const vector<NodeType> &getJoints() const;
    
    NodeType &getJoint(int id);
    const NodeType &getJoint(int id) const;
    
    int getNumJoints() const;
    
    void setName(const string &name);
    const string &getName() const;
    
    template<class NodeTypeRhs>
    void copyMatrices(ofPtr<SkeletonBase<NodeTypeRhs> > rhs);
    
    static void createTree(vector<NodeType>& joints);
    static ofPtr<SkeletonBase<NodeType> > copy(const ofPtr<SkeletonBase<NodeType> > rhs);
    
    float timestamp;
    
protected:
    SkeletonBase& copy(const SkeletonBase& rhs);
    
private:
    vector<NodeType> mJoints;
    string mName;
    
};

template<class NodeType>
typename SkeletonBase<NodeType>::Ptr SkeletonBase<NodeType>::create()
{
    return SkeletonBase<NodeType>::Ptr(new SkeletonBase<NodeType>());
}

template<class NodeType>
SkeletonBase<NodeType>::SkeletonBase() :
timestamp(0.f),
mName("")
{
    mJoints.clear();
    mJoints.assign(NUM_JOINTS, NodeType());
    createTree(mJoints);
}

template<class NodeType>
SkeletonBase<NodeType>::~SkeletonBase() {}

template<class NodeType>
SkeletonBase<NodeType>::SkeletonBase(const SkeletonBase& rhs)
{
    copy(rhs);
}

template<class NodeType>
SkeletonBase<NodeType>& SkeletonBase<NodeType>::operator = (const SkeletonBase& rhs)
{
    return copy(rhs);
}

template<class NodeType>
vector<NodeType>& SkeletonBase<NodeType>::getJoints()
{
    return mJoints;
}

template<class NodeType>
const vector<NodeType>& SkeletonBase<NodeType>::getJoints() const
{
    return mJoints;
}

template<class NodeType>
NodeType& SkeletonBase<NodeType>::getJoint(int id)
{
    return mJoints.at(id);
}

template<class NodeType>
const NodeType& SkeletonBase<NodeType>::getJoint(int id) const
{
    return mJoints.at(id);
}

template<class NodeType>
int SkeletonBase<NodeType>::getNumJoints() const
{
    return mJoints.size();
}

template<class NodeType>
void SkeletonBase<NodeType>::setName(const string &name)
{
    mName = name;
}

template<class NodeType>
const string& SkeletonBase<NodeType>::getName() const
{
    return mName;
}

template<class NodeType>
template<class NodeTypeRhs>
void SkeletonBase<NodeType>::copyMatrices(ofPtr<SkeletonBase<NodeTypeRhs> > rhs)
{
    assert(mJoints.size() == rhs->getJoints().size());
    
    for (int i=0; i<mJoints.size(); i++) {
        mJoints.at(i).setTransformMatrix(rhs->getJoint(i).getLocalTransformMatrix());
        mJoints.at(i).id = rhs->getJoint(i).id;
    }
}

template<class NodeType>
void SkeletonBase<NodeType>::createTree(vector<NodeType>& joints)
{
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

template<class NodeType>
SkeletonBase<NodeType>& SkeletonBase<NodeType>::copy(const SkeletonBase<NodeType>& rhs)
{
    mName = rhs.mName;
    mJoints = rhs.mJoints;
    createTree(mJoints);
    return *this;
}

template<class NodeType>
ofPtr<SkeletonBase<NodeType> > SkeletonBase<NodeType>::copy(const ofPtr<SkeletonBase<NodeType> > rhs)
{
    SkeletonPtr ret = SkeletonPtr(new Skeleton());
    ret->mName = rhs->mName;
    ret->mJoints = rhs->mJoints;
    ret->createTree(ret->mJoints);
    
    return ret;
}

OFX_MOTIONER_NAMESPACE_END

#endif /* defined(__ofxMotioner__Skeleton__) */
