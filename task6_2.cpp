#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
bool comp(std::string &a, std::string &b){
    return a.size() < b.size();
}
int main()
{
    std::string s = "So she was considering in her own mind, as well as she could,"
                    "for the hot day made her feel very sleepy and stupid, whether"
                    " the pleasure of making a daisy-chain would be worth the"
                    "trouble of getting up and picking the daisies, when suddenly a"
                    "White Rabbit with pink eyes ran close by her.";
    std::string cur;
    std::vector < std::string > ar;
    std::pair<int,std::string> q2;
    q2.first = LLONG_MAX;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ' || s[i] == '.' || s[i] == ',' )
        {
            if(cur == "")
                continue;
            else{
                ar.emplace_back(cur);
                if(cur[cur.size()-1] == 'd')
                {
                    if(cur.size() < q2.first){
                        q2.first = cur.size();
                        q2.second = cur;
                    }
                }
                cur = "";
            }



            continue;
        }
        cur += s[i];
    }
    std::sort(ar.begin(),ar.end(),comp);
    int q1 = 0;
    for(auto &i : ar){
        if(i.size() < 5){
            q1++;
        }
        std::cout << i << '\n';
    }
    std::cout << '\n';
    std::cout << "q1 = " << q1 << '\n';
    std::cout << "q2 = " << q2.first << ' ' << q2.second << '\n';


}