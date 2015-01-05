#include <iostream>
using namespace std;


void IsPrime(int iNumber)
{
	cout<<"Prime:";

	for(int i = 2; i < iNumber; ++i)
	{
		bool IsPrime = true;
		for(int j = 2; j * j < i; ++j)
		{
			if(i % j == 0)
			{
				IsPrime = false;
				break;
			}
		}
		if(IsPrime)
			cout<<i<<",";
	}
}

void main()
{
	int iNumber = 0;
	while(iNumber <= 0)
	{
		cout<<"Input positive iNumber:";
		cin>>iNumber;
		if(iNumber <= 0)
			cout<<"Wrong iNumber!"<<endl;
	}

	IsPrime(iNumber);
}
