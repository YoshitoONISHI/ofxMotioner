#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "ofxMotioner.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void onDrawSkeleton(ofxMotioner::EventArgs &e);
    
    ofEasyCam mCam;
};

//----------------------------------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    
    ofxMotioner::setup();
    
    ofAddListener(ofxMotioner::drawSkeletonEvent, this, &ofApp::onDrawSkeleton);
}

//----------------------------------------------------------------------------------------
void ofApp::update()
{
    ofxMotioner::update();
}

//----------------------------------------------------------------------------------------
void ofApp::draw()
{
    ofBackgroundGradient(ofColor(50), ofColor(100));
    
    mCam.begin();
    ofxMotioner::draw(); // notified ofxMotioner::drawSkeletonEvent
    //ofxMotioner::debugDraw(); // debug drawing skeletons
    mCam.end();
}

//----------------------------------------------------------------------------------------
void ofApp::onDrawSkeleton(ofxMotioner::EventArgs &e)
{
    ofPushMatrix();
    ofPushStyle();
    
    ofxMotioner::SkeletonPtr skeleton = e.skeleton;
    ofxMotioner::NodeVec &joints = skeleton->getJoints();
    
    ofNoFill();
    
    for (size_t i=0; i<joints.size(); i++) {
        
        ofSetColor(ofColor::red);
        
        ofSetLineWidth(1.0f);
        ofxMotioner::Node &n = skeleton->getJoint(i);
        n.draw();
        
        if (!n.getParent()) continue;
        
        ofSetColor(ofColor::green);
        ofLine(n.getGlobalPosition(), n.getParent()->getGlobalPosition());
    }

    ofPopStyle();
    ofPopMatrix();
}

//----------------------------------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new ofApp()); // start the app
}
