#include<iostream>
using namespace std;

#define BUFFER_SIZE 20

void copy_by_array(int buff[], int new_buff [])
{
	for(int i = 0; i < BUFFER_SIZE; ++i)
		new_buff[i] = buff[i];
}

void copy_by_pointer(int buff[], int *ptr)
{
	for(int i = 0; i < BUFFER_SIZE; ++i)
		*ptr++ = buff[i];
}

void main()
{
	int buffer[BUFFER_SIZE];
	for(int i = 0; i < BUFFER_SIZE; ++i)
		buffer[i] = i;

	int new_buffer_1[BUFFER_SIZE] = {0};
	int new_buffer_2[BUFFER_SIZE] = {0};

	copy_by_array(buffer, new_buffer_1);
	cout<<"copy_by_array():";
	for(int i = 0; i < BUFFER_SIZE; ++i)
		cout<<new_buffer_1[i]<<",";
	cout<<endl;

	cout<<"copy_by_pointer():";
	copy_by_pointer(buffer, new_buffer_2);
	for(int i = 0; i < BUFFER_SIZE; ++i)
		cout<<new_buffer_2[i]<<",";
	cout<<endl;
}
