#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите k - количество элементов массива: ";
    cin >> size;

    int* arr = { new int[size] };

    for (int i = 0; i < size; i++) {
        cout << "Введите " << i + 1 << " элемент массива: ";
        cin >> arr[i];
    }

    cout << "Массив до сдвига: " << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << " ]" << endl;

    int offset;
    cout << "Введите n-сдвиг: ";
    cin >> offset;

    int* offset_arr = { new int[offset] };

    for (int i = 0; i < offset; i++) {
        offset_arr[i] = arr[i];
    }

    for (int i = 0; i < size - offset; i++) {
        arr[i] = arr[i + offset];
    }

    for (int i = offset; i >= 0; --i) {
        arr[size - i] = offset_arr[offset - i];
    }

    cout << "Массив после сдвига на n позиций влево циклически: " << "[ ";
    for (int i = 0; i < size - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1];
    cout << " ]";
    delete[] arr;
    delete[] offset_arr;
    return 0;
}
