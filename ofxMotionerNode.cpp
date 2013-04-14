//
//  ofxMotionerNode.cpp
//  ofxMotioner
//
//  Created by Onishi Yoshito on 4/15/13.
//
//

#include "ofxMotionerNode.h"


using namespace ofxMotioner;

//----------------------------------------------------------------------------------------
Node::Node() :
size(5.0f)
{
    
}

//----------------------------------------------------------------------------------------
void Node::customDraw()
{
    ofBox(size);
    ofDrawAxis(size);
}

//----------------------------------------------------------------------------------------
NodeFinder::NodeFinder(const string &name) : name(name), id(0), mode(NAME)
{
}

//----------------------------------------------------------------------------------------
NodeFinder::NodeFinder(int id) : id(id), name(""), mode(ID)
{
}

//----------------------------------------------------------------------------------------
bool NodeFinder::operator ()(const Node &n)
{
    switch (mode) {
        case NAME: return (n.name == name);
        case ID: return (n.id == id);
    }
}