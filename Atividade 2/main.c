#include<sys/utsname.h>
#include<stdio.h>

int main(void){
struct utsname dados;
uname(&dados);

printf("Sistema Operacional: %s\n", dados.sysname);
printf("Nodename: %s\n", dados.nodename);
printf("Release: %s\n",dados.release);
printf("Versão do sistema: %s\n", dados.version);
printf("Hardware: %s\n", dados.machine);

return 0;
}
