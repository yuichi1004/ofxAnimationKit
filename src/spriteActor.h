#ifndef __SPRITE_ACTOR_H_
#define __SPRITE_ACTOR_H_

#include "ofMain.h"
#include "actor.h"


class spriteActor: public actor {
protected:
	ofImage* image;
	bool is_image_owner;
	
public:
	spriteActor(ofPoint _pos=ofPoint(0,0,0));
	spriteActor(string file, ofPoint _pos=ofPoint(0,0,0));
	~spriteActor();
	
	void loadImage(string file);
	
protected:
	virtual void onUpdate(int sec);
	virtual void onDraw();
};


#endif
