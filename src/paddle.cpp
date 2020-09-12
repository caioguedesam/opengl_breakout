#include "../include/paddle.h"

Paddle::Paddle() {
	this->position = vec2();
	this->size = vec2();
	this->color = vec4();
	this->moveDirection = vec2();
	this->moveSpeed = 0.0;
}

Paddle::Paddle(vec2 size, vec2 position, vec4 color, float moveSpeed) {
	this->position = position;
	this->size = size;
	this->color = color;

	this->moveDirection = vec2();
	this->moveSpeed = moveSpeed;
}

void Paddle::movePaddle(int x, int y) {
	position.x = x;
	//center.y = y;
}