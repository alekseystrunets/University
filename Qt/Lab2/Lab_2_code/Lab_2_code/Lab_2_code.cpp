#include <iostream>

class Hotel {
private:
    int* rooms_on_the_floor; 
    int* total_rooms;        
    int* price;              
    int* tenants;            

public:
   
    Hotel(int rooms_per_floor, int total, int room_price, int num_tenants);

    Hotel();

    ~Hotel();

    void set(int rooms_per_floor, int total, int room_price, int num_tenants);

    void viewCurrentState(int profit) const;

    void calculateFloorsAndLastFloorRooms() const;

    int calculateProfit() const;
};

Hotel::Hotel(int rooms_per_floor, int total, int room_price, int num_tenants) {
    rooms_on_the_floor = new int(rooms_per_floor);
    total_rooms = new int(total);
    price = new int(room_price);
    tenants = new int(num_tenants);
}

Hotel::Hotel() {
    rooms_on_the_floor = new int(0);
    total_rooms = new int(0);
    price = new int(0);
    tenants = new int(0);
}

Hotel::~Hotel() {
    delete rooms_on_the_floor;
    delete total_rooms;
    delete price;
    delete tenants;
}

void Hotel::set(int rooms_per_floor, int total, int room_price, int num_tenants) {
    *rooms_on_the_floor = rooms_per_floor;
    *total_rooms = total;
    *price = room_price;
    *tenants = num_tenants;
}

void Hotel::viewCurrentState(int profit) const {
    std::cout << "Текущее состояние отеля: " << std::endl;
    std::cout << "Количество комнат на этаже: " << *rooms_on_the_floor << std::endl;
    std::cout << "Общее количество комнат: " << *total_rooms << std::endl;
    std::cout << "Цена за одну комнату: " << *price << std::endl;
    std::cout << "Количество жильцов: " << *tenants << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << "Прибыль отеля: " << profit << " $." << std::endl;
}

void Hotel::calculateFloorsAndLastFloorRooms() const {
    int floors = *total_rooms / *rooms_on_the_floor;
    int last_floor_rooms = *total_rooms % *rooms_on_the_floor;

    std::cout << "Количество этажей в отеле: "
        << (last_floor_rooms > 0 ? floors + 1 : floors) << std::endl;
    std::cout << "Количество комнат на последнем этаже: " << last_floor_rooms << std::endl;
}

int Hotel::calculateProfit() const {
    return *price * *tenants;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int profit;
    Hotel myHotel;

    myHotel.set(3, 9, 100, 9); 

    profit = myHotel.calculateProfit();

    myHotel.viewCurrentState(profit);

    myHotel.calculateFloorsAndLastFloorRooms();

    Hotel* m_myHotel = &myHotel;
    m_myHotel->viewCurrentState(profit);

    return 0;
}
