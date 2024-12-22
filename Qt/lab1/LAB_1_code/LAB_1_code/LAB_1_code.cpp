#include <iostream>

class Hotel {
public:
    int  rooms_on_the_floor; // Количество комнат на этаже
    int total_rooms; // Общее количество комнат
    int price; // Цена за одну комнату
    int tenants; // Количество жильцов
    void viewCurrentState(int profit) const;
    // Конструктор
    void setValues(int rooms_per_floor, int total, int room_price, int num_tenants) {
        rooms_on_the_floor = rooms_per_floor;
        total_rooms = total;
        price = room_price;
        tenants = num_tenants;
    }

    // Метод для вычисления количества этажей и комнат на последнем этаже
    void calculateFloorsAndLastFloorRooms() const {
        int floors = total_rooms / rooms_on_the_floor;
        int last_floor_rooms = total_rooms % rooms_on_the_floor;

        std::cout << "Количество этажей в отеле: " << (last_floor_rooms > 0 ? floors + 1 : floors) << std::endl;
        std::cout << "Количество комнат на последнем этаже: " << last_floor_rooms << std::endl;
    }

    // Метод для вычисления прибыли отеля
    int calculateProfit() const {
        return price * tenants;
    }
};
void Hotel:: viewCurrentState(int profit) const {
    std::cout << "Текущее состояние отеля: " << std::endl;
    std::cout << "Количество комнат на этаже: " << rooms_on_the_floor << std::endl;
    std::cout << "Общее количество комнат: " << total_rooms << std::endl;
    std::cout << "Цена за одну комнату: " << price << std::endl;
    std::cout << "Количество жильцов: " << tenants << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Прибыль отеля: " << profit << " $." << std::endl;
}

int main() {

    setlocale(LC_ALL, "RUS");
    int profit;
    Hotel myHotel;

    // Установка начальных значений
    myHotel.setValues(3, 9, 100, 9); // 3 комнат на этаже, 9 всего, цена 100, 9 жильцов

    profit = myHotel.calculateProfit();

    // Просмотр текущего состояния отеля
    myHotel.viewCurrentState(profit);

    // Рассчет этажей и комнат на последнем этаже
    myHotel.calculateFloorsAndLastFloorRooms();

    Hotel *m_myHotel;
    m_myHotel = &myHotel;
    m_myHotel->viewCurrentState(profit);
    return 0;
}