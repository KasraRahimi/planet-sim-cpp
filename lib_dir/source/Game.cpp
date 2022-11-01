#include <Game.h>

void Game::windowInit(const char* name, int width, int height) {
    window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}

void Game::rendererInit(SDL_RendererFlags flags) {
    renderer_ = SDL_CreateRenderer(window_, -1, flags);
}

Game::Game(Uint32 SDLFlags, const char name[], int width, int height, SDL_RendererFlags rendererFlags) {
    SDL_Init(SDLFlags);
    windowInit(name, width, height);
    rendererInit(rendererFlags);
}

bool Game::getIsRunning() const {
    return isRunning_;
}

void Game::handleEvents() {
    while(SDL_PollEvent(&event_)) {
        switch (event_.type) {
        case SDL_QUIT:
            isRunning_ = false;
            break;
        default:
            break;
        }
    }
}