#include<iostream>
using namespace std;

#define BUFFER_SIZE 20

void CopyByArray(int aiBuff[], int aiNewBuff [])
{
	for(int i = 0; i < BUFFER_SIZE; ++i)
		aiNewBuff[i] = aiBuff[i];
}

void CopyByPointer(int aiBuff[], int *piPtr)
{
	for(int i = 0; i < BUFFER_SIZE; ++i)
		*piPtr++ = aiBuff[i];
}

void main()
{
	int aiBuffer[BUFFER_SIZE];
	for(int i = 0; i < BUFFER_SIZE; ++i)
		aiBuffer[i] = i;

	int aiNewBuffer1[BUFFER_SIZE] = {0};
	int aiNewBuffer2[BUFFER_SIZE] = {0};

	CopyByArray(aiBuffer, aiNewBuffer1);
	cout<<"CopyByArray():";
	for(int i = 0; i < BUFFER_SIZE; ++i)
		cout<<aiNewBuffer1[i]<<",";
	cout<<endl;

	cout<<"CopyByPointer():";
	CopyByPointer(aiBuffer, aiNewBuffer2);
	for(int i = 0; i < BUFFER_SIZE; ++i)
		cout<<aiNewBuffer2[i]<<",";
	cout<<endl;
}
