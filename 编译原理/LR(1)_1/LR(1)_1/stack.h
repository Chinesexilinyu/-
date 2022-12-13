#pragma once
//ͷ�ļ�
typedef struct node
{
	char data;
	struct node* next;
}Stack;
typedef struct//��װLR������
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
//��ʼ��
void StackInitiate(Stack** head)
{
	(*head) = (Stack*)malloc(sizeof(Stack));
	(*head)->next = NULL;
}
//�п�
int StackNotEmpty(Stack* head)
{
	if (head->next != NULL)
		return 1;
	else
		return 0;
}
//��ջ
int StackPush(Stack* head, char x)
{
	Stack* p;
	p = (Stack*)malloc(sizeof(Stack));
	p->data = x;

	p->next = head->next;
	head->next = p;
	return 1;
}
//��ջ
int StackPop(Stack* head, char* x)
{
	Stack* p;
	p = head->next;
	if (p == NULL)
	{
		printf("��ջ�ѿ��޷���ջ!");
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
//ȡջ������Ԫ��
int StackGet(Stack* head, char* x)
{
	Stack* p;
	p = head;
	if (p->next == NULL)
	{
		printf("��ջ�ѿ��޷���ջ!");
		return 0;
	}
	else
		*x = p->next->data;
	return 1;
}
//������̬����ռ�
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
void print(Stack* head)//��ӡ��ǰջ�е�����Ԫ��
{
	Stack* p = head->next;
	//	printf("��ǰջ�е�����Ϊ:");
	while (p != NULL)
	{
		printf("%c  ", p->data);
		p = p->next;
	}
}