//
//  ofxNodeManager.h
//  example
//
//  Created by hiz on 2015/07/05.
//
//

#ifndef __example__ofxNodeManager__
#define __example__ofxNodeManager__

#include "ofxManagedNode.h"

class ofxNodeManager {
public:
    vector<ofPtr<ofxManagedNode> > &nodes() {
        return _nodes;
    }
    
    void update() {
        for(vector<ofPtr<ofxManagedNode> >::iterator ite=_nodes.begin();ite!=_nodes.end();ite++) {
            if((*ite)->isActive())(*ite)->update();
            if((*ite)->isDeleted()) _nodes.erase(ite);
        }
    }
    
    void draw() {
        for(vector<ofPtr<ofxManagedNode> >::iterator ite=_nodes.begin();ite!=_nodes.end();ite++) {
            if((*ite)->isVisible())(*ite)->draw();
        }
    }
private:
    vector<ofPtr<ofxManagedNode> > _nodes;
};

#endif /* defined(__example__ofxNodeManager__) */
