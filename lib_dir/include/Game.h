#pragma once
#include <SDL2/SDL.h>

struct Color
{
    Uint8 r, g, b, a;
};


class Game {

private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Event event_;
    bool isRunning_;

    void windowInit(const char* name, int width, int height);

    void rendererInit(SDL_RendererFlags flags);

    void setRenderColor(Color color);

public:
    Game() = default;
/**
 * Initialize the game by creating a window and renderer.
 * The user establishes certain parameters for the game window and render.
 * 
 * \param SDLFlags the flags for the SDL_Init function
 * \param name the name of the window
 * \param width the width of the window
 * \param height the height of the window
 * \param flags the flags for the renderer
*/
    Game(Uint32 SDLFlags, const char name[], int width, int height, SDL_RendererFlags rendererFlags);

/**
 * The getter for the isRunning boolean.
 * This is used as the condition for the game loop
 * \returns true if game is running, false if not
*/
    bool getIsRunning() const;

/**
 * Handles game events such as quitting.
*/
    void handleEvents();

};