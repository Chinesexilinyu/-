#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int aver,max,min,count;
void*running1(void*p)
{
	int*q=(int*)p;
	int i,sum=0;
	for(i=0;i<count;i++)
	{
		sum=sum+q[i];
	}
	aver=sum/count;
	pthread_exit(0);
}
void*running2(void*p)
{
	int*q=(int*)p;
	int i=0;
	min=q[0];
	for(i=0;i<count;i++)
	{
		if(min>q[i])
			min=q[i];
	}
	pthread_exit(0);
}
void*running3(void*p)
{
	int*q=(int*)p;
	int i;
	max=q[0];
	for(i=0;i<count;i++)
	{
		if(max<q[i])
			max=q[i];
	}
	pthread_exit(0);
}
int main()
{
	pthread_t tid1,tid2,tid3;
        pthread_attr_t attr1,attr2,attr3;
	int i;
	printf("please input the amount of these numbers:\n");
	scanf("%d",&count);
	int*a=(int*)malloc(sizeof(int)*(count));
	printf("please input numbers:\n");
	for(i=0;i<count;i++)
	{
		scanf("%d",&a[i]);
	}
	pthread_attr_init(&attr1);
	pthread_attr_init(&attr2);
	pthread_attr_init(&attr3);
	pthread_create(&tid1,&attr1,running1,a);
	pthread_join(tid1,NULL);
	pthread_create(&tid2,&attr2,running2,a);
	pthread_join(tid2,NULL);
	pthread_create(&tid3,&attr3,running3,a);
	pthread_join(tid3,NULL);
	printf("The average value is %d",aver);
	printf("\n");
	printf("The minimum value is %d",min);
        printf("\n");
	printf("The maximum value is %d",max);
	printf("\n");
	free(a);
	return 0;
}
