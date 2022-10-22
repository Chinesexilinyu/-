#include<iostream>
using namespace std;
void IP(int*a)
{
	int b[65];
	int i;
	for(i=1;i<=64;i++)
	{
		if(i<=8)
		{
			b[i]=a[2+8*(8-i)];
		}
		else
		{
			if(i<=16)
			{
				b[i]=a[4+8*(16-i)];
			}
			else
			{
				if(i<=24)
				{
					b[i]=a[6+8*(24-i)];
				}
				else
				{
					if(i<=32)
					{
						b[i]=a[8+8*(32-i)];
					}
					else
					{
						if(i<=40)
						{
							b[i]=a[1+8*(40-i)];
						}
						else
						{
							if(i<=48)
							{
								b[i]=a[3+8*(48-i)];
							}
							else
							{
								if(i<=56)
								{
									b[i]=a[5+8*(56-i)];
								}
								else
									b[i]=a[7+8*(64-i)];
							}
						}
					}
				}
			}
		}
	}
	for(i=1;i<=64;i++)
		a[i]=b[i];
}
void _IP(int*a)
{
	int b[65];
	int i;
	for(i=1;i<=64;i++)
	{
		if(i%8==2)
		{
			b[i]=a[1+(58-i)/8];
		}
		else
		{
			if(i%8==4)
			{
				b[i]=a[9+(60-i)/8];
			}
			else
			{
				if(i%8==6)
				{
					b[i]=a[17+(60-i)/8];
				}
				else
				{
					if(i%8==0)
					{
						b[i]=a[25+(64-i)/8];
					}
					else
					{
						if(i%8==1)
						{
							b[i]=a[33+(57-i)/8];
						}
						else
						{
							if(i%8==3)
							{
								b[i]=a[41+(59-i)/8];
							}
							else
							{
								if(i%8==5)
								{
									b[i]=a[49+(61-i)/8];
								}
								else
									b[i]=a[57+(63-i)/8];
							}
						}
					}
				}
			}
		}
	}
	for(i=1;i<=64;i++)
		a[i]=b[i];
}
int main()
{
	int*a;
	a=new int[65];
	int i;
	cout<<"请输入64个数字："<<endl;
	for(i=1;i<=64;i++)
	{
		cin>>a[i];
	}
	cout<<"转置之后："<<endl;
	IP(a);
	for(i=1;i<=64;i++)
	{
		cout<<a[i];
		if(i%8==0) cout<<'\n';
	}
	_IP(a);
	cout<<"逆转之后："<<endl;
	for(i=1;i<=64;i++)
	{
		cout<<a[i];
		if(i%8==0) cout<<'\n';
	}
	delete []a;
	return 0;
}