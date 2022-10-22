#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int max(int str[])
{
	int max=0,i,n;
	for(i=0;i<26;i++)
	{
		if(max<str[i])
		{
			max=str[i];
			n=i;
		}
	}
	if(max>0) return n;
	else return 100;
}
int main()
{
	int str[26]={0};
	int str1[26]={0};
	int i,j=0,k=0;
	char x,y;
	char m[26]={0};
	fstream in1("mima.txt",ios::in);
	while(!in1.eof())
	{
		in1>>x;
		switch(x)
		{
		case 'A':str[0]++;break;
		case 'B':str[1]++;break;
		case 'C':str[2]++;break;
		case 'D':str[3]++;break;
		case 'E':str[4]++;break;
		case 'F':str[5]++;break;
		case 'G':str[6]++;break;
		case 'H':str[7]++;break;
		case 'I':str[8]++;break;
		case 'J':str[9]++;break;
		case 'K':str[10]++;break;
		case 'L':str[11]++;break;
		case 'M':str[12]++;break;
		case 'N':str[13]++;break;
		case 'O':str[14]++;break;
		case 'P':str[15]++;break;
		case 'Q':str[16]++;break;
		case 'R':str[17]++;break;
		case 'S':str[18]++;break;
		case 'T':str[19]++;break;
		case 'U':str[20]++;break;
		case 'V':str[21]++;break;
		case 'W':str[22]++;break;
		case 'X':str[23]++;break;
		case 'Y':str[24]++;break;
		case 'Z':str[25]++;break;
		default :break;
		}
	}
	in1.close();
	for(i=0,x='A';i<26;i++,x++)
	{
		str1[i]=str[i];
		cout<<x<<':'<<str[i]<<'\t';
		if(i%5==0) cout<<'\n';
	}
	cout<<endl;
	for(k=0;k<26;k++)
	{
		j=max(str1);
		if(j>26)  break;
		else
		{
			str1[j]=0;
			switch(k)
			{
			case 0:m[j]='E';break;
			case 1:m[j]='T';break;
			case 2:m[j]='A';break;
			case 3:m[j]='O';break;
			case 4:m[j]='I';break;
			case 5:m[j]='N';break;
			case 6:m[j]='S';break;
			case 7:m[j]='R';break;
			case 8:m[j]='H';break;
			case 9:m[j]='L';break;
			case 10:m[j]='D';break;
			case 11:m[j]='C';break;
			case 12:m[j]='U';break;
			case 13:m[j]='M';break;
			case 14:m[j]='F';break;
			case 15:m[j]='P';break;
			case 16:m[j]='G';break;
			case 17:m[j]='W';break;
			case 18:m[j]='Y';break;
			case 19:m[j]='B';break;
			case 20:m[j]='V';break;
			case 21:m[j]='K';break;
			case 22:m[j]='X';break;
			case 23:m[j]='J';break;
			case 24:m[j]='Q';break;
			case 25:m[j]='Z';break;
			}
		}
	}
	cout<<"密码对应为："<<endl;
	for(i=0,x='A';i<26;i++,x++)
	{
		cout<<x<<':';
		if(m[i]>64&&m[i]<91)
			cout<<m[i]<<endl;
		else
			cout<<endl;
	}
	fstream in2("mima.txt",ios::in);
	fstream out("mmm.txt",ios::out);
	while(!in2.eof())
	{
		in2>>x;
		switch(x)
		{
		case 'A':out<<m[0];break;
		case 'B':out<<m[1];break;
		case 'C':out<<m[2];break;
		case 'D':out<<m[3];break;
		case 'E':out<<m[4];break;
		case 'F':out<<m[5];break;
		case 'G':out<<m[6];break;
		case 'H':out<<m[7];break;
		case 'I':out<<m[8];break;
		case 'J':out<<m[9];break;
		case 'K':out<<m[10];break;
		case 'L':out<<m[11];break;
		case 'M':out<<m[12];break;
		case 'N':out<<m[13];break;
		case 'O':out<<m[14];break;
		case 'P':out<<m[15];break;
		case 'Q':out<<m[16];break;
		case 'R':out<<m[17];break;
		case 'S':out<<m[18];break;
		case 'T':out<<m[19];break;
		case 'U':out<<m[20];break;
		case 'V':out<<m[21];break;
		case 'W':out<<m[22];break;
		case 'X':out<<m[23];break;
		case 'Y':out<<m[24];break;
		case 'Z':out<<m[25];break;
		default :out<<x;break;
		}
	}
	in2.close();
	out.close();
	cout<<"请去mmm文件查询明文！"<<endl;
	return 0;
}