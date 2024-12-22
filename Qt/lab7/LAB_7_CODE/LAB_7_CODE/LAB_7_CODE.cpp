#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <locale>
#include <codecvt>

template <typename T>
class Array {
private:
    std::vector<T> arr;

public:
    // Конструктор
    Array(int size) {
        arr.resize(size);
        std::cout << "Введите " << size << " элементов массива:\n";
        for (int i = 0; i < size; ++i) {
            std::cin >> arr[i];
        }
    }

    // Деструктор
    ~Array() {
        // Очистка ресурсов
    }

    // Метод просмотра значений массива
    void display() const {
        std::cout << "Элементы массива: ";
        for (const auto& el : arr) {
            std::cout << el << " ";
        }
        std::cout << '\n';
    }

    // Метод для решения задачи
    void solve() const {
        if constexpr (std::is_same_v<T, int>) {
            int minElement = *std::min_element(arr.begin(), arr.end());
            std::cout << "Элементы после минимального элемента (" << minElement << "): ";
            auto it = std::find(arr.begin(), arr.end(), minElement);
            for (++it; it != arr.end(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << '\n';
        }
        else if constexpr (std::is_same_v<T, double>) {
            double average = std::accumulate(arr.begin(), arr.end(), 0.0) / arr.size();
            std::cout << "Среднее значение элементов массива: " << average << '\n';
        }
        else if constexpr (std::is_same_v<T, char>) {
            auto minIt = std::min_element(arr.begin(), arr.end());
            auto maxIt = std::max_element(arr.begin(), arr.end());
            std::cout << "Элементы между минимальным (" << *minIt << ") и максимальным (" << *maxIt << ") символом ASCII: ";
            for (const auto& el : arr) {
                if (el > *minIt && el < *maxIt) {
                    std::cout << el << " ";
                }
            }
            std::cout << '\n';
        }
    }
};

int main() {
    // Установка локали
    setlocale(LC_ALL, "Russian");

    int choice;
    std::cout << "Выберите тип массива:\n1. int\n2. double\n3. char\n";
    std::cin >> choice;

    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    switch (choice) {
    case 1: {
        Array<int> intArray(size);
        intArray.display();
        intArray.solve();
        break;
    }
    case 2: {
        Array<double> doubleArray(size);
        doubleArray.display();
        doubleArray.solve();
        break;
    }
    case 3: {
        Array<char> charArray(size);
        charArray.display();
        charArray.solve();
        break;
    }
    default:
        std::cout << "Неверный выбор.\n";
    }

    return 0;
}