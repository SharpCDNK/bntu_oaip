#include <iostream>
#include <cmath>
#include <map>

int main() {

    int n;
    std::cout << "Input amount of data: ";
    std::cin >> n;
    std::map<int,std::string> Sqoflands;
    int input;
    std::cout << std::endl << "Input the size of the area: ";
    std::cin >> input;
    std::cout << "Input the name of the territory and the size of the area in km: " << '\n';
    for(int i = 0; i < n; i++){
        std::string terr;
        int size;
        std::cin >> terr >> size;
        Sqoflands[size] = terr;
    }
    std::cout << "Territories have an area of at least " << input << " square meters: " << '\n';
    for(auto &i : Sqoflands){
        if(i.first >= input){
            std::cout << i.second << " - " << i.first << '\n';
        }
    }
}




/*

15
Great_Britain 229979
Iceland 103000
Irish 84000
Novaya_Zemlya 82600
Svalbard 62700
Sicily 25426
Sardinia 23813
Franz_Land 16100
Corsica 8720
Crete 8300
Zealand 7026
Kolguev 5200
Euboea 3770
Mallorca 3410
Vaigach 3380
Gotland 3001
 */