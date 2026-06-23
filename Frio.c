#include <stdio.h>
#include <stdlib.h>

int main () {
	char estahfrio;
	printf ("Estah frio? (s/n): ");
	scanf ("%c", &estahfrio);
	if (estahfrio == 's' || estahfrio == 'S')
		printf ("\n\tVista seu casaco!!");
	else
		printf ("\n\tDeixe seu casaco no guarda-roupas!!");
	printf ("\n\n"); system ("pause");
	return 0;
}
