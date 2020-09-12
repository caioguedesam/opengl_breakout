#include "../include/vec.h"

vec2::vec2() {
	this->x = 0.0;
	this->y = 0.0;
}

vec2::vec2(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
}

vec2 vec2::normalize() {
	float magnitude = sqrtf(pow(x, 2) + pow(y, 2));
	return vec2(x / magnitude, y / magnitude);
}

vec3::vec3() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

vec3::vec3(GLfloat x, GLfloat y, GLfloat z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

vec3 vec3::normalize() {
	float magnitude = sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return vec3(x / magnitude, y / magnitude, z / magnitude);
}

vec4::vec4() {
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
	this->w = 0.0;
}

vec4::vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

vec4 vec4::normalize() {
	float magnitude = sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
	return vec4(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}