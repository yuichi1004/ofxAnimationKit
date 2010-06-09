#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "ofMain.h"
#include "animationValue.h"
#include "animationCue.h"
#include "IActor.h"
#include <queue>
#include <list>

/**
 * @brief Represents animation-enabled 3D/2D object.
 *
 * This is the most basic class of the ofxAnimationKit.
 * Any animatable objects derived this class.
 *
 * You can make original animation-enabled classes deriving this class.
 * In this case, the derived class may basically override functions, onUpdate(int) and onDraw().
 */
class actor: public IActor {
protected:
	animationValue<ofPoint> pos;
	animationValue<ofPoint> rot;
	animationValue<ofPoint> scale;
	animationValue<float> alpha_anime;
	ofPoint basePoint;
	
	std::queue<animationCue> animationCues;
	bool loop;
	
public:
	actor();
	actor(ofPoint _pos);
	
	void setPosition(ofPoint pos);
	void setRotation(ofPoint rot);
	void setScale(ofPoint scale);
	void setAlpha(float alpha);
	void setBasePoint(ofPoint basePoint);
	ofPoint getPosition();
	ofPoint getRotation();
	ofPoint getScale();
	float getAlpha();
	ofPoint getBasePoint();
	ofPoint getSize();
	
	void pushMove(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void pushMove(animationCue cue);
	void move(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void move(animationCue cue);
	
	void setLoop(bool b);
	inline bool isLoop() {return loop;};
	
	bool isAnimationFinished();
	
	void update(int msec);
	void draw();
		
protected:
	virtual void onUpdate(int msec);
	virtual void onDraw();
};


#endif
