#include <stdio.h>
#include <stdlib.h>

typedef struct noh noh;
typedef noh *lista;
typedef noh *posição;
struct noh {
    int elem; noh *prox;
};
lista L;

lista NovaLista (void);
void EscreverLista (lista);
void OrdenarLista (lista);
void Remover (int, lista);

int main () {
    lista L;
    printf ("Leitura de uma lista:\n\n");
    L = NovaLista ();
    printf ("\nLista inicial:");
    EscreverLista (L);
    OrdenarLista (L);
	printf("\nLista ordenada?");
    EscreverLista (L);
    EscreverLista (L);
    Inserir (48, L);
    Remover (52, L);
    Remover (50, L);
    printf ("\nLista modificada:");
    EscreverLista (L);

      printf("\n\n"); system ("pause"); return 0;
}


lista NovaLista () {
    lista L; posicao p;
    int i, n;
    printf ("Numero de elementos da lista: ");
    scanf ("%d", &n);
    printf ("\nElementos:\n\t");
      L = (noh *) malloc (sizeof (noh));
    for (p = L, i = 1; i <= n; i++) {
        p->prox = (noh *) malloc (sizeof (noh));
        p = p->prox;
        scanf ("%d", &p->elem);
    }
    p->prox = NULL;
  return L;
}






void (lista L) {
    posicao p, q, min; int menor;
    for (p = L->prox; p != NULL && p->prox != NULL; 
                                p = p->prox) {
        for (menor = p->elem, min = p, q = p->prox; 
                        q != NULL; q = q->prox) {
            if (q->elem < menor) {
                menor = q->elem; min = q;
            }
        }
        if (min != p) {
            min->elem = p->elem; p->elem = menor;
        }
    }
}

void Remover (int num, lista L) {
    posicao p, q;
    for (p = L; p->prox != NULL && p->prox->elem < num; 
                                p = p->prox);
    if (p->prox != NULL && p->prox->elem == num) {
        q = p->prox;
        p->prox = q->prox;
           free (q);
    }
}
