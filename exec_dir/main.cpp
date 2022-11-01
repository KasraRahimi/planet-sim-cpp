#include <iostream>
#include <Game.h>
#include <Planet.h>

#define WIDTH 720
#define HEIGHT 480

int main() {
    Game game(SDL_INIT_EVERYTHING, "My Game", WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
    while (game.getIsRunning()) {
        game.handleEvents();
    }
    return 0;
}