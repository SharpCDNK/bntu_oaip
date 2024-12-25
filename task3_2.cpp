#include <iostream>
#include <math.h>



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

        double ch = (x - 1) / (x + 1);

        sum = ch;

        for(n = 1;n < 500 && abs(ch) >= eps; n++, sum += ch){
            ch *= ((2 * n - 1) * pow(x - 1, 2)) / ((2 * n + 1) * pow(x + 1, 2));
        }

        mathF = log(x);

        std::cout <<"|  " <<  x << ' '<<  2 * sum <<' ' <<  n <<  ' ' << mathF << " |" << '\n';

    }

    std::cout << "-----------------------------------------------\n";

}