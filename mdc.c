#include <stdio.h>

int mdc (int m, int n) {
	int r;
  	m = abs(m); n = abs(n);
	if (m==0 && n==0) r = -1;
	else if (m == 0) r = n;
	else if (n == 0) r = m;
	else r = mdc(n, m%n);
	return r;
}
int main() {
	int m, n;
  	printf ("Calculo do mdc de m e n");
  	printf ("\n\n\tDigite m e n: "); scanf ("%d%d", &m, &n);
  	printf ("\n\tmdc(%d, %d) = %d", m, n, mdc(m, n));
  	printf ("\n\n"); return 0;
}
