#include<stdlib.h>

int main(){
system("ifconfig tun0 192.168.53.5/24 up");
system("route add -net 192.168.60.0/24 tun0");
return 0;
}
