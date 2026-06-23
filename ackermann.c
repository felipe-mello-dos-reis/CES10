#include <stdio.h>
#include <stdlib.h>

int ackermann(int m, int n)
{
	if(m < 0 || n < 0)
		return -1;
	else
		if(m==0)
			return n+1;
		else
			if(n==0)
				return ackermann(m-1,1);
			else
				return ackermann(m-1, ackermann(m,n-1));
}
int main()
{
	int i, j;
	printf("FUNCAO ACKERMAN\nDigite os valores inteiros de (i,j): ");
	scanf("%d%d", &i, &j);
	printf("Ackermann(%d,%d) = %d\n", i, j, ackermann(i,j));
	printf("\n\n");
	system("pause");
	return 0;
}
