#include "actor.h"
#include "animationCue.h"
#include "ofMain.h"


actor::actor() {
	setScale(ofPoint(1,1,1));
	alpha_anime.set(1.0f);
}


actor::actor(ofPoint pos) {
	setPosition(pos);
	setScale(ofPoint(1,1,1));
	alpha_anime.set(1.0f);
}


void actor::onUpdate(int msec) {
	pos.update(msec);
	rot.update(msec);
	scale.update(msec);
	alpha_anime.update(msec);
	
	if (pos.isFinished()&&rot.isFinished()&&!animationCues.empty()){
		animationCue c=animationCues.front();
		move(c);
		if (loop)
			animationCues.push(c);
		animationCues.pop();
	}
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
	ofTranslate(basePoint.x, basePoint.y, basePoint.z);
	
	float al = (float)alpha_anime;
	int a = (int)(255.0f * (float)alpha_anime);
	ofSetColor(255, 255, 255, a);
}


void actor::update(int msec) {
	this->onUpdate(msec);
}



void actor::draw() {
	//ofPushStyle();
	glPushMatrix();
	this->onDraw();
	glPopMatrix();
	//ofPopStyle();
}


void actor::setPosition(ofPoint pos){
	this->pos.set(pos);
}


void actor::setRotation(ofPoint rot){
	this->rot.set(rot);
}


void actor::setScale(ofPoint scale){
	this->scale.set(scale);
}


void actor::setAlpha(float alpha){
	this->alpha_anime.set(alpha);
}


void actor::setBasePoint(ofPoint basePoint) {
	this->basePoint = basePoint;
}


ofPoint actor::getPosition(){
	return this->pos;
}


ofPoint actor::getRotation(){
	return this->rot;
}


ofPoint actor::getScale(){
	return this->scale;
}


float actor::getAlpha() {
	return this->alpha_anime;
}


ofPoint actor::getSize() {
	return ofPoint(0,0,0);
}


ofPoint actor::getBasePoint() {
	return this->basePoint;
}


void actor::pushMove(int duration, ofPoint pos, float (*f)(float)){
	animationCue c;
	c.setMove(pos, f);
	c.setDuration(duration);
	animationCues.push(c);
}


void actor::pushMove(animationCue c){
	animationCues.push(c);
}


void actor::move(int duration, ofPoint pos, float (*f)(float)){
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
