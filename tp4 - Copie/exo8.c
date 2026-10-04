/* 

1. Adaptation du code (suppression de l'interaction utilisateur)Comme indiqué dans la consigne, 
pour mesurer uniquement le temps d'exécution des algorithmes sans attendre une saisie au clavier, 
il faut commenter (ou supprimer) la partie scanf / printf finale dans les deux fichiers 
(premiers.c et crible.c).   Tu remplaces la fin par :C    

/* Bloc d'affichage commente pour le test de performance

    printf("j'ai trouve tous les premiers, quel nombre souhaitez-vous ?\n");
    scanf("%d", &n);
    if (est_premier[n]) printf("%d est premier\n", n);
    else printf("%d n'est pas premier\n", n);
    */

    return 0;
}

/*
Commandes à exécuter dans le terminalBashgcc -Wall premiers.c -o premiers
gcc -Wall eratosthene.c -o crible
time ./premiers
time ./crible


2. Ce qu'on observe et explications

Observation :
    Le programme crible est considérablement plus rapide que premiers.Pour $N = 100\ 000$, 
    crible s'exécute quasi-instantanément (quelques millisecondes), alors que premiers prend 
    nettement plus de temps (surtout si tu augmentes $N$, par exemple à $500\ 000$).
    
    Est-ce ce à quoi on s'attendait ?
    Oui, c'est tout à fait logique :
        
        Algo naïf (premiers.c) : Pour chaque nombre $n$, il effectue une boucle pour chercher 
        son plus petit diviseur. La complexité globale est d'environ O(N racine{N}), ce qui 
        fait des dizaines de millions d'opérations de division (qui sont gourmandes en calcul 
        pour le processeur).
        
        Crible d'Ératosthène (crible.c) : Il ne fait pas de divisions, mais seulement des 
        affectations directes dans le tableau (est_premier[d * n] = 0). 
        Sa complexité est en O(N log(log N)), ce qui nécessite extrêmement peu d'opérations.*/