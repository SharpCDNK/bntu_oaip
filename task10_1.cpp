#include <iostream>
#include <vector>
#include <math.h>
#include <functional>


double average(double a, double b){
    return (a+b) / 2;
}

double expression_1(double a, double b){
    return a * 2 +  b * 2;
}

double expression_2(double a, double b){
    return sin(a) + sin(b);
}

double expression_3(double a, double b){

    return b != 0 ? a/b : 0;

}
int main(){

    double (*ar_fun[4])(double, double) = {average, expression_1, expression_2, expression_3};

    int a = 6, b = 2;

    for(size_t i = 0; i < 4; i++){

        std::cout << ar_fun[i](a,b) << '\n';
    }


    std::cout << "///////////////////////////////////////////////////////////\n";


    std::vector<std::function<double(double,double)>> ar_func_1= {average, expression_1, expression_2, expression_3};

    for(size_t i = 0; i < 4; i++){
        std::cout << ar_func_1[i](a,b) << '\n';
    }
}