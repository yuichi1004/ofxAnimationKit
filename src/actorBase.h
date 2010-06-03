#ifndef __ACTOR_BASE_H_
#define __ACTOR_BASE_H_

#include "ofMain.h"

class actorBase {
protected:
	ofPoint position;
	ofPoint rotation;
	float alpha;
	
public:
	actorBase();
	actorBase(ofPoint _pos);
	virtual ~actorBase();
	
	virtual void setPosition(ofPoint _pos);
	virtual void setRotation(ofPoint _rot);
	virtual ofPoint getPosition();
	virtual ofPoint getRotation();
	
	void requestUpdate(int sec);
	void requestDraw();
	
protected:
	virtual void update(int sec);
	virtual void draw();
};


#endif
