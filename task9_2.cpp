#include <iostream>
#include <string>
#include <fstream>

class Znak{
public:
    std::string surname;
    std::string name;
    std::string zadiak_sign;
    int d, m, y;

    void writeToFile(std::ofstream &out) {
        size_t surname_length = surname.size();
        size_t name_length = name.size();
        size_t zadiak_sign_length = zadiak_sign.size();


        out.write(reinterpret_cast<char*>(&surname_length), sizeof(surname_length));
        out.write(surname.c_str(), surname_length);

        out.write(reinterpret_cast<char*>(&name_length), sizeof(name_length));
        out.write(name.c_str(), name_length);

        out.write(reinterpret_cast<char*>(&zadiak_sign_length), sizeof(zadiak_sign_length));
        out.write(zadiak_sign.c_str(), zadiak_sign_length);

        out.write(reinterpret_cast<char*>(&d), sizeof(d));
        out.write(reinterpret_cast<char*>(&m), sizeof(m));
        out.write(reinterpret_cast<char*>(&y), sizeof(y));
    }
};

int main() {
    int n;
    std::cout << "Введите количество людей: ";
    std::cin >> n;

    std::ofstream out("4.dat", std::ios::binary);
    if (!out) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1;
    }

    while (n--) {
        Znak person;
        std::cout << "Введите фамилию: ";
        std::cin >> person.surname;
        std::cout << "Введите имя: ";
        std::cin >> person.name;
        std::cout << "Введите знак зодиака: ";
        std::cin >> person.zadiak_sign;
        std::cout << "Введите дату рождения (день месяц год): ";
        std::cin >> person.d >> person.m >> person.y;

        person.writeToFile(out);
    }

    out.close();
    std::cout << "Данные успешно записаны в файл '4.dat'." << std::endl;
}
/*
 * Фамилия: Khala, Имя: Nikita, Знак зодиака: Телец, Дата рождения: 9/5/2007
Фамилия: Линник, Имя: Артём, Знак зодиака: Весы, Дата рождения: 5/10/2006
 */