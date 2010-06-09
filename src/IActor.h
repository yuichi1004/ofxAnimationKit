

#ifndef __I_ACTOR_H__
#define __I_ACTOR_H__


class IActor {
public:
	virtual void setPosition(ofPoint pos) = 0;
	virtual ofPoint getPosition() = 0;
	
	virtual void setRotation(ofPoint rot) = 0;
	virtual ofPoint getRotation() = 0;
	
	virtual void setScale(ofPoint scale) = 0;
	virtual ofPoint getScale() = 0;
	
	virtual void setBasePoint(ofPoint basePoint) = 0;
	virtual ofPoint getBasePoint() = 0;
	
	virtual ofPoint getSize() = 0;
	virtual void setAlpha(float alpha) = 0;
	virtual float getAlpha() = 0;
	
	virtual void update(int msec) = 0;
	virtual void draw() = 0;
};

#endif