#include <iostream>
using namespace std;

bool ToUpper(char *pcVar)
{
	if(*pcVar >= 97 && *pcVar <= 122)
	{
		*pcVar -= 32;
		return true;
	}
	else if(*pcVar >= 65 && *pcVar <= 90)
	{
		return true;
	}
	return false;
}

void main()
{
	char cVar;
	cout<<"Input a character:";
	cin>>cVar;

	if(ToUpper(&cVar))
		cout<<"Capital:"<<cVar<<endl;
	else
		cout<<"It's not a alphabet:"<<cVar<<endl;
}
