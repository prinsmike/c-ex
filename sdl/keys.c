#include "SDL2/SDL.h"

#define WIN_WIDTH 640
#define WIN_HEIGHT 480
#define BALL_WIDTH 10

typedef struct {
	int x, y, xv, yv;
} Ball;

int events() {

	int done = 0;
	SDL_Event event;

	// Event loop.
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				done = 1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					done = 1;
				}
				break;
		}
	}

	return done;
}

void draw(SDL_Renderer* renderer) {

	Ball ball;
	ball.x = WIN_WIDTH / 2 - BALL_WIDTH / 2;
	ball.y = WIN_HEIGHT / 2 - BALL_WIDTH / 2;
	ball.xv = 5;
	ball.yv = 5;

	int done = 0;

	// Animation loop.
	while (!done) {

		done = events();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set renderer color to black (background).
		SDL_RenderClear(renderer); // Clear the window.

		ball.x += ball.xv;
		ball.y += ball.yv;

		if (ball.x < 0 + BALL_WIDTH / 2 || ball.x > WIN_WIDTH - BALL_WIDTH / 2) {
			ball.xv = -ball.xv;
		}
		if (ball.y < 0 + BALL_WIDTH / 2 || ball.y > WIN_HEIGHT - BALL_WIDTH / 2) {
			ball.yv = -ball.yv;
		}

		SDL_Rect rect = {ball.x, ball.y, BALL_WIDTH, BALL_WIDTH};

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set the renderer color to green (rect).
		SDL_RenderFillRect(renderer, &rect); // Render the rect.
		SDL_RenderPresent(renderer); // Render to the screen.
	}
}

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {	// Initialize SDL2.
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_Window* win = SDL_CreateWindow(
			"SDL2 Animate",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			WIN_WIDTH, WIN_HEIGHT, 0);

	if (!win) { 		// Verify that the window was created successfully.
		SDL_Log("Could not create window: %s", SDL_GetError());
		return 1;
	}

	// Create a renderer.
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		SDL_Log("Could not create the renderer: %s", SDL_GetError());
		SDL_DestroyWindow(win);
		SDL_Quit();
		return 1;
	}

	// Draw the animation.
	draw(renderer);

	SDL_DestroyWindow(win);
	SDL_Quit(); // Clean up.
	return 0;
}
