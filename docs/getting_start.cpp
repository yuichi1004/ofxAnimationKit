#include <stdlib.h>
#include "testApp.h"
#include "ofxAnimationKit.h"

#define STARS_SIZE 50
spriteActor stars[STARS_SIZE];

void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	// Loads images and declares the star's animation.
	for (int i=0; i<STARS_SIZE; i++){
		stars[i].load("image.png");		
		stars[i].setPosition(ofPoint(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0));
	
		int w = ofGetScreenWidth();
		int h = ofGetScreenHeight();
		int v = 200;
	
		stars[i].setLoop(true);
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
		stars[i].pushMove(1000,ofPoint(rand()%w,rand()%h,rand()%v));
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
