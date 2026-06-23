#include <stdio.h>
#include <stdlib.h>

typedef struct st st;
struct st {int a; st *prox;};
typedef st *pontst;

pontst NovoEncadeamento (void);
void EscreverEncadeamento (pontst);
void liberar (pontst);
int main()
{
	pontst x;

	printf("Formacao de um encadeamento: \n\n");
	x = NovoEncadeamento ();

	printf ("\nConteudo do encadeamento:\n\n\t");
	EscreverEncadeamento (x);

	printf("\n\n"); liberar(x);  return 0;
}

pontst NovoEncadeamento ()
{
	int i, n, num;
	pontst p, q, r;
	p = (pontst) malloc (sizeof(st));
	p->prox = NULL;
	printf("Digite o numero de elementos do encadeamento: ");
	scanf("%d", &n);
	if(n>0)
	{
		printf("\nDigite os elementos: ");
		for (q = p, i  = 0; i < n; i++)
		{
			
			scanf("%d", &num);
			while(q->prox != NULL && q->prox->a < num)
				q = q->prox;
			r = q->prox;
			q->prox = (pontst) malloc (sizeof(st));
			q->prox->a = num;
			q->prox->prox = r;
		}
	}
	return p;
}
/*	q->prox = NULL;
	}
	else
		p->prox = NULL;
	return p;
	}
*/

void EscreverEncadeamento (pontst p)
{
	pontst q;
	for (q = p->prox; q != NULL; q = q->prox)
		printf("%4d", q->a);
}

void liberar(pontst p) 
{
	int len = 0;
	pontst q;
	for(q = p->prox; q != NULL; q = q->prox)
		len++;
	for(int i = 0; i < len; i++)
	{
		q = p->prox;
		for(int j = 1; j < len - i; j++)
		{
			q = q->prox;
		}
		free(q);
	}
	free(p);
}
