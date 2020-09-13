#include "../include/text_render.h"

void renderStrokeString(float x, float y, void* font, vec4 color, const char* string, float scale) {
	glPushMatrix();
	glLoadIdentity();
	
	glTranslatef(x, y, 0.0);
	glScalef(scale, scale, 1.0);
	glColor3f(color.x, color.y, color.z);
	
	glutStrokeString(font, (const unsigned char*)string);

	glPopMatrix();
}

void renderBitmapString(float x, float y, void* font, vec4 color, const char* string) {
	glPushMatrix();
	glLoadIdentity();

	glColor4f(color.x, color.y, color.z, color.w);
	glRasterPos2f(x, y);

	glutBitmapString(font, (const unsigned char*)string);

	glPopMatrix();
}