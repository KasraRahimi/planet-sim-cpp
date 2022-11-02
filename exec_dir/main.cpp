#include <iostream>
#include <Game.h>
#include <Planet.h>
#include <Timer.h>

#define WIDTH 720
#define HEIGHT 480
#define FPS 60
#define TIME_PER_FRAME 1000/FPS

int main() {
    Color red = { 255, 0, 0, 255 };
    Game game(SDL_INIT_EVERYTHING, "My Game", WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
    Timer timer;
    int x = 0, y = 0;
    while (game.getIsRunning()) {
        timer.reset();
        game.clearRender();
        game.handleEvents();
        game.drawRect(red, x, y, 100, 200);
        x++;
        y++;
        if (timer.elapsedTime() < TIME_PER_FRAME)
            SDL_Delay(TIME_PER_FRAME - timer.elapsedTime());
    }
    return 0;
}