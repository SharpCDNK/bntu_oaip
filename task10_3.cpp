#include <iostream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc != 3 && argc != 4) {
        std::cerr << "Использование:\n"
                  << argv[0] << " <символ> <количество>\n"
                  << "ИЛИ\n"
                  << argv[0] << " <символ> <начальная позиция> <конечная позиция>\n";
        return 1;
    }

    std::string symbol = argv[1];
    int count = 0;
    if (argc == 3) {
        count = std::atoi(argv[2]);
    } else {
        int start = std::atoi(argv[2]);
        int end = std::atoi(argv[3]);
        count = end - start + 1;
    }

    for (int i = 0; i < count; i++) {
        std::cout << symbol;
    }
    std::cout <<'\n';
}
