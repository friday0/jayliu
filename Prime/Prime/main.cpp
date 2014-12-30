#include <iostream>
using namespace std;


void is_prime(int &number)
{
	cout<<"Prime:";

	for(int i = 2; i < number; ++i)
	{
		bool is_prime = true;
		for(int j = 2; j * j < i; ++j)
		{
			if(i % j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime)
			cout<<i<<",";
	}
}

void main()
{
	int number = 0;
	while(number <= 0)
	{
		cout<<"Input positive number:";
		cin>>number;
		if(number <= 0)
			cout<<"Wrong Number!"<<endl;
	}

	is_prime(number);
}
