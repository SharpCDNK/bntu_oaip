#include <iostream>
#include <cmath>

int main() {
    long double alpha;
    std::cout << "Input alpha : ";
    std::cin >> alpha;
    long double z1 = ( sin(alpha) + sin(5 * alpha) - sin(3 * alpha) ) / cos(alpha) - cos(3 * alpha) + cos(5 * alpha);
    long double z2 = tan(3 * alpha);
    std::cout << "alpha = " << alpha << " z1 = " << z1 << " z2 = " << z2 << '\n';
}