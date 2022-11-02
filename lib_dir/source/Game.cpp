#include <Game.h>

void Game::windowInit(const char* name, int width, int height) {
    window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
}

void Game::rendererInit(SDL_RendererFlags flags) {
    renderer_ = SDL_CreateRenderer(window_, -1, flags);
}

void Game::drawRect(Color color, int x, int y, int w, int h) {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer_, &rect);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderPresent(renderer_);
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