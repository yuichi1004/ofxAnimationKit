#ifndef _camera3D_h__
#define _camera3D_h__

#include "ofMain.h"
#include "actor.h"

class camera3D: public actor {
public:
	camera3D(ofPoint _pos=ofPoint(0,0,695));

	void begin();
	void end();
};

#endif