## ofxMotioner
----

### setup

    ofxMotioner::setup(10000); /// argument0: osc incoming port(default = 10000)
    
### update

    ofxMotioner::update();
    
### debug drawing

draw all skeletons

    ofxMotioner::debugDraw();
    
    
### callback event

	class ofApp : public ofBaseApp {
	public:
	    void setup();
	    void update();
	    void draw();
	    
	    // this method is called the same number of all skeletons
	    void onDrawSkeleton(ofxMotioner::EventArgs &e);
	    
	    ofEasyCam mCam;
	};

	//----------------------------------------------------------------------------------------
	void ofApp::setup()
	{	    
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
	    mCam.begin();
	    ofxMotioner::draw(); // notified ofxMotioner::drawSkeletonEvent
	    mCam.end();
	}
	
	//----------------------------------------------------------------------------------------
	void ofApp::onDrawSkeleton(ofxMotioner::EventArgs &e)
	{
		// do some drawing staffs
	}

### ofxMotioner::Skeleton

	// this method is called the same number of all skeletons
    void ofApp::onDrawSkeleton(ofxMotioner::EventArgs &e)
    {
    	// one skeleton
    	ofxMotioner::SkeletonPtr skeleton = e.skeleton;
    	
    	// name
    	skeleton->getName();
    	
    	// get a joint Node
    	skeleton->getJoint(ofxMotioner::JOINT_HEAD);
    }
    
    
### ofxMotioner::Node
`ofxMotioner::Node` inherit from `ofNode`
`ofxMotioner::NodeVec` is typedef of `std::vector<ofxMotioner::Node>`

	// this method is called the same number of all skeletons
    void ofApp::onDrawSkeleton(ofxMotioner::EventArgs &e)
    {
    	ofxMotioner::NodeVec &joints = skeleton->getJoints();
    	
    	for (int i=0; i<joints.size(); i++) {
        
        	ofxMotioner::Node &n = joints.at(i);
        	
    	    // draw node
	        n.draw();
        	
        	if (!n.getParent()) continue;
        	
    	    // draw line
	        ofSetColor(ofColor::green);
        	ofLine(n.getGlobalPosition(), n.getParent()->getGlobalPosition());
    	}
    }


