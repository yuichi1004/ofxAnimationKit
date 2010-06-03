#ifndef __ACTOR_BASE_H_
#define __ACTOR_BASE_H_

#include "ofMain.h"

class actorBase {
protected:
	ofPoint position;
	ofPoint rotation;
	ofPoint scale;
	float alpha;
	
public:
	actorBase();
	actorBase(ofPoint _pos);
	virtual ~actorBase();
	
	virtual void setPosition(ofPoint pos);
	virtual void setRotation(ofPoint rot);
	virtual void setScale(ofPoint scale);
	virtual ofPoint getPosition();
	virtual ofPoint getRotation();
	virtual ofPoint getScale();
	
	void update(int sec);
	void draw();
	
protected:
	virtual void onUpdate(int sec);
	virtual void onDraw();
};


#endif
