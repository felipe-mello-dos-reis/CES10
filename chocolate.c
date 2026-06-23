#include <stdio.h>

int main ()
{
	int X1, X2, Y1, Y2, N;
	scanf("%d", &N);
	scanf("%d %d", &X1, &Y1);
	scanf("%d %d", &X2, &Y2);
	if ((X1 <= N/2 && X2 > N/2) || (X2 <= N/2 && X1 > N/2))
		printf("S\n");
	else if ((Y1 <= N/2 && Y2 > N/2) || (Y2 <= N/2 && Y1 > N/2))
		printf("S\n");
	else
		printf("N\n");
	return 0;
}
