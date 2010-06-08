#ifndef __SPRITE_ACTOR_H__
#define __SPRITE_ACTOR_H__

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
	
	void load(string file);
	void setImage(ofImage* img, bool isOwner);
	ofImage* getImage();
	
	int getSpriteWidth();
	int getSpriteHeight();
	
	ofPoint getSize();
	
protected:
	virtual void onUpdate(int msec);
	virtual void onDraw();
};


#endif
