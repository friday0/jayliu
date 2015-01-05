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
	int iWorkingHour = 0;
	double dSalary = 0, dTax = 0;
	cout<<"Input your working hour per week:";
	cin>>iWorkingHour;
	
	if(iWorkingHour <= BASIC_WORKING_HOUR)
		dSalary = iWorkingHour * BASIC_SALARY;
	else
		dSalary = BASIC_WORKING_HOUR * BASIC_SALARY + (iWorkingHour - BASIC_WORKING_HOUR) * EXTRA_SALARY;

	if(dSalary <= SALARY_LEVEL_1)
		dTax = dSalary * TAX_LEVEL_1;
	else if (dSalary > SALARY_LEVEL_1 && dSalary <= SALARY_LEVEL_2)
		dTax = dSalary * TAX_LEVEL_2;
	else
		dTax = dSalary * TAX_LEVEL_3;

	cout<<"dSalary per week:"<<dSalary<<endl;
	cout<<"dTax:"<<dTax<<endl;
	cout<<"dSalary after dTax:"<<dSalary - dTax<<endl;
}
