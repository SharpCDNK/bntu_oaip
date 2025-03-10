#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>


enum Unit { PIECE, KG, PACKAGE };
enum ContainerType { WHITE, BLUE, RED };


std::string inline containerType(ContainerType container) {
    return container == WHITE ? "White" : container == BLUE ? "Blue" : "Red";
}


class Product {

    int             id;
    std::string     name;
    Unit            unit;
    double          price;

public:

    Product(int id = 0, std::string name = "", Unit unit = PIECE, double price = 0.0) : id(id), name(name), unit(unit), price(price) {}


    int getId() const {
        return id;
    }


    void display() const {
        std::cout << "Product ID: " << id << ", Name: " << name
                  << ", Unit: " << (unit == KG ? "Kg" : unit == PACKAGE ? "Package" : "Piece")
                  << ", Price: " << price << '\n';
    }
};


class WareHouse {

    int             storage;
    int             shelf;
    ContainerType   container;

public:

    WareHouse(int storage = 0, int shelf = 0, ContainerType container = WHITE) : storage(storage), shelf(shelf), container(container) {}


    void display() const {
        std::cout << "Storage id: " << storage << ", Shelf id: " << shelf
                  << ", Container type: " << containerType(container) << '\n';
    }
};


class Order {
private:
    int num_order;
    std::string surname;
    std::string date;

public:
    Order(int num_order = 1, std::string surname = "NoSurname", std::string date = "NoDate") : num_order(num_order), surname(surname), date(date) {}

    void display() const {
        std::cout << "Num of order: " << num_order << ", Surname: " << surname << ", Date: " << date << '\n';
    }
};

class Item {
private:
    Product product;
    WareHouse warehouse;
    Order order;

public:
    Item(const Product& product, const WareHouse& warehouse, const Order& order) : product(product), warehouse(warehouse), order(order) {}

    int getProductId() const {
        return product.getId();
    }

    void display() const {
        product.display();
        warehouse.display();
        order.display();
        std::cout << "------------------------------\n";
    }
};

int main() {
    std::vector<Item> ar;
    ar.reserve(5);
    while (true) {
        system("clear");
        std::cout << "Действия:\n";
        std::cout << "1) Добавить элемент в массив\n";
        std::cout << "2) Посмотреть все элементы в массиве\n";
        std::cout << "3) Удалить элемент из массива\n";
        std::cout << "4) Выйти\n";
        std::string action;
        std::cin >> action;

        if (action == "1") {
            if(ar.capacity() == ar.size()){
                std::cout << "Массив заполнен, надо освободить место.";
                continue;
            }
            std::cout << "Ввод данных: \n";
            int id;
            std::string name;
            int unitChoice;
            double price;

            std::cout << "Введите ID продукта: ";
            std::cin >> id;

            std::cout << "Введите имя продукта: ";
            std::cin.ignore(); // Очистить буфер ввода
            std::getline(std::cin, name);

            std::cout << "Введите единицу измерения (0 - Штука, 1 - Кг, 2 - Упаковка): ";
            std::cin >> unitChoice;

            std::cout << "Введите цену: ";
            std::cin >> price;

            Product product(id, name, static_cast<Unit>(unitChoice), price);

            int storage, shelf;
            int containerChoice;

            std::cout << "Введите номер склада: ";
            std::cin >> storage;

            std::cout << "Введите номер стеллажа: ";
            std::cin >> shelf;

            std::cout << "Введите тип контейнера (0 - Белый, 1 - Синий, 2 - Красный): ";
            std::cin >> containerChoice;

            WareHouse warehouse(storage, shelf, static_cast<ContainerType>(containerChoice));

            int num_order;
            std::string surname, date;

            std::cout << "Введите номер заказа: ";
            std::cin >> num_order;

            std::cout << "Введите фамилию клиента: ";
            std::cin.ignore();
            std::getline(std::cin, surname);

            std::cout << "Введите дату заказа: ";
            std::getline(std::cin, date);

            Order order(num_order, surname, date);

            Item input(product, warehouse, order);
            ar.emplace_back(input);

        } else if (action == "2") {
            if (ar.empty()) {
                std::cout << "Массив пуст.\n";
            } else {
                for (const auto& i : ar) {
                    i.display();
                }
            }
        } else if (action == "3") {
            int deleteId;
            std::cout << "Введите ID продукта, который нужно удалить: ";
            std::cin >> deleteId;

            auto it = std::find_if(ar.begin(), ar.end(), [deleteId](const Item& item) {
                return item.getProductId() == deleteId;
            });

            if (it != ar.end()) {
                ar.erase(it);
                std::cout << "Элемент с ID " << deleteId << " удалён.\n";
            } else {
                std::cout << "Элемент с таким ID не найден.\n";
            }

        } else if (action == "4") {
            return 0;
        }
    }
}





