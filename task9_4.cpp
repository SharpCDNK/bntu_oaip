#include <iostream>
#include <string>
#include <fstream>

class Znak {
public:
    std::string surname;
    std::string name;
    std::string zodiak_sign;
    int d, m, y;

    void readFromFile(std::ifstream &in) {
        size_t length;
        char buffer[256];

        in.read(reinterpret_cast<char*>(&length), sizeof(length));
        in.read(buffer, length);
        buffer[length] = '\0';
        surname = buffer;

        in.read(reinterpret_cast<char*>(&length), sizeof(length));
        in.read(buffer, length);
        buffer[length] = '\0';
        name = buffer;

        in.read(reinterpret_cast<char*>(&length), sizeof(length));
        in.read(buffer, length);
        buffer[length] = '\0';
        zodiak_sign = buffer;

        in.read(reinterpret_cast<char*>(&d), sizeof(d));
        in.read(reinterpret_cast<char*>(&m), sizeof(m));
        in.read(reinterpret_cast<char*>(&y), sizeof(y));
    }

    void print() {
        std::cout << "Фамилия: " << surname << ", Имя: " << name
                  << ", Знак зодиака: " << zodiak_sign
                  << ", Дата рождения: " << d << "/" << m << "/" << y << '\n';
    }
};

int main() {
    int n;
    std::cin >> n;
    Znak* people[n];

    std::ifstream in("4.dat", std::ios::binary);
    if (!in) {
        std::cerr << "Ошибка открытия файла!" << '\n';
        return 1;
    }

    for (int i = 0; i < n; i++) {
        people[i] = new Znak;
        people[i]->readFromFile(in);
    }

    in.close();

    for (int i = 0; i < n; i++) {
        people[i]->print();
        delete people[i];
    }

    return 0;
}
