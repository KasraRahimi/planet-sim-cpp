#include <iostream>
#include <Game.h>
#include <Planet.h>
#include <Timer.h>

#define WIDTH 720
#define HEIGHT 480
#define FPS 60
#define TIME_PER_FRAME 1000/FPS
#define SCALE 1/10e8
#define TIMESTEP 3600 * 12
#define EARTH_MASS 5.972e24

const Color RED = { 255, 0, 0, 255 };
const Color GREEN = { 0, 255, 0, 255 };
const Color BLUE = { 0, 0, 255, 255 };
const Color GREY = { 128, 128, 128, 255 };
const Color YELLOW = { 255, 255, 0, 255 };
const Color ORANGE = { 255, 128, 0, 255 };

int main() {
    Game game(SDL_INIT_EVERYTHING, "My Game", WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
    Timer timer;

    std::vector<Planet*> solarSystem;
    Planet sun(1.989e30, 20, YELLOW, 0, 0, 0, 0, &solarSystem);
    Planet mercury(0.055 * EARTH_MASS, 5, GREY, 60e9, 0, 0, -47e3, &solarSystem);
    Planet venus(0.815 * EARTH_MASS, 8, ORANGE, 109e9, 0, 0, -35e3, &solarSystem);
    Planet earth(EARTH_MASS, 10, BLUE, 150e9, 0, 0, -30e3, &solarSystem);
    Planet mars(0.107 * EARTH_MASS, 7, RED, 225e9, 0, 0, -24e3, &solarSystem);

    while (game.getIsRunning()) {
        timer.reset();
        game.clearRender();
        game.handleEvents();
        for (std::vector<Planet*>::iterator planet = solarSystem.begin(); planet < solarSystem.end(); planet++)
        {
            Vec position = (*planet)->positionOnScreen(WIDTH, HEIGHT, SCALE);
            int radius = (*planet)->getRadius();
            game.drawCircle((*planet)->getColor(), radius, position.x, position.y);
            (*planet)->move(TIMESTEP);
        }
        game.presentRender();
        if (timer.elapsedTime() < TIME_PER_FRAME)
            SDL_Delay(TIME_PER_FRAME - timer.elapsedTime());
    }
    return 0;
}