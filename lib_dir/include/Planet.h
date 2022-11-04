#pragma once
#include <cmath>
#include <vector>
#include <Color.h>
#define for_planet_in(system) for (std::vector<Planet*>::iterator planet = system.begin(); planet < system.end(); planet++)


struct Vec { 
    double x, y;
    double getMagnitude();
    Vec operator-(Vec other);
};

class Planet {
private:
    double mass_, x_, y_, dx_, dy_;
    int radius_;
    Color color_;
    const double G = 6.674e-11;
    std::vector<Planet*>* planetSystem_;

    Vec distanceWith(Planet other);
    Vec forceWith(Planet other);
    Vec sumOfForces();

public:
    /**
     * Constructor for Planet class. 
     * Takes serveral inputs to allow proper simulation of the planet.
     * 
     * \param mass mass of the planet in kilograms (kg)
     * \param radius radius of the planet to be rendered in number of pixels
     * \param color color of the planet given using the Color struct
     * \param x initial x position of the planet in meters (m) where (0, 0) is the center
     * \param y initial y position of the planet in meters (m) where (0, 0) is the center
     * \param dx initial speed of the planet in the x direction in meters per second (m/s)
     * \param dy initial speed of the planet in the y direction in meters per second (m/s)
     * \param system a pointer to a vector containing pointers of planets for the planet system to simulate gravity in  
    */
    Planet(double mass, int radius, Color color, double x, double y, double dx, double dy, std::vector<Planet*>* system);

    /**
     * getter for the x position of the planet
     * \return a double containing the x position
    */
    double getX();

    /**
     * getter for the y position of the planet
     * \return a double containing the y position
    */
    double getY();

    /**
     * getter for the mass of the planet
     * \return a double containing the planet's mass
    */
    double getMass();

    /**
     * getter for the radius of the planet
     * \return a int containing the planet's radius
    */
    int getRadius();

    /**
     * getter for the color of the planet
     * \return a Color describing the planet's color
    */
    Color getColor();

    /**
     * Calculates the sum of all forces acting on the planet by its neighbors and moves the planet.
     * 
     * Using Newton's law of gravitation, a new x and y position as well as speed is determined for the planet
     * 
     * \param timestep the step in time to use in the computation
    */
    void move(const double timestep);

    /**
     * Calculates the position to place the planet on, depending on the window's size and the scale
     * 
     * \param width the width of the window in pixels
     * \param height the height of the window in pixels
     * \param scale the scale at which to represent the planet in pixels/meter (p/m)
     * 
     * \return a Vec object with the x and y position on the window
    */
    Vec positionOnScreen(double width, double height, double scale);

    /**
     * 
    */
    Vec positionOnScreen(double width, double height, double scale, Planet CenterPlanet);
};
