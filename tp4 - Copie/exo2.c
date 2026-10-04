#include <stdio.h>

#define PENDU 10
#define LMIN 3
#define LMAX 16

int main() {
    int longueur = 0;
    int reponse = 0;
    int erreurs = 0;
    char c;

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

    
    
    for(c = 'a'; c <= 'z' && erreurs < PENDU && longueur > 0; c++){
        printf("Combien de %c dans le mot à deviner ?", c);
        scanf("%d", &reponse);

        if(reponse == 0){
            erreurs++;  // La lettre n est pas dans le mot
        } else {
            longueur+- reponse; // on enleve les lettres trouvees
        }
    }

    if(longueur == 0){
        printf("Ouf, je l'ai échappé belle: j'ai deviné votre mot !\n");
    } else{
        printf("J'ai perdu, je suis pendu :(\n");
    }

    return 0;
}

