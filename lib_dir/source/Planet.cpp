#include "Planet.h"

double Vec::getMagnitude() {
    return sqrt((x * x) + (y * y));
}

Vec Planet::distanceWith(Planet other) {
    double deltax = other.x_ - x_;
    double deltay = other.y_ - y_;
    return { deltax, deltay };
}

Vec Planet::forceWith(Planet other) {
    Vec distance = distanceWith(other);
    double forceMagnitude = G * mass_ * other.getMass() / pow(distance.getMagnitude(), 2);
    Vec force;
    force.x = forceMagnitude * distance.x / distance.getMagnitude();
    force.y = forceMagnitude * distance.y / distance.getMagnitude();
    return force;
}

Vec Planet::sumOfForces() {
    double forceInX = 0, forceInY = 0;
    for (std::vector<Planet*>::iterator planet = planetSystem_->begin(); planet < planetSystem_->end(); planet++) {
        if ((*planet)->getX() == x_ || (*planet)->getY() == y_)
            continue;
        Vec force = forceWith(**planet);
        forceInX += force.x;
        forceInY += force.y;
    }
    return { forceInX, forceInY };
}

Planet::Planet(double mass, int radius, double x, double y, double dx, double dy, std::vector<Planet*>* system) {
    x_ = x;
    y_ = y;
    dx_ = dx;
    dy_ = dy;
    mass_ = mass;
    radius_ = radius;
    system->push_back(this);
    planetSystem_ = system;
}

double Planet::getX() { return x_; }

double Planet::getY() { return y_; }

double Planet::getMass() { return mass_; }

int Planet::getRadius() { return radius_; }

void Planet::move(const double timestep) {
    x_ += dx_ * timestep;
    y_ += dy_ * timestep;

    Vec force = sumOfForces();
    dx_ += force.x * timestep / mass_;
    dy_ += force.y * timestep / mass_;
}

Vec Planet::positionOnScreen(double width, double height, double scale) {
    double relativeX = x_ * scale + (width / 2);
    double relativeY = y_ * scale + (height / 2);
    return { relativeX, relativeY };
}