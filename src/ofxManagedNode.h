//
//  ofxManagedNode.h
//  example
//
//  Created by hiz on 2015/07/05.
//
//

#ifndef __example__ofxManagedNode__
#define __example__ofxManagedNode__

#include "ofMain.h"

class ofxManagedNode {
public:
    ofxManagedNode():deleted(false), active(true), visible(true) {}
    ~ofxManagedNode() {delete _node;}
    virtual void update() = 0;
    void draw()                   { if(_node != NULL) _node->draw();  }
    bool isActive()               { return active; }
    bool isVisible()              { return visible;}
    bool isDeleted()              { return deleted;}
    void setActive( bool active ) { this->active  = active; }
    void setVisible(bool visible) { this->visible = visible;}
    void setDeleted()             { this->deleted = true;   }
    void    setNode(ofNode *node) { this->_node = node;   }
    ofNode *node()                { return _node;}
private:
    ofNode *_node;
    bool deleted;
    bool active;
    bool visible;
};

#endif /* defined(__example__ofxManagedNode__) */
