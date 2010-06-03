#ifndef __ACTOR_H_
#define __ACTOR_H_

#include "ofMain.h"
#include "actorBase.h"
#include "animationValue.h"
#include "animationCue.h"
#include <queue>
#include <list>


class actor: public actorBase {
protected:
	animationValue<ofPoint> pos;
	animationValue<ofPoint> rot;
	animationValue<float> alpha_anime;
	
	std::queue<animationCue> animationCues;
	bool loop;
	
public:
	actor();
	actor(ofPoint _pos);
	
	void setPosition(ofPoint pos);
	void setRotation(ofPoint rot);
	
	void pushMove(int duration, const ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void pushMove(animationCue cue);
	void move(int duration, const ofPoint pos, float (*f)(float)=animationFunctions::easeOut);
	void move(animationCue cue);
	
	void setLoop(bool b);
	inline bool isLoop() {return loop;};
protected:
	virtual void update(int sec);
	virtual void draw();
};


#endif
