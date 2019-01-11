#pragma once
#include "math.h"
#include <string>
#include <stdint.h>


//returns smaller of the two
template<typename T>
T min(T a, T b)
{
	return a < b ? a : b;
}

//returns smaller of the two
template<typename T, typename... Args>
T min(T a, T b, Args... args) {
	return (a < b ? min (a,args...) : min(b,args...));
}

//returns larger of the two
template<typename T>
T max(T a, T b)
{
	return a > b ? a : b;
}

//returns larger of the two
template<typename T, typename... Args>
T max(T a, T b, Args... args) {
	return (a > b ? max(a, args...) : max(b, args...));
}

//returns value no smaller than min and no larger than max
template<typename T>
T clamp(T value, T min, T max) {
	value < min ? value = min : value;
	value > max ? value = max : value;
	return value;
}

//Defined as PI 
constexpr double PI2 = 3.141592653589793238;
//Multiply this with a angle measure expressed in degrees to get its equivalent in radians.
constexpr double DEG_TO_RAD2 = PI2/180;
//Multiply this with a angle measure expressed in radians to get its equivalent in degrees.
constexpr double RAD_TO_DEG2 = 180/PI2;

//returns the absolute value of val
template<typename T>
T abs(T val) {
	return val < 0 ? val * -1 : val;
}

//return base to the power of exp base^power
template<typename T>
T pow(T base, int power) {
	T temp = base;
	for (int i = 1; i < power; i++) {
		base *= temp;
	}
	return base;
}

//returns true if teh value is a power of two, otherwise returns false
bool isPowerOfTwo(int val);

//returns the next power of two after the given value
//the behavior of this function if teh next power of two is beyond the range of int is not defined
int nextPowerOfTwo(int val);

//moves the current value towards the target value. The maximum change should not exceed maxDelta
//the value returned should never move past the target value
template<typename T>
T moveTowards(T current, T target, T maxDelta) {
	if (current > target) {
		current -= maxDelta;
		current = clamp(current, target, current);
		return current;
	}
	else if (current < target) {
		current += maxDelta;
		current = clamp(current, current, target);
		return current;
	}
	else {
		return current;
	}
}

// seed the random number generator
void seedRand(int seedValue);

// returns the seed used for the random number generator
uint32_t getRandSeed(uint64_t _seed = 1);

// returns a random value between min and max
template<typename T>
T rand(T min, T max) {
	uint32_t seed = getRandSeed();
	return seed % (max - min + 1) + min;
}

// returns a random value between min and max
//  - the value may contain decimal components
template<typename T>
T randDecimal(T min, T max) {
	return T();
}

