#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	Declaracoes de tipos		*/

typedef char nome[10];
typedef enum diasemana diasemana;
enum diasemana {domingo, segunda, terca, quarta, quinta, sexta, sabado};

/*	Cabecalho e declaracoes de variaveis		*/

int main( ){
	diasemana hoje, ontem, amanha; char c, achou;
	nome cadhoje, NomeDia[7] = {"domingo", "segunda", "terca", "quarta",
		"quinta", "sexta", "sabado"};
/*	Desejo de execucao		*/

   printf ("Conhecer dia de ontem e de amanhan? (s/n): ");
   scanf ("%c", &c);

/*	Leitura do dia de hoje		*/

	while (c == 's' || c == 'S') {
		printf ("\n\tDigite o dia de hoje: "); scanf ("%s", cadhoje);
		achou = 0;

/*	Conversao da cadeia digitada para o tipo diasemana		*/

		hoje = domingo;
		while (hoje <= sabado && achou == 0)
			if (strcmp (cadhoje, NomeDia[hoje]) == 0) achou = 1;
			else hoje++;
/*	Caso de erro de digitacao		*/

      	if (hoje > sabado)
      		printf("\n\thoje: erro de digitacao\n\n");

/*	Determinacao dos dias de ontem e amanhan	*/

		else {
			ontem = (hoje+6) % 7; amanha = (hoje+1) % 7;
			printf("\n\thoje = %s; ontem = %s; amanhan = %s;\n\n",
				NomeDia[hoje], NomeDia[ontem], NomeDia[amanha]);
		}

/*	Desejo de nova execucao 		*/

   		printf ("Conhecer dia de ontem e de amanhan? (s/n): ");
   		fflush(stdin);
		scanf ("%c", &c);
	}
	printf ("\n\n"); system ("pause"); return 0;
}
