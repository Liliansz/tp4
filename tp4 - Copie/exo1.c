#include <stdio.h>

#define PENDU 10
#define LMIN 3
#define LMAX 16

int main() {
    int longueur = 0;

    printf("Choisissez un mot de %d à %d lettres. \n", LMIN, LMAX);

    printf("De combien de lettre, le mot que je dois deviner se compose-t-il ? ");
    scanf("%d", &longueur);

    while(longueur < LMIN || longueur > LMAX){
        if(longueur < LMIN){
            printf("Allons, je suis plus joueur que cela: %d, ça n'est pas assez !\n", longueur);
        } else if (longueur > LMAX) {
            printf("Vous y allez un peu fort... %d, c'est beaucoup !\n", longueur);
        }

        printf("Choisissez un nouveau mot de %d à %d lettres.\n", LMIN, LMAX);
        printf("De combien de lettres ce mot se compose-t-il ? ");
        scanf("%d", &longueur);
    }

    printf("Parfait ! On joue avec un mot de %d lettres.\n", longueur);

    return 0;
}