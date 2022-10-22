#include<iostream>
#include<sys/types.h>
using namespace std;
int main(int argc, char * argv[])
{
int i, id1, id2;
for (i = 1; i < 2; i++) {
id1 = fork();
id2 = fork();
if (id1 == 0 || id2 == 0) fork();
}
printf("I am %d\n", getpid());
return 0;
}