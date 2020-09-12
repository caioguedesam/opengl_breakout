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

bool Ball::collidesWithRect(float xmin, float ymin, float xmax, float ymax) {
	vec2 testEdge = vec2(position.x, position.y);
	if (position.x < xmin) testEdge.x = xmin;
	else if (position.x > xmax) testEdge.x = xmax;
	if (position.y < ymin) testEdge.y = ymin;
	else if (position.y > ymax) testEdge.y = ymax;

	vec2 distVector = vec2(position.x - testEdge.x, position.y - testEdge.y);
	float dist = sqrt(pow(distVector.x, 2) + pow(distVector.y, 2));

	return (dist <= radius);
}

bool Ball::collidesWithPaddle(Paddle paddle) {
	float xmin = paddle.position.x - paddle.size.x;
	float ymin = paddle.position.y - paddle.size.y;
	float xmax = paddle.position.x + paddle.size.x;
	float ymax = paddle.position.y + paddle.size.y;
	return collidesWithRect(xmin, ymin, xmax, ymax);
}

vec2 Ball::collisionDirectionWithRect(float xcenter, float ycenter) {
	return vec2(position.x - xcenter, position.y - ycenter).normalize();
}

vec2 Ball::collisionDirectionWithPaddle(Paddle paddle) {
	return collisionDirectionWithRect(paddle.position.x, paddle.position.y);
}

void Ball::checkPaddleCollision(Paddle paddle) {
	if (collidesWithPaddle(paddle)) {
		moveDirection = collisionDirectionWithPaddle(paddle);
	}
}