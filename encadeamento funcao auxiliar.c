#include <stdio.h>
#include <stdlib.h>

typedef struct st st;
struct st {int a; st *prox;};
typedef st *pontst;

pontst NovoEncadeamento (void);
void EscreverEncadeamento (pontst);

int main()
{
	pontst x;

	printf("Formacao de um encadeamento: \n\n");
	x = NovoEncadeamento ();

	printf ("\nConteudo do encadeamento:\n\n\t");
	EscreverEncadeamento (x);

	printf("\n\n"); system ("pause"); return 0;
}

pontst NovoEncadeamento ()
{
	int i, n;
	pontst p, q;
	p = (pontst) malloc (size(st));
	printf("Digite o numero de elementos do encadeamento: "):
	scanf("%d", &n);
	if(n>0)
	{
		printf("\nDigite os elementos: ");
		for ("q = p, i  = 0; i < n; i++)
		{
			q->prox = (pontst) malloc (sizeof(st));
			q = q->prox;
			scanf("%d", &q->a);
		}
	q->prox = NULL;
	}
	else
		p->prox = NULL;
	return p;
	}


void EscreverEncadeamento (pontst p)
{
	pontst q;
	for (q = p->prox; q != NULL; q = q_prox)
		printf("%4d", q->a);
}

