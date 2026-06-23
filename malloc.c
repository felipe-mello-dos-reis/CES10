#include<stdio.h>
#include<stdlib.h>
typedef int*vetor;
int main()
{
	int m, i; vetor A, B, C;
	printf("Tamnho dos vetores: ");
	scanf("%d", &m);
	A = (int *) malloc (m*sizeof(int));
	B = (int *) malloc (m*sizeof(int));
	C = (int *) malloc (m*sizeof(int));
	printf("\nVetor A: ");
	for(i=0; i<m; i++)
		scanf("%d", &A[i]);
	printf("\nVetor B: ");
	for(i=0; i<m; i++)
		scanf("%d", &B[i]);
	printf("\nVetor C: ");
	for(i=0; i<m; i++)
		C[i] = (A[i]>B[i])? A[i]: B[i];
	for(i=0; i<m; i++)
		printf("%4d", C[i]);
	printf("\n\n");
	return 0;
}
	
