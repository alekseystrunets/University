#include <stdexcept>

class Surprise {
private:
    double number1;
    double number2;

public:
    void setNumbers(double num1, double num2) {
        number1 = num1;
        number2 = num2;
    }

    double check() {
        if (number1 - number2 == 0) {
            throw std::runtime_error("Ошибка: деление на ноль.");
        }
        return (number1 + number2) / (number1 - number2);
    }
};
