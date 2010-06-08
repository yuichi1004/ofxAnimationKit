#ifndef __VIDEO_ACTOR_H__
#define __VIDEO_ACTOR_H__

#include "ofMain.h"
#include "actor.h"


class videoActor: public actor {
protected:
	ofVideoPlayer* video;
	bool is_video_owner;
	
	bool is_playing;
	
public:
	videoActor(ofPoint _pos=ofPoint(0,0,0));
	videoActor(string file, ofPoint _pos=ofPoint(0,0,0));
	~videoActor();
	
	void load(string file);
	ofVideoPlayer* getVideoPlayer();
	
	ofPoint getSize();
	
protected:
	virtual void onUpdate(int msec);
	virtual void onDraw();
};


#endif
