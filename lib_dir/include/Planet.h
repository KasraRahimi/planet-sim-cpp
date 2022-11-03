#pragma once
#include <cmath>
#include <vector>
#include <Color.h>
#define for_planet_in(system) for (std::vector<Planet*>::iterator planet = system.begin(); planet < system.end(); planet++)


struct Vec { 
    double x, y;
    double getMagnitude();
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
    Planet(double mass, int radius_, Color color, double x, double y, double dx, double dy, std::vector<Planet*>* system);
    double getX();
    double getY();
    double getMass();
    int getRadius();
    Color getColor();
    void move(const double timestep);
    Vec positionOnScreen(double width, double height, double scale);
};
