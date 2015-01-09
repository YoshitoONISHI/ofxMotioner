//
//  ofxMotionerNode.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotionerNode.h"


OFX_MOTIONER_NAMESPACE_BEGIN

#pragma mark ___________________________________________________________________
Node::Node() :
size(5.0f)
{
    
}

void Node::customDraw()
{
    ofDrawBox(size);
    ofDrawAxis(size);
}

#pragma mark ___________________________________________________________________
NodeFinder::NodeFinder(const string &name) : name(name), id(0), mode(NAME)
{
}

NodeFinder::NodeFinder(int id) : id(id), name(""), mode(ID)
{
}

bool NodeFinder::operator ()(const Node &n)
{
    switch (mode) {
        case NAME: return (n.name == name);
        case ID: return (n.id == id);
    }
}

OFX_MOTIONER_NAMESPACE_END