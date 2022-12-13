
//源文件
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
void testlr(LR array[7], char temp[20], G gl[4])
{
	char x1;
	int i = 0;
	int stop = 0;
	Stack* stack1;//状态栈
	Stack* stack2;//符号栈
	StackInitiate(&stack1);
	StackInitiate(&stack2);
	StackPush(stack1, '0');
	StackPush(stack2, '#');
	while (stop != 1 || temp[i] != '\0')
	{
		char state;//状态
		char character;//符号
		x1 = temp[i];
		if (x1 == 'a')
		{
			printf("\n当前扫描的字符是a\n");
			printf("当前状态栈:");
			print(stack1);
			printf("当前符号栈:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//状态栈中是字符，这里转换为整型的值
			if (!strcmp(array[state1].action1, ""))//为空，出错
			{
				printf("出错!");
			}
			else if (!strcmp(array[state1].action1, "acc"))//acc-分析结束
			{
				printf("\n***分析成功***\n");
				stop = 1;
				//	exit(-1);
			}
			else if (array[state1].action1[0] == 's')//如果是移进动作
			{
				//int number=array[state1].action1[1]-'0';//看下一个状态号
				char number = array[state1].action1[1];
				StackPush(stack1, number);//状态进栈
				StackPush(stack2, x1);        //符号进栈            
				i++;
			}
			else if (array[state1].action1[0] == 'r')//规约动作
			{
				int number = array[state1].action1[1] - '0';//看用第几个文法规约
				int length = strlen(gl[number - 1].g);//获取文法长度
				if (length == 3)
				{
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					StackPop(stack1, &st1);//先出状态栈
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
				else if (length == 5)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					char ch3 = gl[number - 1].g[3];//右
					char ch4 = gl[number - 1].g[4];//右
					StackPop(stack1, &st1);//先出状态栈
					StackPop(stack1, &st1);//出
					StackPop(stack1, &st1);//出
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
			}
		}
		else if (x1 == 'b')
		{
			printf("\n当前扫描的字符是b\n");
			printf("当前状态栈:");
			print(stack1);
			printf("当前符号栈:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//状态栈中是字符，这里转换为整型的值
			if (!strcmp(array[state1].action2, ""))//为空，出错
			{
				printf("出错!");
			}
			else if (!strcmp(array[state1].action2, "acc"))//acc-分析结束
			{
				printf("分析成功");
				stop = 1;
			}
			else if (array[state1].action2[0] == 's')//如果是移进动作
			{
				char number = array[state1].action2[1];
				StackPush(stack1, number);//状态进栈
				StackPush(stack2, x1);        //符号进栈            
				i++;
			}
			else if (array[state1].action2[0] == 'r')//规约动作
			{
				int number = array[state1].action2[1] - '0';//看用第几个文法规约
				int length = strlen(gl[number - 1].g);//获取文法长度
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					StackPop(stack1, &st1);//先出状态栈
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
				else if (length == 5)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					char ch3 = gl[number - 1].g[3];//右
					char ch4 = gl[number - 1].g[4];//右
					StackPop(stack1, &st1);//先出状态栈
					StackPop(stack1, &st1);//出
					StackPop(stack1, &st1);//出
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
			}
		}


		else if (x1 == ',')
		{
			printf("\n当前扫描的字符是 ,\n");
			printf("当前状态栈:");
			print(stack1);
			printf("当前符号栈:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//状态栈中是字符，这里转换为整型的值
		//	printf("**state1=%d**",state1);
		//	printf("%s\n",array[state1].action1);
			if (!strcmp(array[state1].action3, ""))//为空，出错
			{
				printf("出错!");
			}
			else if (!strcmp(array[state1].action3, "acc"))//acc-分析结束
			{
				printf("分析成功");
				stop = 1;
				//	exit(-1);
			}
			else if (array[state1].action3[0] == 's')//如果是移进动作
			{
				printf("  进入S  ");
				//int number=array[state1].action1[1]-'0';//看下一个状态号
				char number = array[state1].action3[1];
				//	printf("%c",number);
				StackPush(stack1, number);//状态进栈
				StackPush(stack2, x1);        //符号进栈            
		   //	 print(stack1);
		   //	 print(stack2);
				i++;
			}
			else if (array[state1].action3[0] == 'r')//规约动作
			{
				printf("进入R");
				int number = array[state1].action3[1] - '0';//看用第几个文法规约
			  //  printf("\nnumber=%d\n",number);
				int length = strlen(gl[number - 1].g);//获取文法长度
			   // printf("length==%d  ",length);
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					StackPop(stack1, &st1);//先出状态栈
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
				else if (length == 5)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					char ch3 = gl[number - 1].g[3];//右
					char ch4 = gl[number - 1].g[4];//右
					StackPop(stack1, &st1);//先出状态栈
					StackPop(stack1, &st1);//出
					StackPop(stack1, &st1);//出
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
				else {
					printf("什么都没干！");
				}
			}
		}

		else if (x1 == '#')
		{
			printf("\n当前扫描的字符是#\n");
			printf("当前状态栈:");
			print(stack1);
			printf("当前符号栈:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//状态栈中是字符，这里转换为整型的值
			if (!strcmp(array[state1].action4, ""))//为空，出错
			{
				printf("出错!");
			}
			else if (!strcmp(array[state1].action4, "acc"))//acc-分析结束
			{
				printf("\n***分析成功***\n");
				stop = 1;
				exit(-1);//通知循环
			}
			else if (array[state1].action4[0] == 's')//如果是移进动作
			{
				char number = array[state1].action4[1];
				StackPush(stack1, number);//状态进栈
				StackPush(stack2, x1);        //符号进栈            
				print(stack1);
				print(stack2);
				i++;
			}
			else if (array[state1].action4[0] == 'r')//规约动作
			{
				printf("进入R  ");
				int number = array[state1].action4[1] - '0';//看用第几个文法规约
				int length = strlen(gl[number - 1].g);//获取文法长度
		 //	   printf("  number=%d  ",number);
		 //	   printf("length=%d   gl[number-1].g[0]=%c",length,gl[number-1].g[0]);
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					StackPop(stack1, &st1);//先出状态栈
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
				else if (length == 5)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//左
					char ch2 = gl[number - 1].g[2];//右
					char ch3 = gl[number - 1].g[3];//右
					char ch4 = gl[number - 1].g[4];//右
					StackPop(stack1, &st1);//先出状态栈
					StackPop(stack1, &st1);//出
					StackPop(stack1, &st1);//出
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//用于goto
				  //  printf("number1=%d",number1);
					StackPop(stack2, &ch1);//出符号栈
					StackPop(stack2, &ch1);//出符号栈
					StackPop(stack2, &ch1);//出符号栈
					StackPush(stack2, gl[number - 1].g[0]);//规约的左部进栈
					if (gl[number - 1].g[0] == 'E')
					{
						StackPush(stack1, array[number1].goto2[0]);
					}
					else if (gl[number - 1].g[0] == 'L')
					{
						StackPush(stack1, array[number1].goto1[0]);
					}
				}
			}
		}
	}
}
int main()
{
	/*Stack *mystack;
	StackInitiate(&mystack);
	char *x;
	for(int i=0;i<10;i++)
	{
		StackPush(mystack,"a22");
	}
	printf("\n");
	x=StackGet(mystack);
	printf("栈顶:%s \n",x);
   while(StackNotEmpty(mystack))
   {
   x=StackPop(mystack);
   printf("%s    ",x);
   }
   */
   //分析表
	LR array[7] = { {"s3","s4","","","1","2"},{"","","","acc","",""},{"","","s5","r2","",""},
	{"","","r3","r3","",""},{"","","r4","r4","",""},{"s3","s4","","","6","2"},{"","","","r1","",""} };
	//文法
	G gl[4] = { {"L-E,L"},{"L-E"},{"E-a"},{"E-b"} };//用-代替->,你也可以试着改下，不过
	//改成->的话，你上面的代码就要改
	char temp[20] = { "a,b,a#" };
	printf("输入的符号串为:%s\n", temp);
	testlr(array, temp, gl);
	return 0;
}

