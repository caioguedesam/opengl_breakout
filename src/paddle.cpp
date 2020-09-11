#include "../include/paddle.h"

Paddle::Paddle() {
	this->center = vec2();
	this->size = vec2();
	this->color = vec4();
	this->moveDirection = vec2();
	this->moveSpeed = 0.0;
}