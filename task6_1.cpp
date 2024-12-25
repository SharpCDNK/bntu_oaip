#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
int main()
{
    std::string s;
    std::getline(std::cin , s);
    char c = ' ';
    int ans = std::count(s.begin(),s.end(),c);
    std::cout << ans;




}