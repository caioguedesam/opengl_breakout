#pragma once
#include <GL/freeglut.h>
#include "../include/vec.h"

void renderStrokeString(float x, float y, void* font, vec4 color, const char* string, float scale = 1);
void renderBitmapString(float x, float y, void* font, vec4 color, const char* string);