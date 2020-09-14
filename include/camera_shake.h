#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <random>
#include <cstdlib>
#include "../include/vec.h"

class CameraShake {
public:
	vec2 lastOffset;
	vec2 currentOffset;
	float shakeAmount;
	float duration;
	float maxOffset;

	CameraShake();
	CameraShake(float maxOffset);

	void start(float amount, float duration);
	void applyShake(float deltaTime);
};

vec2 getRandomShakeValues();