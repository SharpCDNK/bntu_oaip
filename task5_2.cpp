#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>


int main()
{
    std::vector < std::vector<int> > m = {{ 16, 78, 1, 6, 29, 19, 52, 65, 88, 51},
                                          { -79, -22, 32, -25, -62, -69, -2, -59, -75, 89},
                                          { -87, 95, -22, 85, -49, -75, 76, 73, -59, -52},
                                          { 30, 49, -28, -48, 0, 57, -6, -85, 0, -18},
                                          { -99, -21, -95, 64, 22, -2, 69, -84, -1, -71},
                                          { -25, 47, 72, 43, 15, -44, 44, 61, 4, 74},
                                          { 88, -61, 0, -64, -83, 97, 0, 90, 15, 8},
                                          { -54, 99, 73, 35, -67, -87, 85, -93, -70, 10},
                                          { 98, 58, -10, -29, 95, 62, 77, 89, 36, -32},
                                          { 78, 60, -79, -18, 30, -13, -34, -92, 1, -38}};

    std::vector < std::pair<int,int> > ans;
    for(int i = 0; i < m.size(); i++){
        long long comp = 1;
        bool c = true;
        for(int j = 0; j < m[i].size(); j++){
            if(m[i][j] < 0){
                c = false;
                break;
            }
            comp *= m[i][j];
        }
        if(c == true){
            ans.push_back({i, comp});
        }
    }
    std::cout << "::::::::::::" << '\n';
    for(auto &i : ans){
        std::cout << i.first << ' ' << i.second << '\n';
    }
    std::cout << "::::::::::::" << '\n';
    int sum1 = 0;
    int ans2 = LLONG_MIN;
    for(int k = 0; k < m.size(); k++){
        int line = k;
        int el = 0;
        while(line< m.size() && el < m[line].size()){
            //std::cout << m[line][el] << ' ';
            sum1 += m[line][el];
            line ++;
            el++;
        }
        if(ans2 < sum1){
            ans2 = sum1;
        }
        sum1 = 0;
        //std::cout << '\n';

    }

    for(int k = 1; k < m.size(); k++){
        int line = 0;
        int el = k;
        while(line< m.size() && el < m[line].size()){
            //std::cout << m[line][el] << ' ';
            sum1 += m[line][el];
            line ++;
            el++;

        }

        if(ans2 < sum1) {
            ans2 = sum1;
        }
        //std::cout << '\n';

    }
    std::cout << ans2;






}