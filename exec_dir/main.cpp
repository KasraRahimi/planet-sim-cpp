#include <iostream>
#include <Game.h>
#include <Planet.h>
#include <Timer.h>

#define WIDTH 720
#define HEIGHT 480
#define FPS 60
#define TIME_PER_FRAME 1000/FPS
#define SCALE 5/10e6
#define TIMESTEP 3600
#define EARTH_MASS 5.972e24

const Color RED = { 255, 0, 0, 255 };
const Color GREEN = { 0, 255, 0, 255 };
const Color BLUE = { 0, 0, 255, 255 };
const Color GREY = { 128, 128, 128, 255 };

int main() {
    Game game(SDL_INIT_EVERYTHING, "My Game", WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
    Timer timer;

    std::vector<Planet*> solarSystem;
    Planet earth(EARTH_MASS, 10, BLUE, 0, 0, 0, 0, &solarSystem);
    Planet moon(0.012 * EARTH_MASS, 5, GREY, 384400000, 0, 0, -1022, &solarSystem);

    while (game.getIsRunning()) {
        timer.reset();
        game.clearRender();
        game.handleEvents();
        for (std::vector<Planet*>::iterator planet = solarSystem.begin(); planet < solarSystem.end(); planet++)
        {
            Vec position = (*planet)->positionOnScreen(WIDTH, HEIGHT, SCALE);
            game.drawCircle((*planet)->getColor(), (*planet)->getRadius(), position.x, position.y);
            (*planet)->move(TIMESTEP);
        }
        if (timer.elapsedTime() < TIME_PER_FRAME)
            SDL_Delay(TIME_PER_FRAME - timer.elapsedTime());
    }
    return 0;
}