#include <stdio.h>
#include <stdlib.h>

void ImprimirMatriz (int V[][10], int x, int y) {
 	int i, j;
   printf ("Endereco(V) = %d; Conteudo(V) = %d;\n\n", &V, V);
   printf ("Endereco(V[0][0]) = %d\n\n", &V[0][0]);
   for (i = 0; i < x; i++) {
   	for (j = 0; j < y; j++) {
   		printf ("%5d", V[i][j]);
     	}
      	printf ("\n");
  	}
}

int main () {
	int A[10][10], i, j, m = 5, n = 7;
	printf ("A = %d\n\n", A);
  	printf ("Endereco(A[0][0]) = %d\n\n", &A[0][0]);
  	for (i = 0; i < m; i++)
   	for (j = 0; j < n; j++) 
   	     A[i][j] = (i+1)*(j+1);
	ImprimirMatriz (A, m, n);
	getch ();
}
