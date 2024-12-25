#include <iostream>
#include <cmath>

int main() {
    long double x,y;
    std::cout << "Input x and y: ";
    std::cin >> x >> y;
    std::cout << '\n';
    std::cout << "Choose ex or x^2:";
    std::string input;
    std::cin >> input;
    long double fx;
    if(input == "ex"){
        fx = exp(x);
    }
    if(input == "x^2"){
        fx = x * x;
    }
    long double d;
    if(x > y){
        d = pow(fx-y, 3) + atan(fx);
    }
    if(y > x){
        d = pow(y-fx,3) + atan(fx);
    }
    if(x == y){
        d = pow(y + fx,3) + 0.5;
    }

    std::cout << "x = " << x << " y = " << y << " f(x) = " << input << " d = " << d;
}