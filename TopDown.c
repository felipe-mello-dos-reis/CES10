#include <stdio.h>

typedef char cadeia[31];
struct entr_tab{
	caseia nome; int n_ocorr;
}
FILE *f1; int ntab, posic; entr_tab tabela[100]; cadeia palavra; 

int Posição (cadeia palavra) {
     int inf, sup, med, posic; logic achou;
     achou = FALSE; inf = 1; sup = ntab;
     while (! achou && sup >= inf) {
          med = (inf + sup) / 2;
          if (palavra == tabela[med].nome)
               achou = TRUE;
          else if (palavra < tabela[med].nome)
               sup = med – 1;
          else inf = med + 1;
     }
     if (achou) posic = med;
     else posic = - inf;
     return posic;
}
Inserir (cadeia palavra, int posic) {
     int i;
     ntab++;
     for (i = ntab; i > posic; i--)
          tabela[i] = tabela[i-1];
     tabela[posic].nome = palavra;
     tabela[posic].n_ocorr = 1;
}
ExibirTabela () {
     int i;
     write (“Palavra”, “|”, “Num. de ocorr”);
     write (“\n”, “--------------------------------------------------”);
     for (i = 1; i <= ntab; i++)
          write (“\n”, tabela[i].nome, “|”, tabela[i].n_ocorr);
}

int main ()
{
ContarPalavras {
    fl = open (“ctpalavras.txt”, “read”);
    ntab = 0;
      
    while (readfile (fl, palavra) == 1) {
        posic = Posicao (palavra);
        if (posic > 0)
            tabela[posic].n_ocorr++;
        else
            Inserir (palavra, -posic);
         
    }
    ExibirTabela ();
    return 0;
}
