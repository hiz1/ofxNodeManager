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

class ofxManagedNode : public ofNode {
public:
    ofxManagedNode():deleted(false), active(true), visible(true) {}
    virtual void update() = 0;
    bool isActive()               { return active; }
    bool isVisible()              { return visible;}
    bool isDeleted()              { return deleted;}
    void setActive( bool active ) { this->active  = active; }
    void setVisible(bool visible) { this->visible = visible;}
    void setDeleted()             { this->deleted = true;   }
private:
    bool deleted;
    bool active;
    bool visible;
};

#endif /* defined(__example__ofxManagedNode__) */
