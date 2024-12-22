#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype> // Для std::isalnum и std::tolower

class MyString {
private:
    std::string str;

public:
    MyString() : str("") {}
    MyString(const std::string& s) : str(s) {}

    // Метод для вывода содержимого строки
    void display() const {
        std::cout << str;
    }

    // Перегрузка оператора "="
    MyString& operator=(const std::string& s) {
        str = s;
        return *this;
    }

    // Получение строки
    const std::string& getString() const {
        return str;
    }
};

class Palindrome {
private:
    std::string text;

public:
    Palindrome() : text("") {}
    Palindrome(const std::string& s) : text(s) {}

    // Метод для просмотра содержимого поля
    void display() const {
        if (text.empty()) {
            std::cout << "Палиндромы не найдены." << std::endl;
        }
        else {
            std::cout << text << std::endl;
        }
    }

    // Перегрузка оператора "=" для выбора палиндромов
    Palindrome& operator=(const std::string& s) {
        std::istringstream stream(s);
        std::string word;
        std::string result;

        while (stream >> word) {
            // Удаляем все символы, кроме букв и цифр, и приводим к нижнему регистру
            std::string cleaned;
            for (char c : word) {
                if (std::isalnum(c)) {
                    cleaned += std::tolower(c);
                }
            }

            // Проверяем, является ли слово палиндромом
            std::string reversed = cleaned;
            std::reverse(reversed.begin(), reversed.end());

            // Отладка: выводим очищенное слово и его реверс
            std::cout << "Слово: " << cleaned << ", Реверс: " << reversed << std::endl;

            if (cleaned == reversed && !cleaned.empty()) {
                result += word + " ";
            }
        }

        text = result;
        return *this;
    }

    // Получение текста
    const std::string& getText() const {
        return text;
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    MyString myString;
    std::string input;

    // Ввод строки от пользователя
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    myString = input;  // Используем перегруженный оператор "="

    Palindrome palindrome;
    palindrome = input;  // Перегрузка оператора "=" для проверки палиндромов

    std::cout << "Палиндромы в строке: ";
    palindrome.display();  // Выводим найденные палиндромы

    return 0;
}