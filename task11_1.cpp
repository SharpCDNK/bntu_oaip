#include <iostream>
#include <numbers>

long double square(long double r) {
    return 4 * std::numbers::pi * r * r;
}

long double square(long double r, long double h) {
    return 2 * std::numbers::pi * r * (h + r);
}

long double square(long double a, long double b, long double c) {
    return 2 * (a * b + a * c + b * c);
}

int main() {
    std::cout << "Square of Sphere with r = 4 is " << square(4.0) << '\n';
    std::cout << "Square of Cylinder with r = 4 and h = 5 is " << square(4.0, 5.0) << '\n';
    std::cout << "Square of Rectangular Parallelepiped with sides a = 2, b = 3, c = 4 is " << square(2.0, 3.0, 4.0) << '\n';
}