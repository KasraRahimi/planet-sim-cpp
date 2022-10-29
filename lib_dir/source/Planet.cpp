#include "Planet.h"

double Planet::distanceWith(Planet other) {
    double deltax = other.x_ - x_;
    double deltay = other.y_ - y_;

    return sqrt(pow(deltax, 2) + pow(deltay, 2));
}

std::vector<double> Planet::distanceWithInVector(Planet other) {
    double deltax = other.x_ - x_;
    double deltay = other.y_ - y_;
    std::vector<double> answer = { deltax, deltay };
    return answer;
}

Planet::Planet(int x, int y) {
    x_ = x;
    y_ = y;
}

double Planet::getX() { return x_; }

double Planet::getY() { return y_; }