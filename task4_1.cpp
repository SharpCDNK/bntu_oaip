#include <iostream>
#include <cmath>

double Customsum(double &num1, double &num2){
    int exponent1, exponent2;
    double mantissa1 = std::frexp(num1,&exponent1), mantissa2 = std::frexp(num2,&exponent2);
    double num1 = mantissa1 * pow(2,exponent2), num2 = mantissa2 * pow(2,exponent1);
    return num1 + num2;
}
int main() {
    double a,b;
    std::cin >> a >> b;
    double ans = Customsum(a,b);
    std::cout << ans;
}