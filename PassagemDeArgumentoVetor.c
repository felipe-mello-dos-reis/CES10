#include <stdio.h>
#include <stdlib.h>

void Alterar (int B[]) {
	B[1] = B[3] = 7;
}

int main () {
	int i, A[10] = {0};
	printf ("Vetor inicial      : ");
	for (i = 0; i <= 9; i++)
		printf ("%3d", A[i]);
	Alterar (A);
	printf ("\n\nVetor intermediario: ");
	for (i = 0; i <= 9; i++) printf ("%3d", A[i]);
	Alterar (&A[4]);
	printf ("\n\nVetor final        : ");
	for (i = 0; i <= 9; i++) printf ("%3d", A[i]);
  	printf ("\n\n"); system ("pause"); return 0;
}
