#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "ofMain.h"
#include "actorBase.h"
#include "animationValue.h"
#include "animationCue.h"
#include "IAnimatable.h"
#include <queue>
#include <list>


class actor: public actorBase, IAnimatable {
protected:
	animationValue<ofPoint> pos;
	animationValue<ofPoint> rot;
	animationValue<ofPoint> scale;
	animationValue<float> alpha_anime;
	
	std::queue<animationCue> animationCues;
	bool loop;
	
public:
	actor();
	actor(ofPoint _pos);
	
	void setPosition(ofPoint pos);
	void setRotation(ofPoint rot);
	void setScale(ofPoint scale);
	void setAlpha(float alpha);
	ofPoint getPosition();
	ofPoint getRotation();
	ofPoint getScale();
	float getAlpha();
	
	void pushMove(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void pushMove(animationCue cue);
	void move(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void move(animationCue cue);
	
	void setLoop(bool b);
	inline bool isLoop() {return loop;};
	
	bool isAnimationFinished();

protected:
	virtual void onUpdate(int msec);
	virtual void onDraw();
};


#endif
