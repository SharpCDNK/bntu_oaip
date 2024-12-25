#include <iostream>
#include <cmath>

double f(double x, double y){

    std::cout << "Choose ex or x^2:";
    std::string input;
    std::cin >> input;
    long double fx;
    if(input == "ex"){
        fx = exp(x);
    }
    if(input == "x^2"){
        fx = x * 2;
    }
    return fx;
}

double one(double &fx, double y){
    return pow(fx-y, 3) + atan(fx);
}

double two(double &fx, double y){
    return pow(y-fx,3) + atan(fx);
}

double three(double &fx, double y){
    return pow(y + fx,3) + 0.5;
}

int main() {
    long double x,y;
    std::cout << "Input x and y: ";
    std::cin >> x >> y;
    std::cout << '\n';
    double fx = f(x,y);
    double ans1 = one(fx,y), ans2 = two(fx,y) , ans3 = three(fx,y);

    std::cout << "x = " << x << " y = " << y << " f(x) = " << fx << " one = " << ans1 << " two = " << ans2 << " three =" << ans3;
}