#ifndef __I_ANIMATABLE_H__
#define __I_ANIMATABLE_H__

#include "animationCue.h"

class IAnimatable {
public:
	virtual void pushMove(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut) = 0;
	virtual void pushMove(animationCue cue) = 0;
	virtual void move(int duration, ofPoint pos, float (*f)(float)=animationFunctions::easeOut) = 0;
	virtual void move(animationCue cue) = 0;
	
	virtual void setLoop(bool b) = 0;
	virtual bool isLoop() = 0;
	
	virtual bool isAnimationFinished() = 0;
};

#endif
