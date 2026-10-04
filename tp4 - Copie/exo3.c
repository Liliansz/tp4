#include <stdio.h>

#define PENDU 10
#define LMIN 3
#define LMAX 16

int main() {
    int n = 0;      //longueur
    int reste;      // nombre de lettre restant a trouver
    int reponse = 0;    // nombre d occurence de lettre
    int erreurs = 0;    // nombres de fautes
    char mot[LMAX];     // tableau pour stocker le mot devine
    char c;
    int i, pos;

    printf("Choisissez un mot de %d à %d lettres. \n", LMIN, LMAX);

    printf("De combien de lettre, le mot que je dois deviner se compose-t-il ? ");
    scanf("%d", &n);

    while(n < LMIN || n > LMAX){
        if(n < LMIN){
            printf("Allons, je suis plus joueur que cela: %d, ça n'est pas assez !\n", n);
        } else if (n > LMAX) {
            printf("Vous y allez un peu fort... %d, c'est beaucoup !\n", n);
        }

        printf("Choisissez un nouveau mot de %d à %d lettres.\n", LMIN, LMAX);
        printf("De combien de lettres ce mot se compose-t-il ? ");
        scanf("%d", &n);
    }

    //  --- 2. Initialisation du tableau mot avec les underscores ---
    for (i = 0; i < n; i++) {
        mot[i] = '_';
    }
    reste = n;  //Au depart, toutes les lettres sont a trouver 

    // --- 3. Boucle principale du jeu ---
    for(c = 'a'; c <= 'z' && erreurs < PENDU && n > 0; c++){

        // Affichage de la question avec le moit actuel
        printf("Combien de %c dans le mot à deviner ?", c);
        for(i = 0; i < n; i++){
            printf("%c ", mot[i]);
        }
        printf("à deviner");
        scanf("%d", &reponse);

        if(reponse == 0){
            erreurs++;  // La lettre n est pas dans le mot
        } else {
            if (reponse == reste) {
                for (i = 0; i < n; i++) {
                    if (mot[i] == '_') {
                        mot[i] = c;
                    }
                }
                reste = 0;
            } else {
                // Question 4 : Demande des positions une par une
                printf("En quelles positions (la 1è lettre en position 0) ? ");
                for (i = 0; i < reponse; i++) {
                    scanf("%d", &pos);
                    if (pos >= 0 && pos < n) {
                        mot[pos] = c;
                    }
                }
                reste =- reponse;
            }
        }
    }

    // --- 4. Affichage de fin ---
    if (reste == 0) {
        printf("Ouf, je l'ai échappé belle: j'ai deviné le mot ");
        for (i = 0; i < n; i++) {
            printf("%c ", mot[i]);
        }
        printf("!\n");
    } else {
        printf("J'ai perdu, je suis pendu :(\n");
    }
    
    return 0;
}