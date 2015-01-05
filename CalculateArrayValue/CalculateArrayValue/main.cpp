#include <iostream>
using namespace std;

#define ROW 3
#define COLUMN 5

#define max(a,b) (a > b ? a : b)

void Input(double adBuff[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		cout<<"Set "<<i<<":Input 5 double(Split them by space):";
		for(int j = 0; j < COLUMN; j++)
			cin>>adBuff[i][j];
	}
}

void CalculateSetAverage(double adBuff[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		double dSum = 0;
		for(int j = 0; j < COLUMN; j++)
			dSum += adBuff[i][j];
		cout<<"Average of set "<<i<<" is:"<<dSum / COLUMN<<endl;
	}
}

void CalculateTotalAverage(double adBuff[ROW][COLUMN])
{
	double dSum = 0;
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COLUMN; j++)
			dSum += adBuff[i][j];
	}

	cout<<"Total average is:"<<dSum / (ROW * COLUMN)<<endl;
}

void FindMax(double dBuff[ROW][COLUMN])
{
	double dMax = 0;
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COLUMN; j++)
			dMax = max(dMax, dBuff[i][j]);
	}
	cout<<"Max is:"<<dMax<<endl;
}

void main()
{
	double dBbuff[ROW][COLUMN];
	Input(dBbuff);
	CalculateSetAverage(dBbuff);
	CalculateTotalAverage(dBbuff);
	FindMax(dBbuff);
}