#pragma once
#include <SDL2/SDL.h>
#include <Timer.h>
#include <Color.h>

enum class Shape { SQUARE, CIRCLE, RECTANGLE };


class Game {
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
     * Sets isRunning_ attribute to false
    */
    void quit();

    /**
     * Draws a rectangle definied by parameters the user enters
     * 
     * \param color the color of the rectangle
     * \param x the x position of the top left corner
     * \param y the y position of the top left corner
     * \param w the width of the rectangle
     * \param h the height of the rectangle
    */
    void drawRect(Color color, int x, int y, int w, int h);

    /**
     * Draws a circles to the renderer
     * 
     * \param color the color of the circle
     * \param radius the radius
     * \param x x position of the center of the cirlce
     * \param y y position of the center of the circle
    */
    void drawCircle(Color color, int radius, int x, int y);

    /**
     * Calls the SDL_RenderClear method
    */
    void clearRender();

    /**
     * Calls the SDL_RenderPresent method
    */
    void presentRender();

    void toggleFullScreen();

    void handleFramerate(unsigned FPS = 60);
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    Timer timer_;
    bool isRunning_, isFullScreen_ = false;

    void windowInit(const char* name, int width, int height);
    void rendererInit(SDL_RendererFlags flags);

};