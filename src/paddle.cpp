#include "../include/paddle.h"

Paddle::Paddle() {
	this->center = vec2();
	this->size = vec2();
	this->color = vec4();
	this->moveDirection = vec2();
	this->moveSpeed = 0.0;
}

Paddle::Paddle(vec2 size, vec2 center, vec4 color, float moveSpeed) {
	this->center = center;
	this->size = size;
	this->color = color;

	this->moveDirection = vec2();
	this->moveSpeed = moveSpeed;
}

void Paddle::movePaddle(int x, int y) {
	center.x = x;
	//center.y = y;
}