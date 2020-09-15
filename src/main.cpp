#include "../include/game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Game breakout;

void display(void) {
	breakout.display();
}

void reshape(int w, int h) {
	breakout.reshape(w, h);
}

void mouseMove(int x, int y) {
	breakout.mouseMove(x, y);
}

void mouseInput(int button, int buttonState, int x, int y) {
	breakout.mouseInput(button, buttonState, x, y);
}

void keyboardInput(unsigned char key, int x, int y) {
	breakout.keyboardInput(key, x, y);
}

void idle(void) {
	breakout.idle();
}

Mix_Music *music = NULL;

int main(int argc, char** argv) {
	if(SDL_Init(SDL_INIT_AUDIO) < 0) {
		std::cout << "1";
		return -1;
	}
	if(Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		std::cout << "2";
		return -1;
	}
	music = Mix_LoadMUS("sounds/mitsuo.ogg");
	if(music == NULL) {
		std::cout << "3";
		return -1;
	}
	if(Mix_PlayMusic(music, -1) == -1) {
		std::cout << "4";
		return -1;
	}

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(breakout.displayWidth, breakout.displayHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - breakout.displayWidth)/2, (glutGet(GLUT_SCREEN_HEIGHT) - breakout.displayHeight)/2);
	glutCreateWindow(breakout.gameTitle);
	glutSetCursor(GLUT_CURSOR_NONE);

	breakout.init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(mouseMove);
	glutMouseFunc(mouseInput);
	glutKeyboardFunc(keyboardInput);
	glutIdleFunc(idle);

	glutMainLoop();

	return 0;
}