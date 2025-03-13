#include <iostream>
#include <string>
#include <fstream>
#include <memory>


class Znak{
public:
    std::string surname;
    std::string name;
    std::string zodiak_sign;
    int d,m,y;

    bool readFromFile(std::istream &in){
        return static_cast<bool> (in >> surname >> name >> zodiak_sign >> d >> m >> y);
    }

    void print() const{
        std::cout << "Фамилия: " << surname
                  << ", Имя: " << name
                  << ", Знак зодиака: " << zodiak_sign
                  << ", Дата рождения: " << d << "/" << m << "/" << y << "\n";
    }
};


int main(){
    std::ifstream in("4.dat");

    if(!in){
        std::cerr << "Error file not found" << '\n';
    }

    int capacity = 10;
    std::unique_ptr<std::unique_ptr<Znak>[]> ar = std::make_unique<std::unique_ptr<Znak>[]>(capacity);

    size_t i = 0;

    while(i < capacity){
        std::unique_ptr<Znak> ptr_Znak = std::make_unique<Znak>();
        if(!ptr_Znak->readFromFile(in)){
            break;
        }
        ar[i] = std::move(ptr_Znak);
        i++;
    }

    for(size_t j = 0; j <= i; j++){
        ar[j]->print();
    }

}