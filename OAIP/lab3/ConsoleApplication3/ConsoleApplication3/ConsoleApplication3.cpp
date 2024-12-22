#include <iostream>
#include <math.h>
using namespace std;
  int main() {
	double x, a = 0.1, b = 1., h = 0.09, y, s, r, m;
	int k, n ;
	cout << "Zadai n="; cin >> n;
	for (x = a; x <= b; x += h) {
		r = s = x;
		for (k = 1; k <= n; k++) //k степень
		{
			r = r * x * x / ((2 * k + 1) * 2 * k);
			s += r;;
		}
		y = (exp(x) - exp(-x)) / 2;
		m = fabs(y - s);
		cout << "chislo x= " << x << "  chislo y= " << y << " chislo m= " << m << "  chislo s= " << s << endl;

		//	return 0;


	}

}