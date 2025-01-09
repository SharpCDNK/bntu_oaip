#include <iostream>
#include <cctype>
#include <cstring>

int main(){
    char* ar = new char[101];
    std::cin.getline(ar,100);

    char* beg = ar;

    for(int i = 0; i < strlen(ar); i++){
        if(ispunct(*beg)){
            std::cout << i << ' ';
        }
        beg++;
    }

    delete[] ar;
}