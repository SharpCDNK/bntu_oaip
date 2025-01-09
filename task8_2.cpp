#include <iostream>
#include <limits>

int main(){
    int n;
    std::cin >> n;
    int* ar = new int[n];
    for(int i = 1; i <= n; i++){
        std::cin >> ar[i];
    }
    int** ans = new int*[25];
    for(int i = 0; i < 25; i++){
        ans[i] = new int[4];
        for(int j = 0; j < 4; j++){
            ans[i][j] = ar[i * 4 + j];
        }
    }

    for(int i = 0; i < 25; i++){
        int cur_min = std::numeric_limits<int>::min();
        for(int j = 0; j < 4; j++) {
            if(cur_min < ans[i][j])
                cur_min = ans[i][j];
        }
        std::cout << "Cur row is " << i << " and max is " << cur_min << '\n';
    }

    for(int i = 0; i < 25; i++){
        delete[] ans[i];
    }
    delete[] ans;

}
/*
100
16 78 99 6 -29 19 -52 65 -88 51 -79 -22 32 -25 -62 -69 -2 -59 -75 89 -87 95 -22 85 -49 -75 76 73 -59 -52 30 49 -28 -48 0 57 -6 -85 0 -18 -97 -21 -95 64 22 -2 69 -84 -1 -71 -25 47 72 43 15 -44 44 61 4 74 88 -61 0 -64 -83 97 0 90 15 8 -54 19 73 35 -67 -87 85 -99 -70 10 98 58 -10 -29 95 62 77 89 36 -32 78 60 -79 -18 30 -13 -34 -92 1 -38
*/