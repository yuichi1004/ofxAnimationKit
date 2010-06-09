spriteActor a;
animationCue c(1000);
c.setMove(ofPoint(rand()%ofGetScreenWidth(),rand()%ofGetScreenHeight(),rand()%200));
c.setRotate(ofPoint(360*2,0,0));
c.setAlpha(1.0f);
a.move(c);

