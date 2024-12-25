#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct AEROFLOT{
    int flight_num;
    std::string destination;
    std::string type_aircraft;

};
bool comp(AEROFLOT &a, AEROFLOT &b){
    return a.flight_num < b.flight_num;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<AEROFLOT> ar(n) ;
    for(int i = 0; i < n; i++){
        AEROFLOT input;
        std::cin >> input.flight_num >> input.destination >> input.type_aircraft;
        ar[i] = input;
    }
    std::sort(ar.begin(),ar.end(), comp);

    for(auto i : ar){
        std::cout << i.flight_num << ' ' << i.destination << ' ' << i.type_aircraft << '\n';
    }

    std::string check_dest;
    std::cin >> check_dest;
    bool c = false;
    for(auto i: ar){
        if(i.destination == check_dest){
            c = true;
            std::cout << i.flight_num << ' ' << i.destination << ' ' << i.type_aircraft << '\n';
        }
    }
    if(c == false){
        std::cout << "There are no such flights";
    }



}
/*
5
9234 Moscow Boeing742
1234 Moscow Boeing747
5436 Berlin Airbus350
2134 Paris Airbus320
4321 London Boeing777
Moscow
*/