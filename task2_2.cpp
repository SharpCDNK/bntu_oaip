#include <iostream>
#include <cmath>

int main() {
    int input;
    std::cin >> input;
    std::string ans;
    if(input % 11 == 0){
        ans += 'A';
    }
    if(input > 100 || (input < 10 && input >= 1)){
        ans += 'B';
    }
    if(input > -20 && input <= -1){
        ans += 'C';
    }else{
        ans += 'D';
    }
    std::cout <<"The number "<< input << " belongs to the groups/group: " << ans;
}