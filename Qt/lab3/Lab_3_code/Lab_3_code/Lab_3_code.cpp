#include <iostream>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()
#include <vector>

class Room {
private:
    int price;              // Цена комнаты
    int number_of_residents; // Количество жильцов
    int number_of_beds;      // Количество кроватей

public:
    // Конструктор с параметрами
    Room(int room_price, int num_residents, int num_beds);

    // Метод для получения информации о комнате
    void printInfo() const;

    // Метод для проверки жильцов и выселения неплательщиков
    bool needsEviction() const;

    // Метод для получения цены
    int getPrice() const;

    // Метод для получения количества лишних жильцов
    int excessResidents() const;
};

// Определение методов класса Room
Room::Room(int room_price, int num_residents, int num_beds)
    : price(room_price), number_of_residents(num_residents), number_of_beds(num_beds) {}

void Room::printInfo() const {
    std::cout << "Цена комнаты: " << price
        << ", Количество жильцов: " << number_of_residents
        << ", Количество кроватей: " << number_of_beds << std::endl;
}

bool Room::needsEviction() const {
    return number_of_residents > number_of_beds; 
}

int Room::getPrice() const {
    return price; 
}

int Room::excessResidents() const {
    return number_of_residents - number_of_beds; 
}

class Hostel {
private:
    std::vector<Room> rooms;

public:
   
    Hostel(int size);

    
    void checkEvictions() const;

    
    void calculateAndDisplayProfit() const;
};


Hostel::Hostel(int size) {
    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    for (int i = 0; i < size; ++i) {
        int room_price = rand() % (8000 - 100 + 1) + 100; // Генерация цены от 100 до 8000
        int num_residents = rand() % 15; // Генерация жильцов от 0 до 14
        int num_beds = rand() % 10 + 1; // Генерация кроватей от 1 до 10

        rooms.emplace_back(room_price, num_residents, num_beds); // Создание объекта Room
    }
}

void Hostel::checkEvictions() const {
    std::cout << "Неплательщики:\n";
    for (const auto& room : rooms) {
        if (room.needsEviction()) {
            room.printInfo(); 
            int excess = room.excessResidents();
            std::cout << "Количество лишних жильцов: " << excess << std::endl; 
        }
    }
}

void Hostel::calculateAndDisplayProfit() const {
    int totalProfit = 0;
    for (const auto& room : rooms) {
        totalProfit += room.getPrice(); 
    }
    std::cout << "Общая прибыль от всех комнат: " << totalProfit << " $" << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    int size = 10; // Задаем количество комнат в хостеле
    Hostel myHostel(size); // Создание объекта Hostel

    myHostel.checkEvictions(); // Проверка на выселение неплательщиков
    myHostel.calculateAndDisplayProfit(); // Подсчет и вывод прибыли

    return 0;
}