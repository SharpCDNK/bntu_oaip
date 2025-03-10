#include <iostream>
#include <vector>
#include <string>


class Znak{
public:
    std::string surname;
    std::string name;
    std::string zodiak_sign;
    int d,m,y;
};

void print(char&& chr){
    std::cout << chr << '\n';
}

void print(std::vector<int>& ar){
    for(auto& element: ar){
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

void print(Znak& a){
    std::cout << "Surname: " << a.surname << '\n';
    std::cout << "Name: " << a.name << '\n';
    std::cout << "Zodiak-sign: " << a.zodiak_sign << '\n';
    std::cout << "d.m.y: " << a.d << '.' << a.m << '.' << a.y << '\n';
}

int main(){
    print('H');

    std::vector<int> ar = {1,2,3};
    print(ar);

    Znak b = {"Khala", "Nikita","Taurus", 9,5,2007};
    print(b);

}