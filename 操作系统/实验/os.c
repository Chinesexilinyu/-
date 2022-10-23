#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
double number;
int count;
void* runner1(void*param);
int main()
{
	pthread_t tid1;
	pthread_attr_t attr1;
	printf("please input the amount of numbers:\n");
	scanf("%d",&count);
	double*a=(double*)malloc(sizeof(int)*(2*count));
	pthread_attr_init(&attr1);
	pthread_create(&tid1,&attr1,runner1,a);
	pthread_join(tid1,NULL);
	double b;
	b=4*number/count;
	printf("the approximate value is %lf\n",b);
	free(a);
	return 0;
}
void* runner1(void*param)
{
	double*p=(double*)param;
	int temp,i;
	for(i=0;i<count*2;i++)
	{
		temp=rand()%2;
		if(temp==0)
		{
			p[i]=rand()/(double)(RAND_MAX);
		}
		else
		{
			p[i]=-(rand()/(double)(RAND_MAX));
		}
	}
	number=0;
	for(i=0;i<count;i++)
	{
        	if((p[i]*p[i]+p[i+count]*p[i+count])<=1)
	        	number++;
	}	
	pthread_exit(0);
}
