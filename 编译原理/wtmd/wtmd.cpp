 
#include <stdio.h>
#include <stdlib.h>
#define MAXROW 16
#define MAXACTIONCOL 8
#define MAXGOTOCOL 3
#define MAXDEPTH 50
#define MAXCOUNT 9
 
typedef struct {
    int status;
    char symbol;
}stack_e;
stack_e stack[MAXDEPTH];
int top = 0;
char surplus[MAXDEPTH];
int length = 0;
typedef struct{
    char left;
    const char* right;
    int length;
}grammar;
grammar grammars[MAXCOUNT] = {
        (grammar){'S', "E", 1},
        (grammar){'E', "E+T", 3},
        (grammar){'E', "E-T", 3},
        (grammar){'E', "T", 1},
        (grammar){'T', "T*F", 3},
        (grammar){'T', "T/F", 3},
        (grammar){'T', "F", 1},
        (grammar){'F', "(E)", 3},
        (grammar){'F', "i", 1}
};
int action_tab[MAXROW][MAXACTIONCOL] = {
        { 0, 0, 0, 0, 4, 0, 5, 0},
        { 6, 7, 0, 0, 0, 0, 0, 999},
        {-3,-3, 8, 9, 0,-3, 0,-3},
        {-6,-6,-6,-6, 0,-6, 0,-6},
        { 0, 0, 0, 0, 4, 0, 5, 0},
        {-8,-8,-8,-8, 0,-8, 0,-8},
        { 0, 0, 0, 0, 4, 0, 5, 0},
        { 0, 0, 0, 0, 4, 0, 5, 0},
        { 0, 0, 0, 0, 4, 0, 5, 0},
        { 0, 0, 0, 0, 4, 0, 5, 0},
        { 6, 7, 0, 0, 0,15, 0, 0},
        {-1,-1, 8, 9, 0,-1, 0,-1},
        {-2,-2, 8, 9, 0,-2, 0,-2},
        {-4,-4,-4,-4, 0,-4, 0,-4},
        {-5,-5,-5,-5, 0,-5, 0,-5},
        {-7,-7,-7,-7, 0,-7, 0,-7}
};
int goto_tab[MAXROW][MAXGOTOCOL] = {
        { 1, 2, 3},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        {10, 2, 3},
        { 0, 0, 0},
        { 0,11, 3},
        { 0,12, 3},
        { 0, 0,13},
        { 0, 0,14},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0}
};
const char vt[]={'+','-','*','/','(',')','i','#'};
const char vn[]={'E','T','F'};
 
void ExitWithStop(int erno)
{
    system("pause");
    exit(erno);
}
 
void Push(stack_e ele) {
    if (top<MAXDEPTH) {
        stack[++top] = ele;
    }
    else {
        printf("Error:stack is full!\n");
        ExitWithStop(1);
    }
}
 
stack_e Pop() {
    stack_e ele = stack[top];
    if (top>0) {
        stack[top--] = (stack_e){-1, '\0'};
    }
    else {
        printf("Error:stack is empty!\n");
        ExitWithStop(1);
    }
    return ele;
}
 
int ConvertInVt(char curch) {
    int i;
    for (i = 0; i < MAXACTIONCOL; ++i) {
        if (vt[i]==curch) {
            return i;
        }
    }
    return -1;
}
 
int ConvertInVn(char symbol) {
    int i;
    for (i = 0; i < MAXGOTOCOL; ++i) {
        if (vn[i]==symbol) {
            return i;
        }
    }
    return -1;
}
 
void PrintInfo(char curch) {
    int i;
    int length;
    length = printf("%d",stack[0].status);
    for(i=1;i<=top;++i) {
    	length += printf("%c%d",stack[i].symbol, stack[i].status);
	}
	for(i=0;i<24-length;++i) {
		printf(" ");
	}
	length = printf("%c%s",curch, surplus);
	for(i=0;i<24-length;++i) {
		printf(" ");
	}
}
 
char NextToken() {
    int i=1;
    char ch = surplus[0];
    while (surplus[i-1]!='\0') {
        surplus[i-1] = surplus[i];
        ++i;
    }
    return ch;
}
 
void Predict() {
    int flag = 1;
    int action;
    char curch;
    stack[top] = (stack_e){0, '#'};
    curch = NextToken();
    while (flag) {
        action = action_tab[stack[top].status][ConvertInVt(curch)];
        if (999 == action) {
            break;
        } else if (0 == action) {
            PrintInfo(curch);
            printf("Error!\n");
            ExitWithStop(1);
        } else if (action > 0) {
        	PrintInfo(curch);
        	printf("Shift %c\n",curch);
            Push((stack_e){action, curch});
            curch = NextToken();
        } else if (action < 0) {
            int i;
            int go;
            grammar g = grammars[-action];
            PrintInfo(curch);
            printf("Reduce %c with %c->%s\n",g.left,g.left,g.right);
            for (i = g.length-1; i >= 0; --i) {
                Pop();
            }
            go = goto_tab[stack[top].status][ConvertInVn(g.left)];
            Push((stack_e){go, g.left});
        } else {
            printf("Error with Action Table!\n");
            ExitWithStop(1);
        }
    }
    PrintInfo(curch);
    printf("Accepted!\n");
}
 
int main()
{
    char ch = 0;
    printf("LR method. create by Gaochao,2013***,CS2115\n");
    printf("input a expression within 50 characters which endwith '#':");
    while(ch!='#') {
        ch = getchar();
        if ('+' != ch && '-' != ch && '*' != ch && '/' != ch && '(' != ch && ')' != ch && 'i' != ch && '#' != ch) {
            printf("There are some wrong characters!");
            ExitWithStop(1);
        }
        else {
            surplus[length++] = ch;
        }
    }
    surplus[length] = 0;
    printf("Stack\t\t\tThe remaining string\tAction\n");
    Predict();
    system("pause");
    return 0;
}