#include <iostream>
using namespace std;

#define NUMBER 4
#define LENGTH 32

int compare(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

void main()
{
	char name[NUMBER][LENGTH];
	memset(name, 0x0, NUMBER * LENGTH);

	cout<<"Input 10 names:";
	for(int i = 0; i < NUMBER; ++i)
		cin>>name[i];

	qsort(name[0], NUMBER, LENGTH, compare);

	cout<<"Sorted name:"<<endl;
	for(int i = 0; i < NUMBER; ++i)
		cout<<name[i]<<endl;
	 
	
	system("PAUSE");
}