#pragma once
#include <cmath>
#include <vector>

class Planet {
private:
    double x_, y_, dx_, dy_;

    double distanceWith(Planet other);

    std::vector<double> distanceWithInVector(Planet other);

public:
    Planet(int x, int y);

    double getX();

    double getY();
};
