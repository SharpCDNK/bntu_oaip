#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>


int main()
{
    std::vector <double> ar = {3.24, -0.16, 2.28, -0.16, -3.22, 7.14, 0.88, -3.20, 0.99, 4.15};
    double sum1 = 0, sum2 = 0;
    bool c = false;
    int index1 = 0;
    for(int i = 0 ;i < ar.size(); i++){
        if(i&1){
            sum1 += ar[i];
        }
        if(ar[i] < 0 && c == false){
            c = true;
            index1 = i;
        }
    }

    std::cout << "Sum1 = " << sum1 << '\n';

    bool c1 = false;

    for(int j = ar.size(); j >= index1; j--){
        if(ar[j] < 0 || c1 == true){
            sum2 += ar[j];
            //std::cout << ar[j] << ' ';
            c1 = true;
        }
    }

    std::cout << "Sum2 = " << sum2 << '\n';

    for(int i = 0; i < ar.size(); i++){
        if(abs(ar[i]) < 1){
            ar.erase(ar.begin()+i);
        }

    }
    ar.shrink_to_fit();
    //std::cout << ar.capacity() << ' ';
    for(int i = 0; i < ar.size(); i++){
        std::cout << ar[i] << ' ';
    }
}