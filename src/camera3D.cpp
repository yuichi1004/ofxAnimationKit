#include "ofMain.h"
#include "camera3D.h"

camera3D::camera3D(ofPoint _pos): actor(_pos){
}


void camera3D::begin(){
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	ofPoint position = getPosition();
	gluLookAt(position.x,position.y,position.z,
			 0,0,0,
			 0,1,0);
}


void camera3D::end(){
	glPopMatrix();
}
