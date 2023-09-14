#include <stdio.h>
#include <stdlib.h>

struct competidor {
    int number;
    char name[21];
  };
  typedef struct competidor Competidor;

int main(void) {
  int n, i, j, carNumber, passage;
  Competidor **p, *assist;
  
  do {
    scanf("%d", &n);
  } while (n < 3 || n > 1000);
  
  p = (Competidor **)malloc(n*sizeof(Competidor *));
  if (p == NULL) {
    return 1;
  }

  for (i = 0; i < n; i++) {
    p[i] = (Competidor *)malloc(sizeof(Competidor));
    if (p[i] == NULL) {
      return 1;
    }
    scanf("%d %s", &p[i]->number, p[i]->name);
  }
  
  for (i = 0; i < n; i++) {
    scanf("%d", &carNumber);
    for (j = 0; j < n; j++) {
      if (p[j]->number == carNumber) {
        assist = p[i];
        p[i] = p[j];
        p[j] = assist;
        j = n;
      }
    }
  }

  do {
    scanf("%d", &passage);
    if (passage != p[0]->number) {
      for (i = 1; i < n; i++) { 
        if (passage == p[i]->number) {
          assist = p[i];
          p[i] = p[i-1];
          p[i-1] = assist;
          i = n;
        }
      }
    }
  } while (passage != -1);

for (i = 0; i < 3; i++) {
    printf("%d %s\n", p[i]->number, p[i]->name);
  }
  
  for (i = 0; i < n; i++) {
    free(p[i]);
  }
  free(p);
  
  return 0;
}