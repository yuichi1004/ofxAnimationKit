#include <stdlib.h>

#include "testApp.h"
#include "actor.h"
#include "spriteActor.h"
#include "camera3D.h"

#define A_SIZE 50

spriteActor a[A_SIZE];
camera3D camera;


void testApp::setup(){
	ofBackground(0, 0, 0);
	
	//lets make our circles look a little nicer!
	ofSetCircleResolution(40);
	
	//for smooth animation, set vertical sync if we can
	ofSetVerticalSync(true);
	
	// also, frame rate:
	ofSetFrameRate(60);
	
	for (int i=0; i<A_SIZE; i++){
		a[i].loadImage("image.png");		
		a[i].setPosition(ofPoint(0,0,0));
		
		int w=1024;
		int wb=w/2;
		int h=768;
		int hb=h/2;
		a[i].setLoop(true);
		
		animationCue c(1000);
		c.setMove(ofPoint(rand()%w-wb,rand()%h-hb,rand()%200));
		c.setRotate(ofPoint(360*2,0,0));
		c.setAlpha(1.0f);
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w-wb,rand()%h-hb,rand()%200));
		c.setRotate(ofPoint(0,0,0));
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w-wb,rand()%h-hb,rand()%200));
		c.setRotate(ofPoint(0,360*2,0));
		a[i].pushMove(c);
		
		c.setMove(ofPoint(rand()%w-wb,rand()%h-hb,rand()%200));
		c.setRotate(ofPoint(0,0,0));
		c.setAlpha(0.0f);
		a[i].pushMove(c);
	}
}


void testApp::update(){
	spin	+= 5.0;

	for (int i=0; i<A_SIZE; i++)
		a[i].update(1000/60);
}


void testApp::draw(){
	ofSetupScreen();
	ofEnableAlphaBlending();
	
	camera.begin();
	
	for (int i=0; i<A_SIZE; i++)
		a[i].draw();

	camera.end();
}


void testApp::keyPressed(int key){
	int a;
	a=2;
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

