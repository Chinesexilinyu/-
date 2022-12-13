
//Դ�ļ�
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
void testlr(LR array[7], char temp[20], G gl[4])
{
	char x1;
	int i = 0;
	int stop = 0;
	Stack* stack1;//״̬ջ
	Stack* stack2;//����ջ
	StackInitiate(&stack1);
	StackInitiate(&stack2);
	StackPush(stack1, '0');
	StackPush(stack2, '#');
	while (stop != 1 || temp[i] != '\0')
	{
		char state;//״̬
		char character;//����
		x1 = temp[i];
		if (x1 == 'a')
		{
			printf("\n��ǰɨ����ַ���a\n");
			printf("��ǰ״̬ջ:");
			print(stack1);
			printf("��ǰ����ջ:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//״̬ջ�����ַ�������ת��Ϊ���͵�ֵ
			if (!strcmp(array[state1].action1, ""))//Ϊ�գ�����
			{
				printf("����!");
			}
			else if (!strcmp(array[state1].action1, "acc"))//acc-��������
			{
				printf("\n***�����ɹ�***\n");
				stop = 1;
				//	exit(-1);
			}
			else if (array[state1].action1[0] == 's')//������ƽ�����
			{
				//int number=array[state1].action1[1]-'0';//����һ��״̬��
				char number = array[state1].action1[1];
				StackPush(stack1, number);//״̬��ջ
				StackPush(stack2, x1);        //���Ž�ջ            
				i++;
			}
			else if (array[state1].action1[0] == 'r')//��Լ����
			{
				int number = array[state1].action1[1] - '0';//���õڼ����ķ���Լ
				int length = strlen(gl[number - 1].g);//��ȡ�ķ�����
				if (length == 3)
				{
					char st1;
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					char ch3 = gl[number - 1].g[3];//��
					char ch4 = gl[number - 1].g[4];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackPop(stack1, &st1);//��
					StackPop(stack1, &st1);//��
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number].g[0]);//��Լ���󲿽�ջ
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
			printf("\n��ǰɨ����ַ���b\n");
			printf("��ǰ״̬ջ:");
			print(stack1);
			printf("��ǰ����ջ:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//״̬ջ�����ַ�������ת��Ϊ���͵�ֵ
			if (!strcmp(array[state1].action2, ""))//Ϊ�գ�����
			{
				printf("����!");
			}
			else if (!strcmp(array[state1].action2, "acc"))//acc-��������
			{
				printf("�����ɹ�");
				stop = 1;
			}
			else if (array[state1].action2[0] == 's')//������ƽ�����
			{
				char number = array[state1].action2[1];
				StackPush(stack1, number);//״̬��ջ
				StackPush(stack2, x1);        //���Ž�ջ            
				i++;
			}
			else if (array[state1].action2[0] == 'r')//��Լ����
			{
				int number = array[state1].action2[1] - '0';//���õڼ����ķ���Լ
				int length = strlen(gl[number - 1].g);//��ȡ�ķ�����
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					char ch3 = gl[number - 1].g[3];//��
					char ch4 = gl[number - 1].g[4];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackPop(stack1, &st1);//��
					StackPop(stack1, &st1);//��
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
			printf("\n��ǰɨ����ַ��� ,\n");
			printf("��ǰ״̬ջ:");
			print(stack1);
			printf("��ǰ����ջ:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//״̬ջ�����ַ�������ת��Ϊ���͵�ֵ
		//	printf("**state1=%d**",state1);
		//	printf("%s\n",array[state1].action1);
			if (!strcmp(array[state1].action3, ""))//Ϊ�գ�����
			{
				printf("����!");
			}
			else if (!strcmp(array[state1].action3, "acc"))//acc-��������
			{
				printf("�����ɹ�");
				stop = 1;
				//	exit(-1);
			}
			else if (array[state1].action3[0] == 's')//������ƽ�����
			{
				printf("  ����S  ");
				//int number=array[state1].action1[1]-'0';//����һ��״̬��
				char number = array[state1].action3[1];
				//	printf("%c",number);
				StackPush(stack1, number);//״̬��ջ
				StackPush(stack2, x1);        //���Ž�ջ            
		   //	 print(stack1);
		   //	 print(stack2);
				i++;
			}
			else if (array[state1].action3[0] == 'r')//��Լ����
			{
				printf("����R");
				int number = array[state1].action3[1] - '0';//���õڼ����ķ���Լ
			  //  printf("\nnumber=%d\n",number);
				int length = strlen(gl[number - 1].g);//��ȡ�ķ�����
			   // printf("length==%d  ",length);
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					char ch3 = gl[number - 1].g[3];//��
					char ch4 = gl[number - 1].g[4];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackPop(stack1, &st1);//��
					StackPop(stack1, &st1);//��
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
					printf("ʲô��û�ɣ�");
				}
			}
		}

		else if (x1 == '#')
		{
			printf("\n��ǰɨ����ַ���#\n");
			printf("��ǰ״̬ջ:");
			print(stack1);
			printf("��ǰ����ջ:");
			print(stack2);
			StackGet(stack1, &state);
			int state1 = state - '0';//״̬ջ�����ַ�������ת��Ϊ���͵�ֵ
			if (!strcmp(array[state1].action4, ""))//Ϊ�գ�����
			{
				printf("����!");
			}
			else if (!strcmp(array[state1].action4, "acc"))//acc-��������
			{
				printf("\n***�����ɹ�***\n");
				stop = 1;
				exit(-1);//֪ͨѭ��
			}
			else if (array[state1].action4[0] == 's')//������ƽ�����
			{
				char number = array[state1].action4[1];
				StackPush(stack1, number);//״̬��ջ
				StackPush(stack2, x1);        //���Ž�ջ            
				print(stack1);
				print(stack2);
				i++;
			}
			else if (array[state1].action4[0] == 'r')//��Լ����
			{
				printf("����R  ");
				int number = array[state1].action4[1] - '0';//���õڼ����ķ���Լ
				int length = strlen(gl[number - 1].g);//��ȡ�ķ�����
		 //	   printf("  number=%d  ",number);
		 //	   printf("length=%d   gl[number-1].g[0]=%c",length,gl[number-1].g[0]);
				if (length == 3)
				{
					int flag;
					char st1;
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
					char ch1 = gl[number - 1].g[0];//��
					char ch2 = gl[number - 1].g[2];//��
					char ch3 = gl[number - 1].g[3];//��
					char ch4 = gl[number - 1].g[4];//��
					StackPop(stack1, &st1);//�ȳ�״̬ջ
					StackPop(stack1, &st1);//��
					StackPop(stack1, &st1);//��
					StackGet(stack1, &st1);
					int number1 = st1 - '0';//����goto
				  //  printf("number1=%d",number1);
					StackPop(stack2, &ch1);//������ջ
					StackPop(stack2, &ch1);//������ջ
					StackPop(stack2, &ch1);//������ջ
					StackPush(stack2, gl[number - 1].g[0]);//��Լ���󲿽�ջ
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
	printf("ջ��:%s \n",x);
   while(StackNotEmpty(mystack))
   {
   x=StackPop(mystack);
   printf("%s    ",x);
   }
   */
   //������
	LR array[7] = { {"s3","s4","","","1","2"},{"","","","acc","",""},{"","","s5","r2","",""},
	{"","","r3","r3","",""},{"","","r4","r4","",""},{"s3","s4","","","6","2"},{"","","","r1","",""} };
	//�ķ�
	G gl[4] = { {"L-E,L"},{"L-E"},{"E-a"},{"E-b"} };//��-����->,��Ҳ�������Ÿ��£�����
	//�ĳ�->�Ļ���������Ĵ����Ҫ��
	char temp[20] = { "a,b,a#" };
	printf("����ķ��Ŵ�Ϊ:%s\n", temp);
	testlr(array, temp, gl);
	return 0;
}

