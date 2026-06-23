#include <stdio.h>
#include <stdlib.h>

typedef int **matriz;
int main () {
	int m, n, i, j; matriz A;
	printf ("Dimensoes de uma matriz: ");
	scanf ("%d%d", &m, &n);
	A = (int **) malloc (m * sizeof(int*));
	for (i = 0; i < m; i++)
		A[i]= (int *) malloc (n * sizeof(int));
	printf ("\nElementos da matriz:\n\n");
	for (i = 0; i < m; i++) {
		printf ("\tLinha %d: ", i);
		for (j = 0; j < n; j++)
			scanf ("%d", &A[i][j]);
	}
	printf ("\nConfirmacao: \n\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
			printf ("%5d", A[i][j]);
		printf ("\n");
	}
  	printf ("\n\n"); return 0;
}
