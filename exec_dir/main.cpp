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

int main() {
    Color red = { 255, 0, 0, 255 };
    Color blue = { 0, 0, 255, 255 };
    Game game(SDL_INIT_EVERYTHING, "My Game", WIDTH, HEIGHT, SDL_RENDERER_ACCELERATED);
    Timer timer;

    std::vector<Planet*> solarSystem;
    Planet earth(EARTH_MASS, 20, 0, 0, 0, 0, &solarSystem);
    Planet moon(0.012 * EARTH_MASS, 10, 384400000, 0, 0, -1022, &solarSystem);

    while (game.getIsRunning()) {
        timer.reset();
        game.clearRender();
        game.handleEvents();
        for (std::vector<Planet*>::iterator planet = solarSystem.begin(); planet < solarSystem.end(); planet++)
        {
            Vec position = (*planet)->positionOnScreen(WIDTH, HEIGHT, SCALE);
            game.drawCircle(blue, (*planet)->getRadius(), position.x, position.y);
            (*planet)->move(TIMESTEP);
        }
        if (timer.elapsedTime() < TIME_PER_FRAME)
            SDL_Delay(TIME_PER_FRAME - timer.elapsedTime());
    }
    return 0;
}