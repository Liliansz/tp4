#include <stdio.h>
#include <stdlib.h> // Pour rand, srand
#include <time.h>   // Pour time

#define PENDU 10
#define LMIN 3
#define LMAX 16
#define NB_LETTRES 26

int main() {
    // Initialisation de la graine aleatoire
    srand(time(NULL));

    char rejouer = ' ';

    do {
        int n = 0;           // Longueur du mot
        int reste = 0;       // Nombre de lettres restant a trouver
        int reponse = 0;     // Nombre d'occurrences
        int erreurs = 0;     // Nombre de fautes
        char mot[LMAX];      // Tableau du mot devine
        int propositions[NB_LETTRES]; // Tableau pour eviter les doublons
        char c;
        int i, pos, indice;

        // Initialisation du tableau des propositions : 0 = pas encore proposee
        for (i = 0; i < NB_LETTRES; i++) {
            propositions[i] = 0;
        }

        // --- 1. Saisie de la longueur ---
        printf("Choisissez un mot de %d à %d lettres.\n", LMIN, LMAX);
        printf("Vous êtes prêt ? Moi aussi !\n");

        printf("De combien de lettres le mot que je dois deviner se compose-t-il ? ");
        scanf("%d", &n);

        while (n < LMIN || n > LMAX) {
            if (n < LMIN) {
                printf("Allons, je suis plus joueur que cela: %d, ça n'est pas assez !\n", n);
            } else {
                printf("Vous y allez un peu fort ... %d, c'est beaucoup !\n", n);
            }
            printf("Choisissez un nouveau mot de %d à %d lettres.\n", LMIN, LMAX);
            printf("De combien de lettres ce mot se compose-t-il ? ");
            scanf("%d", &n);
        }

        // Initialisation du mot avec des underscores '_'
        for (i = 0; i < n; i++) {
            mot[i] = '_';
        }
        reste = n;

        // --- 2. Boucle de jeu avec tirage aleatoire ---
        while (erreurs < PENDU && reste > 0) {
            
            // Tirage d'une lettre au hasard JAMAIS proposee
            do {
                indice = rand() % NB_LETTRES;
                c = 'a' + indice;
            } while (propositions[indice] == 1);

            // On marque la lettre comme proposee
            propositions[indice] = 1;

            // Affichage de la question avec le mot masque
            printf("Combien de %c dans le mot ", c);
            for (i = 0; i < n; i++) {
                printf("%c ", mot[i]);
            }
            printf("à deviner ? ");
            scanf("%d", &reponse);

            if (reponse == 0) {
                erreurs++;
            } else {
                // Si toutes les lettres restantes sont trouvees d'un coup
                if (reponse == reste) {
                    for (i = 0; i < n; i++) {
                        if (mot[i] == '_') {
                            mot[i] = c;
                        }
                    }
                    reste = 0;
                } else {
                    // Saisie des positions des lettres trouvees
                    printf("En quelles positions (la 1è lettre en position 0) ? ");
                    for (i = 0; i < reponse; i++) {
                        scanf("%d", &pos);
                        if (pos >= 0 && pos < n) {
                            mot[pos] = c;
                        }
                    }
                    reste = reste - reponse;
                }
            }
        }

        // --- 3. Fin de la partie ---
        if (reste == 0) {
            printf("Ouf, je l'ai échappé belle: j'ai deviné le mot ");
            for (i = 0; i < n; i++) {
                printf("%c ", mot[i]);
            }
            printf("!\n");
        } else {
            printf("J'ai perdu, je suis pendu :(\n");
        }

        // Demande pour rejouer
        printf("\nAppuyez sur 'q' pour quitter ou une autre touche pour rejouer : ");
        scanf(" %c", &rejouer);

    } while (rejouer != 'q' && rejouer != 'Q');

    printf("Merci d'avoir joué ! À bientôt.\n");

    return 0;
}