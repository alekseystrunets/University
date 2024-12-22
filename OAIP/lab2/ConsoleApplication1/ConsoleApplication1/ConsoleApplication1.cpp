// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
using namespace std;
int main()

{
	double x, y, f, a, s;
	int k;
	cout << "Vvedite x "; cin >> x;
	cout << "Vvedite y "; cin >> y;
	cout << "Viberite f: 1 - sh(x), 2 - x^2, 3 - exp(x) "; cin >> k;
	switch (k)
	{
	case 1: f = sinh(x); break;
	case 2: f = pow(x, 2); break;
	case 3: f = exp(x); break;
	default: cout << "Ne vuibrana funkciya "; return 1;
	}
	a = x * y;
	if (a < 0.1) {
		cout << "Net rezultata" << endl;
		return 1;
	}
	else
		if (a < 0.5 && a > 0.1) s = pow(fabs(f + y), 1. / 3.);
		else
			if (a <= 10 && a > 5) s = exp(f + y);
			else s = 2 * pow(f, 2);
	cout << "RESULT = " << s << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
