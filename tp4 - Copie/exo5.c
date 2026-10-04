#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PENDU 10
#define LMIN 3
#define LMAX 16
#define NB_LETTRES 26
#define APP 3

int main() {
    srand(time(NULL));

    // Tableau de statistiques persistant entre les parties
    int stats[NB_LETTRES] = {0};
    int nb_parties = 0;
    char rejouer = ' ';

    do {
        int n = 0;
        int reste = 0;
        int reponse = 0;
        int erreurs = 0;
        char mot[LMAX];
        int propositions[NB_LETTRES] = {0}; // 0 = non proposee, 1 = proposee
        char c;
        int i, pos, indice;

        nb_parties++; // Incrémentation du nombre de parties jouées

        printf("Partie n°%d\n", nb_parties);
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

        for (i = 0; i < n; i++) {
            mot[i] = '_';
        }
        reste = n;

        // Boucle principale de la partie
        while (erreurs < PENDU && reste > 0) {

            // --- Choix de la lettre par l'ordinateur ---
            if (nb_parties <= APP) {
                // Stratégie aléatoire pour les 3 premières parties
                do {
                    indice = rand() % NB_LETTRES;
                } while (propositions[indice] == 1);
            } else {
                // Stratégie basée sur la fréquence (stats)
                int max_freq = -1;

                // 1. Recherche de la fréquence maximale disponible
                for (i = 0; i < NB_LETTRES; i++) {
                    if (propositions[i] == 0 && stats[i] > max_freq) {
                        max_freq = stats[i];
                    }
                }

                // 2. Sélection d'une lettre (avec gestion des ex-æquo au hasard)
                do {
                    indice = rand() % NB_LETTRES;
                } while (propositions[indice] == 1 || stats[indice] != max_freq);
            }

            c = 'a' + indice;
            propositions[indice] = 1; // Marquer comme proposée

            // --- Interaction avec l'utilisateur ---
            printf("Combien de %c dans le mot ", c);
            for (i = 0; i < n; i++) {
                printf("%c ", mot[i]);
            }
            printf("à deviner ? ");
            scanf("%d", &reponse);

            if (reponse == 0) {
                erreurs++;
            } else {
                // Mise à jour du tableau stats
                stats[indice] += reponse;

                if (reponse == reste) {
                    for (i = 0; i < n; i++) {
                        if (mot[i] == '_') {
                            mot[i] = c;
                        }
                    }
                    reste = 0;
                } else {
                    printf("En quelles positions (la 1è lettre en position 0) ? ");
                    for (i = 0; i < reponse; i++) {
                        scanf("%d", &pos);
                        if (pos >= 0 && pos < n) {
                            mot[pos] = c;
                        }
                    }
                    reste -= reponse;
                }
            }
        }

        // --- Fin de partie ---
        if (reste == 0) {
            printf("Ouf, je l'ai échappé belle: j'ai deviné le mot ");
            for (i = 0; i < n; i++) {
                printf("%c ", mot[i]);
            }
            printf("!\n");
        } else {
            printf("J'ai perdu, je suis pendu :(\n");
        }

        printf("\nAppuyez sur 'q' pour quitter ou une autre touche pour rejouer : ");
        scanf(" %c", &rejouer);

    } while (rejouer != 'q' && rejouer != 'Q');

    printf("Merci d'avoir joué ! À bientôt.\n");

    return 0;
}