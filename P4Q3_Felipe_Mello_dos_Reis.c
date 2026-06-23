#include<stdio.h>

long int pot (int x, int n);
int EhMagico (long int n);

int main()
{
	long int a;
	printf("VERIFICADOR DE NUMEROS  MAGICOS\n\n");
	printf("Digite um inteiro: ");
	scanf("%ld", &a);
	if(EhMagico(a) == 1)
		printf("\t%ld eh um numero magico\n\n", a);
	else
		printf("\t%ld nao eh um numero magico\n\n", a);
	return 0;
}

long int pot (int x, int n)
{
	int p=1;
	if(n != 0)
		p = x * pot(x, n-1);
	return p;
}

int EhMagico (long int n)
{
	int ndigitos, exp = -1, logic = 0;
	if(n < 1 || n > pot(10,9))
		return 0;
	long int parte1, parte2;
	while(logic == 0)
	{
		exp++;
		if(n >= pot(10,exp) && n < pot(10,exp + 1))
			logic = 1;
	}
	ndigitos = exp+1;
	if(ndigitos % 2 != 0)
		return 0;
	else
	{
		parte2 = n % pot(10,ndigitos/2);
		parte1 = n/pot(10,ndigitos/2);
		if((parte1 + parte2)*(parte1 + parte2) == n)
			return 1;
		else
			return 0;
	}
}
