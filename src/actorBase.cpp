#include "actorBase.h"


actorBase::actorBase() {
}


actorBase::actorBase(ofPoint _pos) {
	position = _pos;
}


actorBase::~actorBase() {
}


void actorBase::onUpdate(int msec) {
}


void actorBase::onDraw() {
}


void actorBase::setPosition(ofPoint pos){
	this->position = pos;
}


void actorBase::setRotation(ofPoint rot){
	this->rotation = rot;
}


void actorBase::setScale(ofPoint scale){
	this->scale = scale;
}


void actorBase::setBasePoint(ofPoint basePoint){
	this->basePoint = basePoint;
}


void actorBase::setAlpha(float alpha) {
	this->alpha = alpha;
}


ofPoint actorBase::getPosition() {
	return position;
}


ofPoint actorBase::getRotation() {
	return rotation;
}


ofPoint actorBase::getScale() {
	return scale;
}


ofPoint actorBase::getBasePoint() {
	return basePoint;
}


ofPoint actorBase::getSize() {
	return ofPoint(0,0,0);
}


float actorBase::getAlpha() {
	return alpha;
}

void actorBase::update(int msec) {
	this->onUpdate(msec);
}


void actorBase::draw() {
	//ofPushStyle();
	glPushMatrix();
	this->onDraw();
	glPopMatrix();
	//ofPopStyle();
}


bool actorBase::isAnimationFinished() {
	return true;
}