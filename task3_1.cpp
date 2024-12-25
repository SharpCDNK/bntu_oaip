#include <iostream>
#include<iomanip>

int main() {
    long double x1, x2, dx, a, b, c;
    std::cin >> x1 >> x2 >> dx >> a >> b >> c;
    std::cout << "------------------" << '\n';
    std::cout << "|   X   |   F    |" << '\n';
    std::cout << "------------------" << '\n';
    for(long double x = x1; x <= x2; x += dx){
        long double f;
        if(x < 0 && b != 0){
            f = -(2 * x - c) / (c * x - a);
        }
        if(x > 0 && b == 0){
            f = (x-a)/(x-c);
        }else{
            f = -x/c + -b/2*x;
        }

        std::cout << "|   " << std::setprecision(2) <<x << "   |   " << f <<"   |"<< '\n';
//        std::cout << x << '\n'; -2.3 2.5 0.5 -1.4 -3.2 -4.6
    }
    std::cout << "-----------------" << '\n';


}