#include <iostream>
#include <cmath>
#include <limits>

double bisection(double (*f)(double), double a, double b, double eps) {

    double mid = 0.0;
    while ((b - a) / 2 > eps) {
        mid = (a + b) / 2;
        double fmid = f(mid);
        if (fmid == 0.0)
            return mid;
        if (f(a) * fmid < 0)
            b = mid;
        else
            a = mid;
    }
    return (a + b) / 2;
}

double equation1(double x) {
    return 3 * x * x - 150 * sin(x);
}

double equation2(double x) {
    return exp(x / 2) - x * x * x + 50;
}

double equation3(double x) {
    return x * x * x - x * x - 50;
}

double equation4(double x) {
    return 3 * x - x * x;
}

int main() {

    double a = 1.5, b = 4.5;
    double eps = 0.0001;

    double root1 = bisection(equation1, a, b, eps);
    std::cout << "Корень уравнения 1 (3*x^2 - 150*sin(x) = 0): " << root1 << "\n";

    double root2 = bisection(equation2, a, b, eps);
    std::cout << "Корень уравнения 2 (exp(x/2) - x^3 + 50 = 0): " << root2 << "\n";

    double root3 = bisection(equation3, a, b, eps);
    std::cout << "Корень уравнения 3 (x^3 - x^2 - 50 = 0): " << root3 << "\n";

    double root4 = bisection(equation4, a, b, eps);
    std::cout << "Корень уравнения 4 (3x - x^2 = 0): " << root4 << "\n";

}