/*
 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

enum Unit { PIECE, KG, PACKAGE };
enum ContainerType { WHITE, BLUE, RED };
enum ItemType { IN_STOCK, IN_WAREHOUSE, BY_ORDER };

std::string inline getUnitName(Unit unit) {
    return unit == KG ? "Kg" : unit == PACKAGE ? "Package" : "Piece";
}

std::string inline getContainerName(ContainerType container) {
    return container == WHITE ? "White" : container == BLUE ? "Blue" : "Red";
}

struct InStock {
    int id;
    std::string name;
    Unit unit;
    double price;
};

struct InWarehouse {
    int storage;
    int shelf;
    ContainerType container;
};

struct ByOrder {
    int orderNumber;
    std::string customerSurname;
    std::string date;
};

struct Item {
    ItemType type;
    union {
        InStock inStock;
        InWarehouse inWarehouse;
        ByOrder byOrder;
    };

    Item() {}


    Item(const InStock& stock) : type(IN_STOCK) {
        inStock = stock;
    }


    Item(const InWarehouse& warehouse) : type(IN_WAREHOUSE) {
        inWarehouse = warehouse;
    }


    Item(const ByOrder& order) : type(BY_ORDER) {
        byOrder = order;
    }

    void display() const {
        switch (type) {
            case IN_STOCK:
                std::cout << "In Stock: ID = " << inStock.id
                          << ", Name = " << inStock.name
                          << ", Unit = " << getUnitName(inStock.unit)
                          << ", Price = " << inStock.price << '\n';
                break;
            case IN_WAREHOUSE:
                std::cout << "In Warehouse: Storage = " << inWarehouse.storage
                          << ", Shelf = " << inWarehouse.shelf
                          << ", Container = " << getContainerName(inWarehouse.container) << '\n';
                break;
            case BY_ORDER:
                std::cout << "By Order: Order Number = " << byOrder.orderNumber
                          << ", Customer = " << byOrder.customerSurname
                          << ", Date = " << byOrder.date << '\n';
                break;
        }
        std::cout << "------------------------------\n";
    }
};

int main() {
    std::vector<Item> items;
    items.reserve(5);

    while (true) {
        system("clear");
        std::cout << "Действия:\n";
        std::cout << "1) Добавить элемент в массив\n";
        std::cout << "2) Посмотреть все элементы в массиве\n";
        std::cout << "3) Удалить элемент из массива\n";
        std::cout << "4) Выйти\n";
        std::string action;
        std::cin >> action;

        if (action == "1") {
            if (items.size() == 5) {
                std::cout << "Массив заполнен, надо освободить место.\n";
                continue;
            }

            std::cout << "Выберите тип записи (0 - В наличии, 1 - На складе, 2 - Под заказ): ";
            int typeChoice;
            std::cin >> typeChoice;

            if (typeChoice == 0) {
                int id;
                std::string name;
                int unitChoice;
                double price;

                std::cout << "Введите ID продукта: ";
                std::cin >> id;

                std::cout << "Введите имя продукта: ";
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cout << "Введите единицу измерения (0 - Штука, 1 - Кг, 2 - Упаковка): ";
                std::cin >> unitChoice;

                std::cout << "Введите цену: ";
                std::cin >> price;

                InStock stock = {id, name, static_cast<Unit>(unitChoice), price};
                items.emplace_back(stock);

            } else if (typeChoice == 1) {
                int storage, shelf, containerChoice;

                std::cout << "Введите номер склада: ";
                std::cin >> storage;

                std::cout << "Введите номер стеллажа: ";
                std::cin >> shelf;

                std::cout << "Введите тип контейнера (0 - Белый, 1 - Синий, 2 - Красный): ";
                std::cin >> containerChoice;

                InWarehouse warehouse = {storage, shelf, static_cast<ContainerType>(containerChoice)};
                items.emplace_back(warehouse);

            } else if (typeChoice == 2) {
                int orderNumber;
                std::string customerSurname, date;

                std::cout << "Введите номер заказа: ";
                std::cin >> orderNumber;

                std::cout << "Введите фамилию клиента: ";
                std::cin.ignore();
                std::getline(std::cin, customerSurname);

                std::cout << "Введите дату заказа: ";
                std::getline(std::cin, date);

                ByOrder order = {orderNumber, customerSurname, date};
                items.emplace_back(order);
            }

        } else if (action == "2") {
            if (items.empty()) {
                std::cout << "Массив пуст.\n";
            } else {
                for (const auto& item : items) {
                    item.display();
                }
            }

        } else if (action == "3") {
            int deleteId;
            std::cout << "Введите ID продукта для удаления (работает только для записей 'В наличии'): ";
            std::cin >> deleteId;

            auto it = std::find_if(items.begin(), items.end(), [deleteId](const Item& item) {
                return item.type == IN_STOCK && item.inStock.id == deleteId;
            });

            if (it != items.end()) {
                items.erase(it);
                std::cout << "Элемент с ID " << deleteId << " удалён.\n";
            } else {
                std::cout << "Элемент с таким ID не найден.\n";
            }

        } else if (action == "4") {
            return 0;
        }
    }
}

 */