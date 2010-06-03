#include "actor.h"
#include "animationCue.h"
#include "ofMain.h"


// Constructor
actor::actor() {
	alpha_anime.set(1.0f);
}


actor::actor(ofPoint pos): actorBase(pos) {
	alpha_anime.set(1.0f);
}


void actor::update(int sec) {
	pos.update(sec);
	rot.update(sec);
	alpha_anime.update(sec);
	
	if (pos.isFinished()&&rot.isFinished()&&!animationCues.empty()){
		animationCue c=animationCues.front();
		if (c.isMove()){
			pos.go(c.getMove(),c.getDuration(),c.getMoveFunc());
		}
		if (c.isRotate()){
			rot.go(c.getRotate(),c.getDuration(),c.getRotateFunc());
		}
		if (c.isAlpha()) {
			alpha_anime.go(c.getAlpha(), c.getDuration(), c.getAlphaFunc());
		}
		if (loop)
			animationCues.push(c);
		animationCues.pop();
	}
}


void actor::draw() {
	ofPoint p = pos;
	ofTranslate(p.x, p.y, p.z);
	ofPoint r = rot;
	ofRotate(r.x, 1.0f, 0.0f, 0.0f);
	ofRotate(r.y, 0.0f, 1.0f, 0.0f);
	ofRotate(r.z, 0.0f, 0.0f, 1.0f);
	
	float al = (float)alpha_anime;
	int a = (int)(255.0f * (float)alpha_anime);
	ofSetColor(a, a, a, a);
}


void actor::setPosition(ofPoint pos){
	this->pos.set(pos);
	actorBase::setPosition(pos);
}


void actor::setRotation(ofPoint rot){
	this->rot.set(rot);
	actorBase::setRotation(rot);
}


void actor::pushMove(int duration, const ofPoint pos, float (*f)(float)){
	animationCue c;
	c.setMove(pos, f);
	c.setDuration(duration);
	animationCues.push(c);
}


void actor::pushMove(animationCue c){
	animationCues.push(c);
}


void actor::move(int duration, const ofPoint pos, float (*f)(float)){
	while(!animationCues.empty())
		animationCues.pop();

	this->pos.go(pos,duration,f);
}


void actor::move(animationCue c){
	if (c.isMove())
		this->pos.go(c.getMove(),c.getDuration(),c.getMoveFunc());
	if (c.isRotate())
		this->rot.go(c.getRotate(),c.getDuration(),c.getMoveFunc());
}


void actor::setLoop(bool b){
	loop = b;
}
