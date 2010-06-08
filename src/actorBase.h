#ifndef __ACTOR_BASE_H_
#define __ACTOR_BASE_H_

#include "ofMain.h"
#include "IActor.h"

class actorBase {
protected:
	ofPoint basePoint;
	ofPoint position;
	ofPoint rotation;
	ofPoint scale;
	float alpha;
	
public:
	actorBase();
	actorBase(ofPoint _pos);
	virtual ~actorBase();
	
	virtual void setPosition(ofPoint pos);
	virtual ofPoint getPosition();

	virtual void setRotation(ofPoint rot);
	virtual ofPoint getRotation();

	virtual void setScale(ofPoint scale);
	virtual ofPoint getScale();
	
	virtual void setBasePoint(ofPoint basePoint);
	virtual ofPoint getBasePoint();
	
	virtual void setAlpha(float alpha);
	virtual float getAlpha();
	
	virtual ofPoint getSize();
	
	void update(int msec);
	void draw();
	
	virtual bool isAnimationFinished();
	
protected:
	virtual void onUpdate(int msec);
	virtual void onDraw();
};

#endif
