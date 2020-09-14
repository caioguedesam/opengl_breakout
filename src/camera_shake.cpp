#include "../include/camera_shake.h"

CameraShake::CameraShake() {
	this->lastOffset = vec2(0.0, 0.0);
	this->currentOffset = vec2(0.0, 0.0);

	this->shakeAmount = 1.0;
	this->duration = 0.0;
	this->maxOffset = 0.0;
}

CameraShake::CameraShake(float maxOffset) {
	this->lastOffset = vec2(0.0, 0.0);
	this->currentOffset = vec2(0.0, 0.0);

	this->shakeAmount = 0.0;
	this->duration = 0.0;
	this->maxOffset = maxOffset;
}

void CameraShake::start(float amount, float duration) {
	shakeAmount = amount;
	this->duration = duration;
}

void CameraShake::applyShake(float deltaTime) {
	if (duration > 0.0) {
		vec2 randomPoint = getRandomShakeValues();
		float offsetX = maxOffset * shakeAmount * randomPoint.x;
		float offsetY = maxOffset * shakeAmount * randomPoint.y;
		currentOffset = vec2(offsetX, offsetY);
		vec2 diff = currentOffset - lastOffset;

		gluLookAt(diff.x, diff.y, 0.0, diff.x, diff.y, -1.0, 0.0, 1.0, 0.0);
		
		lastOffset = currentOffset;
		duration -= deltaTime;
	}
}

vec2 getRandomShakeValues() {
	std::random_device rd;
	std::mt19937 gen(rd());
	float valueX = std::generate_canonical<float, 10>(gen) * 2 - 1;
	float valueY = std::generate_canonical<float, 10>(gen) * 2 - 1;
	return vec2(valueX, valueY);
}