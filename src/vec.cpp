#include "../include/vec.h"

vec2::vec2() {
	this->x = 0.0;
	this->y = 0.0;
}

vec2::vec2(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
}

float vec2::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2));
}

vec2 vec2::normalize() {
	float magnitude = this->magnitude();
	return vec2(x / magnitude, y / magnitude);
}

vec2 vec2::operator+(const vec2& rhs) {
	vec2 result = vec2(this->x + rhs.x, this->y + rhs.y);
	return result;
}

vec2 vec2::operator-(const vec2& rhs) {
	vec2 result = vec2(this->x - rhs.x, this->y - rhs.y);
	return result;
}

vec2 vec2::operator-() {
	return vec2(-this->x, -this->y);
}

vec2 vec2::operator*(const vec2& rhs) {
	vec2 result = vec2(this->x * rhs.x, this->y * rhs.y);
	return result;
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

float vec3::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

vec3 vec3::normalize() {
	float magnitude = this->magnitude();
	return vec3(x / magnitude, y / magnitude, z / magnitude);
}

vec3 vec3::operator+(const vec3& rhs) {
	vec3 result = vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
	return result;
}

vec3 vec3::operator-(const vec3& rhs) {
	vec3 result = vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
	return result;
}

vec3 vec3::operator-() {
	return vec3(-this->x, -this->y, -this->z);
}

vec3 vec3::operator*(const vec3& rhs) {
	vec3 result = vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
	return result;
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

float vec4::magnitude() {
	return sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2));
}

vec4 vec4::normalize() {
	float magnitude = this->magnitude();
	return vec4(x / magnitude, y / magnitude, z / magnitude, w / magnitude);
}

vec4 vec4::operator+(const vec4& rhs) {
	vec4 result = vec4(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z, this->w + rhs.w);
	return result;
}

vec4 vec4::operator-(const vec4& rhs) {
	vec4 result = vec4(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z, this->w - rhs.w);
	return result;
}

vec4 vec4::operator-() {
	return vec4(-this->x, -this->y, -this->z, -this->w);
}

vec4 vec4::operator*(const vec4& rhs) {
	vec4 result = vec4(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z, this->w * rhs.w);
	return result;
}