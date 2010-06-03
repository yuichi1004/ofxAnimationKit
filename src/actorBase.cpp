#include "actorBase.h"


actorBase::actorBase() {
}


actorBase::actorBase(ofPoint _pos) {
	position = _pos;
}


actorBase::~actorBase() {
}


void actorBase::onUpdate(int sec) {
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


ofPoint actorBase::getPosition() {
	return position;
}


ofPoint actorBase::getRotation() {
	return rotation;
}


ofPoint actorBase::getScale() {
	return scale;
}


void actorBase::update(int sec) {
	this->onUpdate(sec);
}

void actorBase::draw() {
	//ofPushStyle();
	glPushMatrix();
	this->onDraw();
	glPopMatrix();
	//ofPopStyle();
}

