#include "spriteActor.h"


spriteActor::spriteActor(ofPoint _pos){
	image = NULL;
	setPosition(_pos);
}


spriteActor::spriteActor(string file, ofPoint _pos): actor(_pos){
	loadImage(file);
	setPosition(_pos);
}


spriteActor::~spriteActor(){
	if ( is_image_owner && !image )
		delete image;
}


void spriteActor::loadImage(string file) {
	image = new ofImage();
	image->loadImage(file);
	image->setImageType(OF_IMAGE_COLOR_ALPHA);
	is_image_owner = true;	
}


void spriteActor::onUpdate(int sec){
	actor::onUpdate(sec);
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