#pragma once

class Planet {
private:
    double x_, y_, dx_, dy_;

public:
    Planet(int x, int y);

    double getX();

    double getY();
};
