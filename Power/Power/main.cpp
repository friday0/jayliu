#include<iostream>
using namespace std;

int power(double &base, double &exponent)
{
	double value = 1;
	for(int i = 1; i <= exponent; ++i)
	{
		value *= base;
	}
	return (int) value;
}

void main()
{
	double base = 0, exponent = 0;
	cout<<"Input base:";
	cin>>base;
	cout<<"Input exponent:";
	cin>>exponent;
	cout<<power(base, exponent)<<endl;
}