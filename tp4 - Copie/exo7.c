#include <stdio.h>

#define N 100000

int main() {
    int est_premier[N + 1]; 
    int n, d;

    // 0 et 1 ne sont pas premiers 
    est_premier[1] = est_premier[0] = 0;

    /* Les entiers
        - 0 et 1 ne sont pas premiers
        - i >= 2, <= N sont supposés premiers "jusqu'à preuve du contraire" */

    
    // Au depart, tous les nombres >= 2 sont supposes premiers
    for(n = 2 ; n <= N ; n ++) {
        est_premier[n] = 1;
    }


    // Crible d’Ératosthène
    n = 2; 
    while(n <= N){
        for (d = n; d * n <= N; d++){
            est_premier[d * n] = 0; 
        }

        n++; 
        while (n <= N && est_premier[n] == 0){
            n++;
        }
    }


    printf("j'ai trouver tous les premiers, quel nombre souhaitez-vous ?\n");
    scanf("%d", &n);

    if (n >= 0 && n <= N){
        if (est_premier[n]) {
            printf("%d est premier\n",n);
        }
        else {
            printf("%d n'est pas premier\n",n);
        }
    } else{
        printf("Nombre hors limites (doit etre entre 0 et %d).\n", N);
    }
    
    return 0;
}