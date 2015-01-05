#include <iostream>
using namespace std;

#define NUMBER 10
#define LENGTH 32

int Compare(const void *pvA, const void *pvB)
{
	return strcmp((char *)pvA, (char *)pvB);
}

void main()
{
	char acName[NUMBER][LENGTH];
	memset(acName, 0x0, NUMBER * LENGTH);

	cout<<"Input 10 names:";
	for(int i = 0; i < NUMBER; ++i)
		cin>>acName[i];

	qsort(acName[0], NUMBER, LENGTH, Compare);

	cout<<"Sorted acName:"<<endl;
	for(int i = 0; i < NUMBER; ++i)
		cout<<acName[i]<<endl;
	 
	
	system("PAUSE");
}