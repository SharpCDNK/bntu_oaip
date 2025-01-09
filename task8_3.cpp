#include <iostream>
#include <random>
#include <ctime>

int main(){
    int x = 3, y = 7, z = 12;
    char*** ar = new char**[x];
    for(int i = 0; i < x; i++){
        ar[i] = new char*[y];
        for(int j = 0; j < y; j++){
            ar[i][j] = new char[z];
        }
    }
    std::mt19937 generator(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<int> distribution(0, 25);
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            for(int k = 0; k < z; k++){
                ar[i][j][k] = 'A' + distribution(generator);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                if (ar[i][j][k] == 'A' ||
                    ar[i][j][k] == 'E' ||
                    ar[i][j][k] == 'I' ||
                    ar[i][j][k] == 'O' ||
                    ar[i][j][k] == 'U')
                    std::cout << "ar[" << i << "][" << j << "][" << k << "] = " << ar[i][j][k] << '\n';
                if(ar[i][j][10] == 'Q')
                    count++;
            }
        }
    }
    std::cout << "\n\nCount of [i][j][10] = Q is " << count;

}