#include "../include/ball.h"

Ball::Ball() {
	this->active = true;

	this->position = vec2(0.0, 0.0);
	this->radius = 1.0;
	this->color = vec4(0.0, 0.0, 0.0, 0.0);

	this->moveDirection = vec2(0.0, -1.0);
	this->maxSpeed = 60.0;
	this->minSpeed = 30.0;
	this->moveSpeed = minSpeed;
	this->maxAngle = 75.0;
}

Ball::Ball(float radius, vec2 position, vec4 color, vec2 moveDirection, float maxSpeed, float minSpeed) {
	this->active = true;

	this->position = position;
	this->radius = radius;
	this->color = color;

	this->moveDirection = moveDirection;
	this->maxSpeed = maxSpeed;
	this->minSpeed = minSpeed;
	this->moveSpeed = minSpeed;
	this->maxAngle = 75.0;
}

void Ball::moveBall() {
	if (active) {
		vec2 normalizedDir = moveDirection.normalize();
		position.x += normalizedDir.x * moveSpeed * deltaTime;
		position.y += normalizedDir.y * moveSpeed * deltaTime;
	}
}

void Ball::destroyBall() {
	active = false;
}

void Ball::clampBallToScreenBounds(float width, float height) {
	if (position.x < (-width) / 2.0 || position.x > width / 2.0)
		moveDirection.x = -moveDirection.x;
	if (position.y < (-height) / 2.0 || position.y > height / 2.0)
		moveDirection.y = -moveDirection.y;
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

bool Ball::collidesWithBrick(Brick brick) {
	float xmin = brick.position.x - brick.size.x;
	float ymin = brick.position.y - brick.size.y;
	float xmax = brick.position.x + brick.size.x;
	float ymax = brick.position.y + brick.size.y;
	return collidesWithRect(xmin, ymin, xmax, ymax);
}

bool Ball::isBelowPaddle(Paddle paddle) {
	return (position.y < paddle.position.y);
}

vec2 Ball::collisionDirectionWithRect(float xcenter, float ycenter) {
	return vec2(position.x - xcenter, position.y - ycenter).normalize();
}

vec2 Ball::collisionDirectionWithPaddle(Paddle paddle) {
	return collisionDirectionWithRect(paddle.position.x, paddle.position.y);
}

vec2 Ball::collisionDirectionWithBrick(Brick brick) {
	return collisionDirectionWithRect(brick.position.x, brick.position.y);
}

float Ball::collisionAngle(vec2 collisionDirection) {
	vec2 up = vec2(0.0, 1.0);
	vec2 dir = collisionDirection;
	
	vec2 product = up * dir;
	float scalarProduct = product.x + product.y;
	float cosine = scalarProduct / (up.magnitude() * dir.magnitude());
	return acos(cosine) * (180 / PI);
}

void Ball::checkPaddleCollision(Paddle paddle) {
	if (isBelowPaddle(paddle)) {
		destroyBall();
	}

	if (collidesWithPaddle(paddle)) {
		// REVISE THIS LATER: how does changing direction when hitting paddle works.
		vec2 collisionDir = collisionDirectionWithPaddle(paddle);
		moveDirection = vec2(-collisionDir.x, collisionDir.y);

		// Change speed based on angle hit
		float angle = collisionAngle(moveDirection);
		if (abs(angle) <= maxAngle) {
			moveSpeed = minSpeed + (maxSpeed - minSpeed) * (abs(angle) / maxAngle);
			moveSpeed = clampMax(moveSpeed, maxSpeed);
		}
	}
}

void Ball::checkBrickCollision(Level level) {
	for (unsigned int i = 0; i < level.bricks.size(); i++) {
		if (level.bricks[i]->active && collidesWithBrick(*level.bricks[i])) {
			moveDirection = collisionDirectionWithBrick(*level.bricks[i]);
			level.bricks[i]->hitBrick();
		}
	}
}

void Ball::draw(void) {
	if (active) {
		// Setting the ball color
		glColor3f(color.x, color.y, color.z);
		// Calculating vertex positions and drawing paddle
		glBegin(GL_POLYGON);
		// Using 50 segments, maybe change this later as ball attribute
		for (int i = 0; i < 50.0; i++) {
			// Calculates angle as (i/segments) percent of 2pi rad (360º)
			float theta = 2.0f * PI * (float)i / 50.0f;
			float x = radius * cos(theta);
			float y = radius * sin(theta);
			glVertex2f(position.x + x, position.y + y);
		}
		glEnd();
	}
}