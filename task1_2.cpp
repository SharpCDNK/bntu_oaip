#include <iostream>
#include <cmath>

int main() {
    long double a,b,c;
    std::cin >> a >> b >> c;
    long double p = (a + b + c) / 2;
    long double cnt  = 2 * sqrt(p * (p-a) * (p-b) * (p-c));
    long double ha = cnt/a, hb = cnt/b, hc = cnt/c;
    std::cout << "a = " << a << " b = " << b << " c = " << c << " ha = " << ha << " hb = " << hb << " hc = " << hc;
}
/*
 * 
 */