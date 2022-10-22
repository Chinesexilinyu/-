#include<iostream>
using namespace std;
int main()
{
	int n,i,m1=0,m2=0;
	cin>>n;
	char*a=new char[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			m1++;
		}
		if(a[i]=='c') 
		{
			break;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(a[i]==')')
		{
			m2++;
		}
		if(a[i]=='c')
		{
			break;
		}
	}
	if(m1<m2)
		i=m1;
	else
		i=m2;
	cout<<i<<endl;
	delete []a;
	return 0;
}

/*int main()
{
	int T,n,m,S,i,j,t=0;
	int*a,*b,*number;
	cin>>T;
	number=new int[T];
	while(T>0)
	{
		cin>>n;
		cin>>m;
		cin>>S;
		a=new int[n];
		b=new int[m];
		for(i=0;i<n;i++)
			cin>>a[i];
		for(j=0;j<m;j++)
			cin>>b[j];



		number[t]=;
		t++;
		T--;
		delete []a;
		delete []b;
	}
	for(i=0;i<t;i++)
		cout<<number[i]<<endl;
	return 0;
}*/