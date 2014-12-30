#include <iostream>
using namespace std;

#define ROW 3
#define COLUMN 5

#define max(a,b) (a > b ? a : b)

void input(double buff[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		cout<<"Set "<<i<<":Input 5 double(Split them by space):";
		for(int j = 0; j < COLUMN; j++)
			cin>>buff[i][j];
	}
}

void calculate_set_average(double buff[ROW][COLUMN])
{
	for(int i = 0; i < ROW; ++i)
	{
		double sum = 0;
		for(int j = 0; j < COLUMN; j++)
			sum += buff[i][j];
		cout<<"Average of set "<<i<<" is:"<<sum / COLUMN<<endl;
	}
}

void calculate_total_average(double buff[ROW][COLUMN])
{
	double sum = 0;
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COLUMN; j++)
			sum += buff[i][j];
	}

	cout<<"Total average is:"<<sum / (ROW * COLUMN)<<endl;
}

void find_max(double buff[ROW][COLUMN])
{
	double max = 0;
	for(int i = 0; i < ROW; ++i)
	{
		for(int j = 0; j < COLUMN; j++)
			max = max(max, buff[i][j]);
	}
	cout<<"Max is:"<<max<<endl;
}

void main()
{
	double buff[ROW][COLUMN];
	input(buff);
	calculate_set_average(buff);
	calculate_total_average(buff);
	find_max(buff);
}