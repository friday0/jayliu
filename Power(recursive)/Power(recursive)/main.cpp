#include<iostream>
using namespace std;

double Power(double dBase, double dExponent)
{
	if(dExponent == 1)
		return dBase * dExponent;

	return Power(dBase, dExponent - 1) * dBase;
}

void main()
{
	double dBase = 0, dExponent = 0;
	cout<<"Input dBase:";
	cin>>dBase;
	cout<<"Input dExponent:";
	cin>>dExponent;
	cout<<(int)Power(dBase, dExponent)<<endl;
}