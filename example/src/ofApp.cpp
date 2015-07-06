#include "ofApp.h"

ofImage image;
class ImageNode : public ofNode {
public:
    ImageNode() {
        if(!image.isAllocated()) {
            image.loadImage("of.png");
            image.setAnchorPercent(0.5, 0.5);
        }
    }
    
    virtual void customDraw() {
        image.draw(0,0);
    }

};

class ManagedImageNode : public ImageNode, public ofxManagedNode {
public:
    ManagedImageNode() {
        count = 0;
        setNode(new ImageNode());
    }
    virtual void update() {
        node()->tilt(1);
        count ++;
        if(count > 120) {
            setDeleted();
        }
    }
private:
    int count;
};

//--------------------------------------------------------------
void ofApp::setup(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    manager.update();
    
    ofPtr<ManagedImageNode> img = ofPtr<ManagedImageNode>(new ManagedImageNode());
    img->node()->setPosition(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
    img->node()->setScale(0.2);
    manager.nodes().push_back(img);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    manager.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
