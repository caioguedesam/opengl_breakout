#pragma once
#include <GL/freeglut.h>
#include <math.h>

class vec2 {
public:
	GLfloat x;
	GLfloat y;
	vec2();
	vec2(GLfloat x, GLfloat y);

	vec2 operator+(const vec2& rhs);
	vec2 operator-(const vec2& rhs);
	vec2 operator-();
	vec2 operator*(const vec2& rhs);

	float magnitude();
	vec2 normalize();
};

class vec3 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	vec3();
	vec3(GLfloat x, GLfloat y, GLfloat z);

	vec3 operator+(const vec3& rhs);
	vec3 operator-(const vec3& rhs);
	vec3 operator-();
	vec3 operator*(const vec3& rhs);

	float magnitude();
	vec3 normalize();
};

class vec4 {
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat w;
	vec4();
	vec4(GLfloat x, GLfloat y, GLfloat z, GLfloat w);

	vec4 operator+(const vec4& rhs);
	vec4 operator-(const vec4& rhs);
	vec4 operator-();
	vec4 operator*(const vec4& rhs);

	float magnitude();
	vec4 normalize();
};