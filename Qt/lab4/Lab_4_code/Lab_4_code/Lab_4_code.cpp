#include <iostream>
#include <cstdlib>
#include <ctime>

class Restaurant {
private:
    int** tables; // Динамический двумерный массив
    int rows;     // Количество строк
    int cols;     // Количество столбцов

public:
    
    Restaurant(int r, int c) : rows(r), cols(c) {
        // Создание двумерного массива
        tables = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            tables[i] = new int[cols];
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr))); 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                tables[i][j] = std::rand() % 11 - 5; // Генерация значений от -5 до 5
            }
        }
    }

    ~Restaurant() {
        for (int i = 0; i < rows; ++i) {
            delete[] tables[i]; 
        }
        delete[] tables; 
    }

    // Дружественная функция для вывода состояния массива
    friend void displayState(const Restaurant& restaurant) {
        for (int i = 0; i < restaurant.rows; ++i) {
            for (int j = 0; j < restaurant.cols; ++j) {
                std::cout << restaurant.tables[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Дружественная функция для установки нового значения элемента
    friend void setTableValue(Restaurant& restaurant, int row, int col, int value) {
        if (row >= 0 && row < restaurant.rows && col >= 0 && col < restaurant.cols) {
            restaurant.tables[row][col] = value;
        }
    }

    // Функция для подсчета свободных столов
    int countAvailableTables() const {
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (tables[i][j] <= 0) { // Если стол свободен или забронирован
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    Restaurant restaurant(5, 5); 

    // Вывод текущего состояния массива
    std::cout << "Current state of the restaurant:\n";
    displayState(restaurant);

    // Подсчет доступных столов
    int availableTables = restaurant.countAvailableTables();
    std::cout << "Available tables for tourists: " << availableTables << std::endl;

    // Установка нового значения для столика
    setTableValue(restaurant, 2, 2, 1); // Устанавливаем значение 1 для столика (например, занят)
    std::cout << "Updated state of the restaurant:\n";
    displayState(restaurant);

    return 0;
}