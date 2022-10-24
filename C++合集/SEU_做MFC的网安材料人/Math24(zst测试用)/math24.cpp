#include<iostream>
using namespace std;
 int main()
 {
 int A=1,B=2,C=3,D=4,a=1,b=2,c=3,d=4,e=-1,f=112,out1,out2,out3,operator1=1,operator2=2,operator3=2;
 int num[12]={0};
 for(int i=0;i<12;i++)
 {
	 if(i+1==A||i+1==B||i+1==C||i+1==D)
	 num[i]++;
 }
   switch(operator1)
   {
	   if(a==A||a==B||a==C||a==D)
	   {
		   if(b!=a&&(b==A||b==B||b==C||b==D))
		   {  num[a]--,num[b]--; 
              case 0: out1=a+b;  break;
              case 1: out1=a-b;  break;
              case 2: out1=a*b;  break;
              case 3: out1=a/b;  break;
		   }
	   }
	   cout<<"请输入正确的数字"<<endl;
   }
  
  
	  if((c!=a&&c!=b&&(c==A||c==B||c==C||c==D))&&(d!=a&&d!=b&&d!=c&&(d==A||d==B||d==C||d==D)))
	  {
		  switch(operator2)
			{			
				case 0: out2=c+d; break;
			    case 1: out2=c-d; break; 
                case 2: out2=c*d; break; 
                case 3: out2=c/d; break; 
			}
	  }
	  else if (c==out1)  
				if(d!=a&&d!=b&&(d==A||d==B||d==C||d==D))
				{
				num[d]--;out1=-10000;
				switch(operator2)
					{
						case 0: out2=c+d; break;
						case 1: out2=c-d; break; 
						case 2: out2=c*d; break; 
						case 3: out2=c/d; break; 
					}
				}
		   else if(d==out1)  
					if(c!=a&&c!=b&&(c==A||c==B||c==C||c==D))
					{	num[c]--;out1=-10000;
						switch(operator2)
						{	
							case 0: out2=c+d; break;
							case 1: out2=c-d; break; 
							case 2: out2=c*d; break; 
							case 3: out2=c/d; break; 
						}
					}
		cout<<"请输入正确的数字"<<endl;
  
         if(out1==-10000)//out1在第二行式子中被用掉，则代表第三行式子中使用了ABCD中的最后一个未被使用的数
			 if(e==out2)
				for(int i=0;i<12;i++)
				{
					if ((i+1==f)&&num[i])
					{	switch(operator3)
						{
							 case 0:  out3=e+f;break;
							 case 1:  out3=e-f;break;
							 case 2:  out3=e*f;break;
							 case 3:  out3=e/f;break;
						}
					}
					else  cout<<"请输入正确的数字"<<endl;
				}
			 else if(f==out2)
			 {
				for(int i=0;i<12;i++)
				{
					if ((i+1==e)&&num[i])
					{	switch(operator2)
						{
							 case 0:  out3=e+f;break;
							 case 1:  out3=e-f;break;
							 case 2:  out3=e*f;break;
							 case 3:  out3=e/f;break;
						}
					}
				}
			 } else cout<<"请输入正确的数字"<<endl;
		   else if((e==out1&&f==out2)||(e==out2&&f==out1))   
						{	switch(operator2)
							{
							 case 0:  out3=e+f;break;
							 case 1:  out3=e-f;break;
							 case 2:  out3=e*f;break;
							 case 3:  out3=e/f;break;
							}
						}
				  else cout<<"请输入正确的数字"<<endl;
   
   if(out3==24)
	   cout << "回答正确!" << endl;
   else cout << "回答错误!" << endl;
   return 0;
 }