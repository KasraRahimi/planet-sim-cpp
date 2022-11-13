#include <iostream>
#include <Game.h>
#include <Planet.h>

#define WIDTH 1024
#define HEIGHT 576
#define FPS 60
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
    SDL_Event event;

    std::vector<Planet*> solarSystem;
    Planet sun(1.989e30, 20, YELLOW, 0, 0, 0, 0, &solarSystem);
    Planet mercury(0.055 * EARTH_MASS, 5, GREY, 60e9, 0, 0, -47e3, &solarSystem);
    Planet venus(0.815 * EARTH_MASS, 8, ORANGE, 109e9, 0, 0, -35e3, &solarSystem);
    Planet earth(EARTH_MASS, 10, BLUE, 150e9, 0, 0, -30e3, &solarSystem);
    Planet mars(0.107 * EARTH_MASS, 7, RED, 225e9, 0, 0, -24e3, &solarSystem);

    size_t index = 0;

    while (game.getIsRunning()) {
        game.clearRender();
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game.quit();
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            if (++index >= solarSystem.size())
                                index = 0;
                            break;
                        case SDLK_LEFT:
                            if (index == 0)
                                index = solarSystem.size() - 1;
                            else
                                --index;
                            break;
                        case SDLK_F11:
                            game.toggleFullScreen();
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        for_planet_in(solarSystem) {
            Vec position = (*planet)->positionOnScreen(WIDTH, HEIGHT, SCALE, *solarSystem[index]);
            int radius = (*planet)->getRadius();
            game.drawCircle((*planet)->getColor(), radius, position.x, position.y);
            (*planet)->move(TIMESTEP);
        }
        game.presentRender();
        game.handleFramerate(FPS);
    }
    return 0;
}