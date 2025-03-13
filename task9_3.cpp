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

    bool readFromFile(std::istream &in) {
        return static_cast<bool>(in >> surname >> name >> zodiak_sign >> d >> m >> y);
    }


    bool checkZodiac() const {
        if ((zodiak_sign == "Aries" && ((m == 3 && d >= 21) || (m == 4 && d <= 19))) ||
            (zodiak_sign == "Taurus" && ((m == 4 && d >= 20) || (m == 5 && d <= 20))) ||
            (zodiak_sign == "Gemini" && ((m == 5 && d >= 21) || (m == 6 && d <= 20))) ||
            (zodiak_sign == "Cancer" && ((m == 6 && d >= 21) || (m == 7 && d <= 22))) ||
            (zodiak_sign == "Leo" && ((m == 7 && d >= 23) || (m == 8 && d <= 22))) ||
            (zodiak_sign == "Virgo" && ((m == 8 && d >= 23) || (m == 9 && d <= 22))) ||
            (zodiak_sign == "Libra" && ((m == 9 && d >= 23) || (m == 10 && d <= 22))) ||
            (zodiak_sign == "Scorpio" && ((m == 10 && d >= 23) || (m == 11 && d <= 21))) ||
            (zodiak_sign == "Sagittarius" && ((m == 11 && d >= 22) || (m == 12 && d <= 21))) ||
            (zodiak_sign == "Capricorn" && ((m == 12 && d >= 22) || (m == 1 && d <= 19))) ||
            (zodiak_sign == "Aquarius" && ((m == 1 && d >= 20) || (m == 2 && d <= 18))) ||
            (zodiak_sign == "Pisces" && ((m == 2 && d >= 19) || (m == 3 && d <= 20))))
        {
            return true;
        }
        return false;
    }

    void print() const {
        std::cout << "Фамилия: " << surname
                  << ", Имя: " << name
                  << ", Знак зодиака: " << zodiak_sign
                  << ", Дата рождения: " << d << "/" << m << "/" << y << '\n';
    }
};

int main() {
    std::ifstream in("4.dat");
    if (!in) {
        std::cerr << "Ошибка открытия файла '4.dat'!" << std::endl;
        return 0;
    }

    std::vector<Znak> people;
    while (true) {
        Znak person;
        if (!person07.readFromFile(in)) {
            break;
        }
        people.push_back(person);
    }

    for (auto &person : people) {
        if (!person.checkZodiac()) {
            person.print();
        }
    }


}
