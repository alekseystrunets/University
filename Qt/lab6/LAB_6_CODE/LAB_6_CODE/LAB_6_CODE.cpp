#include <iostream>
#include <string>

class Room {
protected:
    double cost;
    int number_of_residents;
    int convenience;

public:
    Room(double c, int n, int conv) : cost(c), number_of_residents(n), convenience(conv) {}

    virtual void print_info() const {
        std::cout << "Cost: " << cost << ", Number of Residents: " << number_of_residents
            << ", Convenience Level: " << convenience << std::endl;
    }

    virtual double how_much_is_days() const = 0; // Чисто виртуальная функция
};


class StandardRoom : public Room {
public:
    StandardRoom(double c, int n, int conv) : Room(c, n, conv) {}

    void print_info() const override {
        std::cout << "Standard Room - ";
        Room::print_info();
    }

    double how_much_is_days() const override {
        return cost * 3; // Для стандартного номера
    }
};


class ComfortRoom : public Room {
public:
    ComfortRoom(double c, int n, int conv) : Room(c, n, conv) {}

    void print_info() const override {
        std::cout << "Comfort Room - ";
        Room::print_info();
    }

    double how_much_is_days() const override {
        if (convenience > 3 && convenience < 5) {
            return cost * 3 + 0.15 * number_of_residents * cost;
        }
        return cost * 3; // Если convenience <= 3 или convenience >= 5
    }
};


class LuxuryRoom : public Room {
public:
    LuxuryRoom(double c, int n, int conv) : Room(c, n, conv) {}

    void print_info() const override {
        std::cout << "Luxury Room - ";
        Room::print_info();
    }

    double how_much_is_days() const override {
        if (convenience > 3 && convenience < 5) {
            return cost * 3 + 0.15 * number_of_residents * cost;
        }
        return cost * 3; // Если convenience <= 3 или convenience >= 5
    }
};


int main() {
    Room* rooms[3];

    // Создаем комнаты
    rooms[0] = new StandardRoom(100.0, 2, 2);
    rooms[1] = new ComfortRoom(150.0, 3, 4);
    rooms[2] = new LuxuryRoom(200.0, 2, 5);

    // Вывод информации о комнатах
    for (int i = 0; i < 3; ++i) {
        rooms[i]->print_info();
        std::cout << "Price for 3 days: " << rooms[i]->how_much_is_days() << std::endl;
    }

    // Освобождаем память
    for (int i = 0; i < 3; ++i) {
        delete rooms[i];
    }

    return 0;
}