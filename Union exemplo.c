
#include <stdio.h>
#include <stdlib.h>

typedef char str2[2]; typedef char str4[4];
struct ss {str2 x[4]; str4 y[2];};
typedef struct ss ss; typedef char str16[16];
typedef char str8[8];
union uu {ss a; str16 b; str8 c;} uniao;

int main () {
	str16 palavra = "ABCDEFGHIJKLMNOP";
	str8 numero = "12345678";
	int i, j;
	for (i=0; i<16; i++) uniao.b[i] = palavra[i];
	for (i=0; i<8; i++) uniao.c[i] = numero[i];
	for (i=0; i<4; i++) {
		for (j=0; j<2; j++)
			printf ("%c%c",
				uniao.a.x[i][j],
				uniao.a.y[j][i]);
		printf ("\n");
	}
   	printf ("\n\n");  system ("pause");
	return 0;
}
