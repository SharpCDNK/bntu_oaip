#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        n--;
        if(digits[n] != 9){
            digits[n]++;
        }else{
            digits[n]++;
            for(int i = n; i >= 0; i--){
                if(digits[i] == 10){
                    if(i == 0){
                        digits[i] = 0;
                        digits.insert(digits.begin(),1);

                        break;
                    }
                    digits[i-1]++;
                    digits[i] = 0;
                }

            }
        }
        return digits;
    }
};

int main(){
    Solution a;
    std::vector<int> digits= {9};
    std::vector<int> ans = a.plusOne(digits);
    for(auto i : ans){
        std::cout << i << ' ';
    }
}