#include <iostream>
using namespace std;

bool to_upper(char &var)
{
	if(var >= 97 && var <= 122)
	{
		var -= 32;
		return true;
	}
	else if(var >= 65 && var <= 90)
	{
		return true;
	}
	return false;
}

bool main()
{
	char var;
	cout<<"Input a character:";
	cin>>var;

	if(to_upper(var))
		cout<<"Capital:"<<var<<endl;
	else
		cout<<"It's not a alphabet:"<<var<<endl;
}
