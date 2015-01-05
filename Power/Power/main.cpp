#include<iostream>
using namespace std;

int Power(double *pdBase, double *pdExponent)
{
	double dValue = 1;
	for(int i = 1; i <= *pdExponent; ++i)
	{
		dValue *= *pdBase;
	}
	return (int) dValue;
}

void main()
{
	double dBase = 0, dExponent = 0;
	cout<<"Input dBase:";
	cin>>dBase;
	cout<<"Input dExponent:";
	cin>>dExponent;
	cout<<Power(&dBase, &dExponent)<<endl;
}