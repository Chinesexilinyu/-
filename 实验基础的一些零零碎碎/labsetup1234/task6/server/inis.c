#include<stdlib.h>

int main(){
	system("ifconfig tun0 192.168.53.1/24 up");
	return 0;
}
