#ifndef _ANIME_VALUE_H__
#define _ANIME_VALUE_H__

class animationFunctions {
public:
	static inline float linear(float t){
		return t;
	}
	static inline float easeIn(float t){
		return t*t;
	}
	static inline float easeOut(float t){
		return 2*t-t*t;
	}
	static inline float easeInQuad(float t){
		return t*t*t*t;
	}
	static inline float easeOutQuad(float t){
		return (t-t*t*t*t/4.0f)*4.0/3.0f;
	}
	static inline float easeInOut(float t){
		return 3*t*t-2*t*t*t;
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