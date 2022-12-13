#pragma once
//头文件
typedef struct node
{
	char data;
	struct node* next;
}Stack;
typedef struct//封装LR分析表
{
	char action1[10];//a
	char action2[10];//b
	char action3[10];//,
	char action4[10];//#
	char goto1[10];//L
	char goto2[10];//E
}LR;
typedef struct
{
	char g[10];
}G;
//初始化
void StackInitiate(Stack** head)
{
	(*head) = (Stack*)malloc(sizeof(Stack));
	(*head)->next = NULL;
}
//判空
int StackNotEmpty(Stack* head)
{
	if (head->next != NULL)
		return 1;
	else
		return 0;
}
//入栈
int StackPush(Stack* head, char x)
{
	Stack* p;
	p = (Stack*)malloc(sizeof(Stack));
	p->data = x;

	p->next = head->next;
	head->next = p;
	return 1;
}
//出栈
int StackPop(Stack* head, char* x)
{
	Stack* p;
	p = head->next;
	if (p == NULL)
	{
		printf("堆栈已空无法出栈!");
		return 0;
	}
	else
	{
		head->next = p->next;
		*x = (p->data);
		free(p);
		return 1;
	}
}
//取栈顶数据元素
int StackGet(Stack* head, char* x)
{
	Stack* p;
	p = head;
	if (p->next == NULL)
	{
		printf("堆栈已空无法出栈!");
		return 0;
	}
	else
		*x = p->next->data;
	return 1;
}
//撤销动态申请空间
void Destroy(Stack* head)
{
	Stack* p, * p1;
	p = head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
void print(Stack* head)//打印当前栈中的所有元素
{
	Stack* p = head->next;
	//	printf("当前栈中的内容为:");
	while (p != NULL)
	{
		printf("%c  ", p->data);
		p = p->next;
	}
}