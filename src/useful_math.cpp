#include "../include/useful_math.h"

float min(const float &a, const float &b) {
	return (a < b) ? a : b;
}

float max(const float &a, const float &b) {
	return (a > b) ? a : b;
}

float clampMin(const float &value, const float &min) {
	float result = value;
	return max(result, min);
}

float clampMax(const float &value, const float& max) {
	return min(value, max);
}

float clamp(const float& value, const float& min, const float& max) {
	float result = value;
	result = clampMin(result, min);
	result = clampMax(result, max);
	return result;
}