#include <stdio.h>
#include <stdlib.h>

int chamada = 0;

int fib(int n)
{
	chamada = chamada +1;
	if(n<0)
		return -1;
	else if(n==0)
		return 0;
	else if(n==1)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int main()
{
	int i, n, aux;
	printf("NUMEROS DE FIBONACCI\nDigite o limite que deseja exibir: ");
	scanf("%d", &n);
	printf("%10s |%18s | %19s\n----------------------------------------------------------\n", "n", "Fib(n)", "Chamadas recursivas");
	for(i = 0; i <= n;i++)
	{
		aux =  fib(i);
		printf("%10d |%18d | %19d\n", i, aux, chamada);
		chamada = 0;
	}
	return 0; 
}
