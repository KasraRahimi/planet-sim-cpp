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

void Game::quit() { isRunning_ = false; }

void Game::drawRect(Color color, int x, int y, int w, int h) {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer_, &rect);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
}

void Game::drawCircle(Color color, int radius, int x, int y) {
    SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
    int rsquared = radius * radius;
    for (int i = -radius; i <= radius; i++) {
        for (int j = -radius; j <= radius; j++) {
            if ((i*i) + (j*j) <= rsquared)
                SDL_RenderDrawPoint(renderer_, i + x, j + y);
        }
    }
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
}

void Game::clearRender() {
    SDL_RenderClear(renderer_);
}

void Game::presentRender() {
    SDL_RenderPresent(renderer_);
}

void Game::toggleFullScreen() {
    isFullScreen_ = !isFullScreen_;
    if (isFullScreen_)
        SDL_SetWindowFullscreen(window_, SDL_WINDOW_FULLSCREEN);
    else
        SDL_SetWindowFullscreen(window_, 0);
}