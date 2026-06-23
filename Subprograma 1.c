#include <stdio.h>
int i = 58, j = 49;
void gg (int i, int j, int k, int m) {
      printf ("%7d%7d%7d%7d\n\n", i, j, k, m);
}
void ff (int p, int q, int *r, int *s) {
      int k, m;
      gg (p, q, *r, *s); k = 100; m = 200;
      p = -1; q = -2; *r = -3; *s = -4;
      gg (i, j, k, m); gg (p, q, *r, *s);
}
main () {
      int i, j, k, m;
      i = 10; j = 20; k = 30; m = 40; gg (i, j, k, m);
      {
            int j, k;
            i = 1; j = 2; k = 3; m = 4;
            gg (i, j, k, m); ff (i, j, &k, &m);
      }
      gg (i, j, k, m);
}
