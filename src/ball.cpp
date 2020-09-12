#include "../include/ball.h"

Ball::Ball() {
	this->position = vec2(0.0, 0.0);
	this->radius = 1.0;
	this->color = vec4(0.0, 0.0, 0.0, 0.0);

	this->moveDirection = vec2(0.0, -1.0);
	this->moveSpeed = 10.0;
}

Ball::Ball(float radius, vec2 position, vec4 color, vec2 moveDirection, float moveSpeed) {
	this->position = position;
	this->radius = radius;
	this->color = color;

	this->moveDirection = moveDirection;
	this->moveSpeed = moveSpeed;
}

void Ball::moveBall() {
	vec2 normalizedDir = moveDirection.normalize();
	position.x += normalizedDir.x * moveSpeed * deltaTime;
	position.y += normalizedDir.y * moveSpeed * deltaTime;
}