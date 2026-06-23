#include <stdio.h>
#include <stdlib.h>

int pot (int x, int n)
{
	int p=1;
	if(n != 0)
		p = x * pot(x, n-1);
	return p;
}

int main()
{
	int x, n;
  	printf ("Calculo da poentica de x^n");
  	printf ("\n\n\tDigite x e n: "); scanf ("%d%d", &x,  &n);
  	if(n < 0 || (n == 0 && x == 0))
		printf("\n\tEntrada invalida!");
	else
		printf ("\n\tPot(%d,%d) = %d", x, n, pot(x,n));
  	system("pause"); printf ("\n\n"); return 0;
}
