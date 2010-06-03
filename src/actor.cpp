#include "actor.h"
#include "actorBase.h"
#include "animationCue.h"
#include "ofMain.h"


actor::actor() {
	setScale(ofPoint(1,1,1));
	alpha_anime.set(1.0f);
}


actor::actor(ofPoint pos): actorBase(pos) {
	setScale(ofPoint(1,1,1));
	alpha_anime.set(1.0f);
}


void actor::onUpdate(int sec) {
	pos.update(sec);
	rot.update(sec);
	scale.update(sec);
	alpha_anime.update(sec);
	
	if (pos.isFinished()&&rot.isFinished()&&!animationCues.empty()){
		animationCue c=animationCues.front();
		move(c);
		if (loop)
			animationCues.push(c);
		animationCues.pop();
	}
	
	actorBase::onUpdate(sec);
}


void actor::onDraw() {
	ofPoint p = pos;
	ofTranslate(p.x, p.y, p.z);
	ofPoint r = rot;
	ofRotate(r.x, 1.0f, 0.0f, 0.0f);
	ofRotate(r.y, 0.0f, 1.0f, 0.0f);
	ofRotate(r.z, 0.0f, 0.0f, 1.0f);
	ofPoint s = scale;
	ofScale(s.x, s.y, s.z);
	
	float al = (float)alpha_anime;
	int a = (int)(255.0f * (float)alpha_anime);
	ofSetColor(255, 255, 255, a);
	
	actorBase::onDraw();
}


void actor::setPosition(ofPoint pos){
	this->pos.set(pos);
	actorBase::setPosition(pos);
}


void actor::setRotation(ofPoint rot){
	this->rot.set(rot);
	actorBase::setRotation(rot);
}


void actor::setScale(ofPoint scale){
	this->scale.set(scale);
	actorBase::setScale(scale);
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
	this->pos.go(pos,duration,f);
}


void actor::move(animationCue c){
	if (c.isMove())
		this->pos.go(c.getMove(),c.getDuration(),c.getMoveFunc());
	if (c.isRotate())
		this->rot.go(c.getRotate(),c.getDuration(),c.getMoveFunc());
	if (c.isScale())
		this->scale.go(c.getScale(),c.getDuration(),c.getScaleFunc());
	if (c.isAlpha())
		this->alpha_anime.go(c.getAlpha(),c.getDuration(),c.getAlphaFunc());
}


void actor::setLoop(bool b){
	loop = b;
}


bool actor::isAnimationFinished() {
	return animationCues.empty() && pos.isFinished() && rot.isFinished() && scale.isFinished() && alpha_anime.isFinished();
}
