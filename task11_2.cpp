#include <iostream>
#include <vector>
#include <type_traits>

template <typename T>
double calc_average(std::vector<std::vector<T>>& matrix){
    static_assert(std::is_arithmetic<T>::value, "Type should be arithmetic");

    T sum  = 0;
    size_t count = 0;

    for(auto& row : matrix){
        for(auto& element: row){
            sum += element;
            count++;
        }
    }

    return static_cast<double>(sum) / count;

}
int main(){

    std::vector<std::vector<int>> int_matrix = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };

    std::vector<std::vector<double>> double_matrix = {
            {1.1,2.2,3.3},
            {4.4,5.5,6.6},
            {7.7,8.8,9.9}
    };

    std::cout << "Int matrix average : " << calc_average(int_matrix) << '\n';

    std::cout << "Double matrix average : " << calc_average(double_matrix) << '\n';



}