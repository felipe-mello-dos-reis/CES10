#include <stdio.h>

double f1 (double x)
{
	return 1/(1+25*x*x);
}
double f2 (double x)
{
	return x*x*x - x;
}
double f3(double x)
{
	return x*x - 4*x + 10;
}
typedef double vetor[50];
typedef struct carta carta;
struct carta
{
	vetor y;
};
struct carta funcao (double f (double), double inf, double sup/*, int n*/)
{
	carta aux;
	for(int i = 0; i < 22; i++)
		printf("-");
	printf("\n   x |%15s  \n", "f(x)");
	for(int i = 0; i < 22; i++)
		printf("-");
	printf("\n");
	int k = inf;
	for(double x = inf; x <= sup;k++, x++)
		{
			printf("%4.0lf |%15.5lf \n", x, f(x));
			aux.y[k] = f(x);
		}
	for(int i = 0; i < 22; i++)
		printf("-");
	printf("\n\n");
	return aux;
}
int main ()
{
	//int n;
	double inf, sup;
	carta y1, y2, y3;
	printf("Digite os limites inferior e superior: ");
	scanf("%lf%lf", &inf , &sup);
	/*printf("Digite o numero de linhas: ");
	scanf("%d", &n);*/
	printf("\nf1(x) = 1/(1 + 25x²)\tf2(x) = x³-x\tf3(x) = x² -4x +10\n");
	y1 = funcao(f1, inf, sup/*, n*/);
	y2 = funcao(f2, inf, sup/*, n*/);
	y3 = funcao(f3, inf, sup/*, n*/);
	printf("\n\n");  return 0;
}
