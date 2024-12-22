#include <iostream>

using namespace std;

int main()
{
    char **matrix, *array;
    int i, j, n, m, k, length;
    //char valid[] = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    //const int l = 62;

    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;

    // динамически создаем массив указателей размера n
    matrix = new char* [n];

    // динамически выделяем память размером m для каждой строки
    for (i = 0; i < n; i++) 
        matrix[i] = new char[m];

    // динамически выделяем память размером n*m для одномерного массива
    length = n * m;
    array = new char [length];

    // присваиваем значения выделенной памяти для двумерного массива
    cout << "Enter the matrix elements: ";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> matrix[i][j];
            //matrix[i][j] = valid[rand() % l];

    // печатаем двумерный массив и присваиваем значения одномерному массиву
    cout << "\nMatrix:\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";

            array[i*m+j] = matrix[i][j];
        }
        cout << endl;
    }

    // определяем количество различных элементов массива
    //for (i = 0; i < length; i++) 
    //    for (j = i + 1; j < length; j++) 
    //        if (array[i] == array[j]) {
    //            for (k = j; k < length - 1; k++) // перемещаем конец массива влево
    //                array[k] = array[k + 1]; // вырезаем значение из массива

    //            j--;
    //            length--; // урезаем длину массива
    //        }

    //cout << "\nCount: " << length << endl; // длина массива = количество неповторяющихся элементов

    int count = 1;

    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (array[i] == array[j])
                break;
        }

        if (j == length)
            count++;
    }

    cout << "\nCount: " << count << endl;

    // освобождаем память с помощью оператора удаления
    delete[] array;

    for (i = 0; i < n; i++) 
        delete[] matrix[i];
    
    delete[] matrix;

    return 0;
}