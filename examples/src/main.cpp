#include "ofMain.h"
#include "ofAppGlutWindow.h"

#include "ofxMotioner.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    /// this method is called the same number of all skeletons
    void onDrawSkeleton(ofxMotioner::EventArgs &e);
    
    ofEasyCam mCam;
};

//----------------------------------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    
    /// setup ofxMotioner and setup OSC incoming port(argument0)
    /// default incoming port is 10000(same as MOTIONER application)
    ofxMotioner::setup();
    
    /// add callback event listener
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
    
    /// notify ofxMotioner::drawSkeletonEvent
    ofxMotioner::draw();
    /// debug drawing skeletons
    //ofxMotioner::debugDraw();
    
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
