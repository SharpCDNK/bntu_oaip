#include <iostream>
#include <stdio.h>
#include <math.h>

double T(double x){
    return (x-1)/(x+1);
}
std::pair<double,int> iter(double sum, int n, double ch, double x, double eps){
    sum = ch;
    for(n = 1;n < 500 && abs(ch) >= eps; n++, sum += ch){
        ch *= ((2 * n - 1) * pow(x - 1, 2)) / ((2 * n + 1) * pow(x + 1, 2));
    }
    return {sum*2,n};
}
int main()
{

    double xn, xk, dx, eps, mathF, sum;
    int n;

    std::cin >> xn >> xk >> dx >> eps;

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "|    x    |    F       |    n    |   math F   |\n";
    std::cout << "-----------------------------------------------\n";

    for(double x = xn; x < xk; x += dx)
    {

        double ch = T(x);
        std::pair<double,int> it = iter(sum,n,ch,x,eps);


        mathF = log(x);

        std::cout <<"|  " <<  x << ' '<<  it.first <<' ' <<  it.second<<  ' ' << mathF << " |" << '\n';

    }

    std::cout << "-----------------------------------------------\n";

}