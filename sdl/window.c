#include "SDL2/SDL.h"

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {	// Initialize SDL2.
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow(
			"SDL2 Window",						// Window title.
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, 0);

	if (!window) { 		// Verify that the window was created successfully.
		SDL_Log("Could not create window: %s", SDL_GetError());
		return 1;
	}

	// Create a renderer.
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer) {
		SDL_Log("Could not create the renderer: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set renderer color to black (background).
	SDL_RenderClear(renderer); // Clear the window.

	SDL_Rect rect;
	rect.x = 640 / 2 - 10;
	rect.y = 480 / 2 - 10;
	rect.w = 20;
	rect.h = 20;

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set the renderer color to green (rect).

	SDL_RenderFillRect(renderer, &rect); // Render the rect.

	SDL_RenderPresent(renderer); // Render to the screen.

	SDL_Delay(5000);

	SDL_DestroyWindow(window);
	SDL_Quit(); // Clean up.
	return 0;
}
