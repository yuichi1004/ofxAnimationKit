#include "spriteActor.h"


spriteActor::spriteActor(ofPoint _pos){
	image = NULL;
	setPosition(_pos);

	is_image_owner = true;	
}


spriteActor::spriteActor(string file, ofPoint _pos): actor(_pos){
	load(file);
	setPosition(_pos);

	is_image_owner = true;	
}


spriteActor::~spriteActor(){
	if ( is_image_owner && !image )
		delete image;
}


void spriteActor::load(string file) {
	if ( is_image_owner && !image )
		delete image;

	image = new ofImage();
	image->loadImage(file);
	image->setImageType(OF_IMAGE_COLOR_ALPHA);
}


void spriteActor::setImage(ofImage* img, bool isOwner) {
	if ( is_image_owner && !image )
		delete image;

	image = img;
	is_image_owner = isOwner;
}


ofImage* spriteActor::getImage() {
	return image;
}


void spriteActor::onUpdate(int msec){
	actor::onUpdate(msec);
}


void spriteActor::onDraw(){
	actor::onDraw();
	if ( image!=NULL ){
		glPushMatrix();
		glTranslatef(-image->getWidth()/2.0f,-image->getHeight()/2.0f,0.0f);
		image->draw(0,0);
		glPopMatrix();
	}
}


ofPoint spriteActor::getSize() {
	return ofPoint(image->getWidth(), image->getHeight(), 0);
}


int spriteActor::getSpriteWidth() {
	return image->getWidth();
}


int spriteActor::getSpriteHeight() {
	return image->getHeight();
}