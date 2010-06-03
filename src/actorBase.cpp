#include "actorBase.h"

// Constructor
actorBase::actorBase() {
}


actorBase::actorBase(ofPoint _pos) {
	position = _pos;
}


actorBase::~actorBase() {
}


void actorBase::update(int sec) {
}


void actorBase::draw() {
}


void actorBase::setPosition(ofPoint _pos){
	position = _pos;
}


void actorBase::setRotation(ofPoint _rot){
	rotation = _rot;
}


ofPoint actorBase::getPosition() {
	return position;
}


ofPoint actorBase::getRotation() {
	return rotation;
}


void actorBase::requestUpdate(int sec) {
	this->update(sec);
}

void actorBase::requestDraw() {
	//ofPushStyle();
	glPushMatrix();
	this->draw();
	glPopMatrix();
	//ofPopStyle();
}

