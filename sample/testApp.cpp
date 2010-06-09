#include <stdlib.h>

#include "testApp.h"
#include "actor.h"
#include "spriteActor.h"

#define A_SIZE 50

spriteActor a[A_SIZE];

void testApp::setup(){
	ofBackground(0, 0, 0);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	for (int i=0; i<A_SIZE; i++){
		a[i].load("image.png");		
		a[i].setPosition(ofPoint(ofGetScreenWidth()/2,ofGetScreenHeight()/2,0));
		
		a[i].setLoop(true);
		
		animationCue c(1000);
		c.setMove(ofPoint(rand()%ofGetScreenWidth(),rand()%ofGetScreenHeight(),rand()%200));
		c.setRotate(ofPoint(360*2,0,0));
		c.setAlpha(1.0f);
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%ofGetScreenWidth(),rand()%ofGetScreenHeight(),rand()%200));
		c.setRotate(ofPoint(0,0,0));
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%ofGetScreenWidth(),rand()%ofGetScreenHeight(),rand()%200));
		c.setRotate(ofPoint(0,360*2,0));
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%ofGetScreenWidth(),rand()%ofGetScreenHeight(),rand()%200));
		c.setRotate(ofPoint(0,0,0));
		c.setAlpha(0.0f);
		a[i].pushMove(c);
	}
}


void testApp::update(){
	for (int i=0; i<A_SIZE; i++)
		a[i].update(1000/60);
}


void testApp::draw(){
	ofSetupScreen();
	ofEnableAlphaBlending();
	
	for (int i=0; i<A_SIZE; i++)
		a[i].draw();
}


void testApp::keyPressed(int key){
}


void testApp::keyReleased(int key){
}


void testApp::mouseMoved(int x, int y ){
}


void testApp::mouseDragged(int x, int y, int button){
}


void testApp::mousePressed(int x, int y, int button){
}


void testApp::mouseReleased(int x, int y, int button){
}


void testApp::windowResized(int w, int h){
}

