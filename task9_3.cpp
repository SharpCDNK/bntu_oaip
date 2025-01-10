#include <iostream>
#include <string>
#include <fstream>
#include <vector>

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

    bool checkZodiac() {
        if ((zodiak_sign == "Овен" && ((m == 3 && d >= 21) || (m == 4 && d <= 19))) ||
            (zodiak_sign == "Телец" && ((m == 4 && d >= 20) || (m == 5 && d <= 20))) ||
            (zodiak_sign == "Близнецы" && ((m == 5 && d >= 21) || (m == 6 && d <= 20))) ||
            (zodiak_sign == "Рак" && ((m == 6 && d >= 21) || (m == 7 && d <= 22))) ||
            (zodiak_sign == "Лев" && ((m == 7 && d >= 23) || (m == 8 && d <= 22))) ||
            (zodiak_sign == "Дева" && ((m == 8 && d >= 23) || (m == 9 && d <= 22))) ||
            (zodiak_sign == "Весы" && ((m == 9 && d >= 23) || (m == 10 && d <= 22))) ||
            (zodiak_sign == "Скорпион" && ((m == 10 && d >= 23) || (m == 11 && d <= 21))) ||
            (zodiak_sign == "Стрелец" && ((m == 11 && d >= 22) || (m == 12 && d <= 21))) ||
            (zodiak_sign == "Козерог" && ((m == 12 && d >= 22) || (m == 1 && d <= 19))) ||
            (zodiak_sign == "Водолей" && ((m == 1 && d >= 20) || (m == 2 && d <= 18))) ||
            (zodiak_sign == "Рыбы" && ((m == 2 && d >= 19) || (m == 3 && d <= 20))))
        {
            return true;
        }
        return false;
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
    Znak people[n];

    std::ifstream in("4.dat", std::ios::binary);
    if (!in) {
        std::cerr << "Ошибка открытия файла!" << '\n';
        return 1;
    }

    for (int i = 0; i < n; i++) {
        people[i].readFromFile(in);
    }

    in.close();

    for (int i = 0; i < n; i++) {
        if (!people[i].checkZodiac()) {
            people[i].print();
        }
    }

}
