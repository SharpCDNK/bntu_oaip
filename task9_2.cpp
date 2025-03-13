#include <iostream>
#include <fstream>
#include <string>

class Znak {
public:
    std::string surname;
    std::string name;
    std::string zodiac_sign;
    int d, m, y;

    void writeToFile(std::ofstream &out) const {
        out << surname << " "
            << name << " "
            << zodiac_sign << " "
            << d << " " << m << " " << y << "\n";
    }
};

int main() {
    int n;
    std::cout << "Введите количество людей: ";
    if (!(std::cin >> n)) {
        std::cerr << "Ошибка ввода количества!" << std::endl;
        return 1;
    }

    std::ofstream file("4.dat");
    if (!file) {
        std::cerr << "Ошибка открытия файла '4.dat'!" << std::endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {

        Znak person;
        std::cout << "Введите фамилию: ";
        std::cin >> person.surname;
        std::cout << "Введите имя: ";
        std::cin >> person.name;
        std::cout << "Введите знак зодиака: ";
        std::cin >> person.zodiac_sign;
        std::cout << "Введите дату рождения (день месяц год): ";
        std::cin >> person.d >> person.m >> person.y;

        person.writeToFile(file);
    }

    std::cout << "Данные успешно записаны в файл '4.dat'." << std::endl;
}