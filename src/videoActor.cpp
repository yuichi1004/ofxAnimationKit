#include "videoActor.h"


videoActor::videoActor(ofPoint _pos){
	video = NULL;
	setPosition(_pos);
	
	is_video_owner = true;
}


videoActor::videoActor(string file, ofPoint _pos): actor(_pos){
	load(file);
	setPosition(_pos);

	is_video_owner = true;
}


videoActor::~videoActor(){
	if ( is_video_owner && !video )
		delete video;
}


void videoActor::load(string file) {
	video = new ofVideoPlayer();
	video->loadMovie(file);
}


ofVideoPlayer* videoActor::getVideoPlayer() {
	return video;
}


void videoActor::onUpdate(int msec){
	actor::onUpdate(msec);
}


void videoActor::onDraw(){
	actor::onDraw();
	if ( video!=NULL ){
		glPushMatrix();
		glTranslatef(-video->getWidth()/2.0f,-video->getHeight()/2.0f,0.0f);
		video->draw(0, 0);
		glPopMatrix();
	}
}


ofPoint videoActor::getSize() {
	return ofPoint(video->getWidth(), video->getHeight(), 0);
}

