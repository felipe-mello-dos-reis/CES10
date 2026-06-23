#include <stdio.h>
#include <stdlib.h>

float modulo(float x)
{
	if(x>0)
		return x;
	else
		return -x;
}

float raizquad(float n, float a, float e)
{
	if(modulo(a*a-n) < e)
		return a;
	else
		return raizquad(n, (a*a+n)/(2*a), e);
}

int main()
{
	float n, a, e;
	printf("RAIZ QUADRADA\n");
	printf("Digite a raiz a ser calculada, seguida da primeira aproximacao e o  erro: ");
	scanf("%f %f %f", &n, &a, &e);
	printf("Raiz quadrada de %.4f eh aproximadamente %.6f\n\n", n,  raizquad(n, a, e));
	return 0;
}
