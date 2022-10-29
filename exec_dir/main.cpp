#include <iostream>
#include <Planet.h>
using namespace std;

int main() {
    Planet ceres(10, 3);
    cout << "Ceres is currently at (" << ceres.getX() << ", " << ceres.getY() << ")" << endl;
    return 0;
}