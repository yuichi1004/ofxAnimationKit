#ifndef _ANIME_VALUE_H__
#define _ANIME_VALUE_H__

/**
 Animation functions
 Some functions based on the robertpenner's easing function.
 See also http://www.robertpenner.com/easing/easing_demo.html
 */
class animationFunctions {
public:
	static inline float linear(float t){
		return t;
	}
	static inline float easeIn(float t){
		return t*t;
	}
	static inline float easeOut(float t){
		return 2.0f*t-t*t;
	}
	static inline float easeInOut(float t){
		return 3.0f*t*t-2.0f*t*t*t;
	}
	static inline float easeInCubic(float t){
		return t*t*t;
	}
	static inline float easeOutCubic(float t){
		return (-t*t*t+3.0f*t)/2.0f;
	}
	static inline float easeInOutCubic(float t){
		if (t<0.5f) {
			t*=2.0f;
			return t*t*t/2.0f;
		}
		t=(t-0.5f)*2.0f;
		return 0.5f+(-t*t*t+3.0f*t)/4.0f;
	}
	static inline float bounce(float t) {
		if (t<1.0f/2.75f) {
			return (7.5625f*t*t);
		} else if (t<2.0f/2.75f) {
			t-=1.5f/2.75f;
			return (7.5625f*t*t+.75f);
		} else if (t <2.5f/2.75f) {
			t-=2.25f/2.75f;
			return (7.5625f*t*t+.9375f);
		} else {
			t-=(2.625f/2.75f);
			return (7.5625f*t*t + .984375);
		}
		
		// if (x<1.0/2.75){7.5625*x*x} else{0}
	}
};


template<typename T>
class animationValue {
	T to;
	T from;
	int duration;
	int current;
	
	// function pointer for animation function
	float (*animeFunc)(float);
	
public:
	inline animationValue(){
		duration=current=0;
		animeFunc=animationFunctions::linear;
	}
	
	inline void update(int sec) {
		current+=sec;
		if(current>=duration){
			current=duration;
			from=to;
		}
	}
	
	inline T get() {
		return duration!=0 ? from+(to-from)*(float)animeFunc((float)current/(float)duration): from;
	}
	
	inline operator T() {
		return get();
	}
	
	inline void go(T _to, int _duration){
		from = get();
		to=_to;
		duration=_duration;
		current=0;
	}
	
	inline void go(T _to, int _duration, float (*f)(float)){
		from = get();
		to=_to;
		duration=_duration;
		animeFunc=f;
		current=0;
	}
	
	inline void set(T t){
		from=t;
		to=t;
		duration=0;
		current=0;
	}
	
	inline bool isFinished() {
		return duration==current;
	}
};


#endif