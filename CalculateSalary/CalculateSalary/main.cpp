#include <iostream>
using namespace std;

#define BASIC_SALARY 10
#define EXTRA_SALARY (BASIC_SALARY * 1.5)
#define	BASIC_WORKING_HOUR 40

#define SALARY_LEVEL_1 300
#define SALARY_LEVEL_2 450

#define TAX_LEVEL_1 0.15f
#define TAX_LEVEL_2 0.20f
#define TAX_LEVEL_3 0.50f


void main()
{
	int working_hour = 0;
	double salary = 0, tax = 0;
	cout<<"Input your working hour per week:";
	cin>>working_hour;
	
	if(working_hour <= BASIC_WORKING_HOUR)
		salary = working_hour * BASIC_SALARY;
	else
		salary = BASIC_WORKING_HOUR * BASIC_SALARY + (working_hour - BASIC_WORKING_HOUR) * EXTRA_SALARY;

	if(salary <= SALARY_LEVEL_1)
		tax = salary * TAX_LEVEL_1;
	else if (salary > SALARY_LEVEL_1 && salary <= SALARY_LEVEL_2)
		tax = salary * TAX_LEVEL_2;
	else
		tax = salary * TAX_LEVEL_3;

	cout<<"Salary per week:"<<salary<<endl;
	cout<<"Tax:"<<tax<<endl;
	cout<<"Salary after tax:"<<salary - tax<<endl;
}
