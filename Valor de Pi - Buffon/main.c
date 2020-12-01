#include <stdio.h>
#include <math.h>
#include <time.h>  
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    int i; //contador
    double l; //comprimento da agulha
    double n;// numero de tentativas
    double L; // espaço entre as linhas
    
    printf("O programa estima o valor do número pi pelo método de Monte Carlo com base no experimento das agulhas de Buffon\n");
    printf("Insira o número de tentativas como um valor maior que zero:\n");
    scanf("%lf", &n);
    printf("Insira um comprimento de agulha menor que a largura entre as linhas:\n");
    scanf( "%lf", &l);
    printf("Por favor, insira uma largura entre as linhas:\n");
    scanf("%lf", &L);
    if (n <= 0.0 || l > L) 
    {
        printf("Erro - dados fornecidos incorretamente \n");
        return 1;
    }
    printf("%f %f %f \n", n,l,L);


     pid_t pid = fork();

    if ( pid  < 0 ) {
      perror("Process could not be forked!");
      exit(EXIT_FAILURE);
    } else if ( pid == 0 ) {  // If the pid is equal to 0 we are executing the child
      filho(n, l, L);
    } else { // If the pid is not negative nor 0 we are executing the parent
      printf("PAI \n");
    }

}

int filho(double n, double l, double L){
    double x; // angulo
    double P=0; //quantidade de tentativas que funcionaram
    double d; // distancia entre o centro da agulha e linha
    double y; //minimizando os cálculos
    int i;
    double pi; // pi
    double  quant; //quantidade de tentativas para quantidade de tentativas bem-sucedidas

    for (i = 0; i<n; i++)
  {
    x = ((double)rand()/RAND_MAX)*3.1415; // angulo randomico - em rad

    d = ((double)rand()/RAND_MAX)*L/2; // comprimento aleatório da agulha menor que o espaçamento de linha

    y = (l/2) * sin (x);
printf(" Tentativa %d\n", i);
    if (d<=y)                                    
    {
        P++;                                  
    }

  }

quant=n/P;
printf("quantidade: %lf \n", quant);
pi=quant*2*l/L;
printf("pi=%lf", pi); 
    return 0;
  }
