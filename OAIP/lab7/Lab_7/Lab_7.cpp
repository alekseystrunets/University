#include <iostream>

using namespace std;

//Declaring the structure
struct Employee 
{
	char fio[40];
	char id[5];
	int hm_count;
	double h_rate;
	double salary = 0.0;
} empl[10];

//Declare and initialize constants
const int hours{ 144 };
const double income_tax{ 0.12 };

int main()
{
	//Data for example
	//{ "Kovalev Alexandr Vladimirovich", "2310", 156, 12.7, 0.0};
	//{ "Eliseeva Mariya Viktorovna", "2315", 144, 11.5, 0.0};
	//{ "Kotov Pavel Sergeevich", "2320", 162, 11.2, 0.0};
	//{ "Pikova Darya Vasilyevna", "2302", 130, 20.4, 0.0};

	int n_empl, i, j;

	//Enter the number of employees
	cout << "Enter the number of employees: " << endl;
	cin >> n_empl;
	
	//Enter data for each employee
	for (i = 0; i < n_empl; i++) {
		cout << "\nEmployee #" << i + 1 << endl;

		cout << "Enter the employee's FIO: " << endl;
		cin >> empl[i].fio;

		cout << "Enter the employee's service number: " << endl;
		cin >> empl[i].id;

		cout << "Enter the number of hours worked per month: " << endl;
		cin >> empl[i].hm_count;
		
		cout << "Enter the hourly rate: " << endl;
		cin >> empl[i].h_rate;

		//Сalculate the employee's salary including overtime
		if (empl[i].hm_count > hours) {
			int overtime = empl[i].hm_count - hours;
			double dirty_salary = hours * empl[i].h_rate + overtime * empl[i].h_rate * 2;

			empl[i].salary = dirty_salary - dirty_salary * income_tax;
		}
		else {
			double dirty_salary = empl[i].hm_count * empl[i].h_rate;

			empl[i].salary = dirty_salary - dirty_salary * income_tax;
		}
	}

	cout << endl;

	//Displaying information about employees
	for (i = 0; i < n_empl; i++)
		cout << empl[i].fio << " | " << empl[i].id << " | "
			<< empl[i].hm_count << " | " << empl[i].h_rate << " | "
			<< empl[i].salary << endl;

	return 0;
}
