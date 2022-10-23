#include<windows.h>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
typedef int buffer_item;
#define BUFFER_SIZE 5
#define RAND_max 100
#define pro_number 4
#define con_number 3
int in = 0;
int out = 0;
int loops = 20;
buffer_item buffer[BUFFER_SIZE];
HANDLE full;
HANDLE empty;
HANDLE mutex;
DWORD WINAPI producer_i(LPVOID Param)
{
	srand(time(0));
	buffer_item item;
	int i;
	while (loops > 0)
	{
		i = rand() % 5 + 1;
		Sleep(i);
		item = rand() % RAND_max;
		WaitForSingleObject(empty,INFINITE);
		WaitForSingleObject(mutex, INFINITE);
		buffer[in] = item;
		in = (in + 1) % BUFFER_SIZE;
		loops--;
		printf("producer produced %d\n", item);
		ReleaseMutex(mutex);
		ReleaseSemaphore(full, 1, NULL);
	}
	return 0;
}
DWORD WINAPI consumer_i(LPVOID Param)
{
	srand(time(0));
	buffer_item item;
	int i;
	while (loops > 0)
	{
		i = rand() % 5 + 1;
		Sleep(i);
		WaitForSingleObject(full, INFINITE);
		WaitForSingleObject(mutex, INFINITE);
		item=buffer[out];
		out = (out + 1) % BUFFER_SIZE;
		loops--;
		printf("consumer consumed %d\n", item);
		ReleaseMutex(mutex);
		ReleaseSemaphore(empty, 1, NULL);
	}
	return 0;
}
int main()
{
    HANDLE producer[pro_number];
    HANDLE consumer[con_number];
	int th[BUFFER_SIZE];
    int i;
    mutex = CreateMutex(NULL, FALSE, NULL);
    empty = CreateSemaphore(NULL, BUFFER_SIZE, BUFFER_SIZE, NULL);
    full = CreateSemaphore(NULL, 0,BUFFER_SIZE, NULL);
    for (i = 0; i < pro_number; i++) 
	{
		th[i] = i + 1;
		producer[i] = CreateThread(NULL, 0, producer_i, &th[i], 0, NULL);
    }
    for (i = 0; i < con_number; i++) 
	{
		th[i] = i + 1;
        consumer[i] = CreateThread(NULL,0,consumer_i,&th[i],0, NULL);

    }
	WaitForMultipleObjects(pro_number, producer, TRUE, INFINITE);
	WaitForMultipleObjects(con_number, consumer, TRUE, INFINITE);
	i = rand() % 20;
	Sleep(i);
    return 0;
}