#include <iostream>
#include <SDL2/SDL.h>
#include <Planet.h>

#define WIDTH 720
#define HEIGHT 480

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    bool isRunning = true;
    while (isRunning) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    exit(0);
                    break;
                default:
                    break;
            }
        }
        SDL_RenderPresent(renderer);
    }
    return 0;
}