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
    
    /// this method is called the same number of all skeletons
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
    ofxMotioner::draw(); /// notify ofxMotioner::drawSkeletonEvent
    //ofxMotioner::debugDraw(); /// debug drawing skeletons
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
    ofSetLineWidth(1.0f);
    
    for (size_t i=0; i<joints.size(); i++) {
        
        ofSetColor(ofColor::red);
        
        ofxMotioner::Node &n = joints.at(i);
        
        /// draw node
        n.draw();
        
        if (!n.getParent()) continue;
        
        ofSetColor(ofColor::green);
        
        /// draw line
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
