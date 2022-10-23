#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int id,a[7],num,i;
	printf("please input seven numbers:\n");
	for(i=0;i<7;i++)
	{
		scanf("%d",&a[i]);
	}
	id=fork();
	if(id==0)
	{
		id=fork();
		if(id==0)
		{
			num=a[0];
			for(i=0;i<7;i++)
			{
				if(num<a[i])
				{
					num=a[i];
				}
			}
			printf("The maximum value is %d",num);
			printf("\n");
		}
		else
		{
			num=a[0];
			for(i=0;i<7;i++)
			{
				if(num>a[i])
				{
					num=a[i];
				}
			}
			printf("The minimum value is %d",num);
			printf("\n");
		}
	}
	else
	{
		num=0;
		for(i=0;i<7;i++)
		{
			num=num+a[i];
		}
		num=num/7;
		printf("The average value is %d",num);
		printf("\n");
	}
	return 0;
}
