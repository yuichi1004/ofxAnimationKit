#ifndef __ANIMATION_CUE__
#define __ANIMATION_CUE__

#include "ofMain.h"

class animationCue {
	int duration;
	ofPoint move, rotate, scale;
	float alpha;
	float (*move_func)(float);
	float (*rotate_func)(float);
	float (*scale_func)(float);
	float (*alpha_func)(float);
	bool is_move, is_rotate, is_scale, is_alpha;
	
public:
	inline animationCue(){
		is_move = false;
		is_rotate = false;
		is_scale = false;
		is_alpha = false;
	}
	
	inline animationCue(int duration){
		is_move = false;
		is_rotate = false;
		is_scale = false;
		is_alpha = false;
		this->duration = duration;
	}
	
	inline void setMove(ofPoint move, float (*move_func)(float)=animationFunctions::easeOut) {
		this->move = move;
		this->move_func = move_func;
		this->is_move = true;
	}
	
	inline void setRotate(ofPoint rotate, float (*rotate_func)(float)=animationFunctions::easeOut) {
		this->rotate = rotate;
		this->rotate_func = rotate_func;
		this->is_rotate = true;
	}

	inline void setScale(ofPoint scale, float (*scale_func)(float)=animationFunctions::easeOut) {
		this->scale = scale;
		this->scale_func = scale_func;
		this->is_scale = true;
	}
	
	inline void setAlpha(float alpha, float (*alpha_func)(float)=animationFunctions::easeOut) {
		this->alpha = alpha;
		this->alpha_func = alpha_func;
		this->is_alpha = true;
	}
	
	inline ofPoint getMove(){
		return move;
	}
	
	inline ofPoint getRotate(){
		return rotate;
	}
	
	inline ofPoint getScale(){
		return scale;
	}
	
	inline float getAlpha() {
		return alpha;
	}
	
	inline void setDuration(int duration){
		this->duration = duration;
	}
	
	inline int getDuration(){
		return duration;
	}
	
	inline float (*getMoveFunc())(float) {
		return move_func;
	}

	inline float (*getRotateFunc())(float) {
		return rotate_func;
	}	
	
	inline float (*getScaleFunc())(float) {
		return scale_func;
	}

	inline float (*getAlphaFunc())(float) {
		return alpha_func;
	}	
	
	inline bool isMove(){
		return is_move;
	}
	
	inline bool isRotate(){
		return is_rotate;
	}
	
	inline bool isScale(){
		return is_scale;
	}
	
	inline bool isAlpha(){
		return is_alpha;
	}	
};

#endif