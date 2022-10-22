#include<stdlib.h>

int main(){
	system("route add -net 192.168.53.0/24 gw 192.168.60.2 eth0");
	return 0;
}
