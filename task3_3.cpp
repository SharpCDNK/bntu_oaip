#include <iostream>

int main() {
    int x;
    int ans = 0;
    while(std::cin >> x){
        if(!(x&1)){
            ans++;
        }
        if(x > 1000){
            break;
        }
    }
    std::cout << ans;

}