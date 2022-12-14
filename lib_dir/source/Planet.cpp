#include "Planet.h"

double Vec::getMagnitude() {
    return sqrt((x * x) + (y * y));
}

Vec Vec::operator-(Vec other) {
    return { other.x - x, other.y - y};
}

Vec Planet::distanceWith(Planet other) {
    double deltax = other.x_ - x_;
    double deltay = other.y_ - y_;
    return { deltax, deltay };
}

Vec Planet::forceWith(Planet other) {
    Vec distance = distanceWith(other);
    double forceMagnitude = G * mass_ * other.mass_ / pow(distance.getMagnitude(), 2);
    Vec force;
    force.x = forceMagnitude * distance.x / distance.getMagnitude();
    force.y = forceMagnitude * distance.y / distance.getMagnitude();
    return force;
}

Vec Planet::sumOfForces() {
    double forceInX = 0, forceInY = 0;
    for_planet_in((*planetSystem_)) {
        if ((*planet)->getX() == x_ || (*planet)->getY() == y_)
            continue;
        Vec force = forceWith(**planet);
        forceInX += force.x;
        forceInY += force.y;
    }
    return { forceInX, forceInY };
}

Planet::Planet(double mass, int radius, Color color, double x, double y, double dx, double dy, std::vector<Planet*>* system) {
    x_ = x;
    y_ = y;
    dx_ = dx;
    dy_ = dy;
    mass_ = mass;
    radius_ = radius;
    color_ = color;
    system->push_back(this);
    planetSystem_ = system;
}

double Planet::getX() { return x_; }

double Planet::getY() { return y_; }

double Planet::getMass() { return mass_; }

int Planet::getRadius() { return radius_; }

Color Planet::getColor() { return color_; }

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

Vec Planet::positionOnScreen(double width, double height, double scale, Planet centerPlanet) {
    double relativeX = (x_ - centerPlanet.x_) * scale + (width / 2);
    double relativeY = (y_ - centerPlanet.y_) * scale + (height / 2);
    return { relativeX, relativeY };
}