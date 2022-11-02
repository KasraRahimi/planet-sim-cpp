#pragma once
#include <cmath>
#include <vector>

struct Vec { 
    double x, y;
    double getMagnitude();
};

class Planet {
private:
    double mass_, x_, y_, dx_, dy_;
    int radius_;
    const double G = 6.674e-11;
    std::vector<Planet*>* planetSystem_;

    Vec distanceWith(Planet other);
    Vec forceWith(Planet other);
    Vec sumOfForces();

public:
    Planet(double mass, int radius_, double x, double y, double dx, double dy, std::vector<Planet*>* system);
    double getX();
    double getY();
    double getMass();
    int getRadius();
    void move(const double timestep);
    Vec positionOnScreen(double width, double height, double scale);
};
