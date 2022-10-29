#include "Planet.h"

Planet::Planet(int x, int y) {
    x_ = x;
    y_ = y;
}

double Planet::getX() { return x_; }

double Planet::getY() { return y_; }