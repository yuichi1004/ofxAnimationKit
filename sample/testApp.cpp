#include <stdlib.h>
#include "testApp.h"
#include "ofxAnimationKit.h"

#define STARS_SIZE 50
spriteActor stars[STARS_SIZE];

void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	// Loads images and declear the star's animation.
	for (int i=0; i<STARS_SIZE; i++){
		stars[i].load("image.png");		
		stars[i].setPosition(ofPoint(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0));
		
		stars[i].setLoop(true);
		
		int w = ofGetScreenWidth();
		int h = ofGetScreenHeight();
		int v = 200;

		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		
		/* Complicated animation Version
		animationCue c(1000);
		c.setMove(ofPoint(rand()%w,rand()%h,rand()%v));
		c.setRotate(ofPoint(360*2,0,0));
		c.setAlpha(1.0f);
		stars[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w,rand()%h,rand()%v));
		c.setRotate(ofPoint(0,0,0));
		stars[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w,rand()%h,rand()%v));
		c.setRotate(ofPoint(0,360*2,0));
		stars[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w,rand()%h,rand()%v));
		c.setRotate(ofPoint(0,0,0));
		c.setAlpha(0.0f);
		stars[i].pushMove(c);
		 */
	}
}


void testApp::update(){
	for (int i=0; i<STARS_SIZE; i++)
		stars[i].update(1000/60);
}


void testApp::draw(){
	ofSetupScreen();
	ofEnableAlphaBlending();
	
	for (int i=0; i<STARS_SIZE; i++)
		stars[i].draw();
}
