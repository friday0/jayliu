#include<iostream>
using namespace std;

double power(double base, double exponent)
{
	if(exponent == 1)
		return base * exponent;

	return power(base, exponent - 1) * base;
}

void main()
{
	double base = 0, exponent = 0;
	cout<<"Input base:";
	cin>>base;
	cout<<"Input exponent:";
	cin>>exponent;
	cout<<(int)power(base, exponent)<<endl;
}