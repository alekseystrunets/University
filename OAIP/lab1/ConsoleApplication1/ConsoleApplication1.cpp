#include <iostream>
#include <cmath>
#include <Windows.h>
//using namespace std;
int main() {
	setlocale(LC_ALL, "RUS");
	double y, x, z, s;
	double h, g, k;
	std::cout << "Введите данные значения y,x,z" << std::endl;
	if (std::cin >> y) {
		std::cout << "y=" << y << std::endl;
		
	}
	else {
		std::cout << "Ошибка" << std::endl;
		return -1;
	}
	
	if (std::cin >> x )
		std::cout << "x=" << x << std::endl;
	else
		std::cout << "Ошибка" << std::endl;

	if (std::cin >> z)
		std::cout << "z=" << z << std::endl;
	else
		std::cout << "Ошибка" << std::endl;
	if (x != -y)
		 s = (x + y / 2) / (2 * fabs(x + y));

	else
		std::cout << "Ошибка, знаменатель не может быть равен нулю " << std::endl;

	if (sin(z) != 0)
		 h = pow((x + 1), (-1./ sin(z)));
	else 
		std::cout << "Ошибка ,знаменатель в показатели степени не может быть равен нулю" << std::endl;

       k = (pow((y), (x + 1))) / (pow(fabs(y - 2), (1./ 3)) + 3);
	
	g = k + s*h;

	std::cout << "g=" << g << std::endl;

	

	




	


}