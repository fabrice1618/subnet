# Découpage de sous-réseau

## Besoin

- En entrée donner :
    - une adresse de réseau en notation CIDR (exemple 192.168.3.0/24)
    - le nombre de sous-réseaux à créer
- Le programme calcule et affiche les caractéristiques des sous-réseaux
- Le programme affiche pour chacun des sous-réseaux :
    - l'adresse du sous-réseau en notation CIDR
    - l'adresse de broadcast
    - l'adresse du premier hôte du sous-réseau
    - l'adresse du dernier hôte du sous-réseau
- Chaque sous-réseau est de taille identique
- Le nombre de sous-réseaux est une puissance de 2
- Le réseau en entrée doit être un réseau privé
- Le programme doit pouvoir traiter les fichiers test*.txt contenant les données d'entrée de test
- utiliser au maximum les opérateurs binaires AND, OR, XOR, décalage de bits...
- Penser votre programme comme un programme UNIX:
    - Le programme utilise des codes de retour au shell (0=OK, 1=erreur, 2=autre erreur...)
    - utiliser les flux standards stdin, stdout, stderr
    - le programme ne fait pas de boucles de saisie
    - le programme prends des entrées et retourne le code de retour, affiche ce qui est nécessaire, puis exit()
    - Vous pourrez donc tester votre programme automatiquement, exemple:
        - cat test01.txt | mon_programme  
        - cat test02.txt | mon_programme  
- utiliser les structures de données (struct), cela sera une bonne introduction à la programmation orientée objet pour la 2ème année

## pédagogie

- niveau de développement de fin de première année
- notions réseau
- opérations binaires
- notions de système UNIX
- structuration (architecture) d'un programme complexe
- tester votre programme par petits bouts (tests unitaires)
- essayer de garder les aides extérieures au minimum (collègues, chat tout-pété)
- vous utiliserez les pointeurs
- bonne utilisation des fonctions
- c'est un chemin personnel qui vous permettra de consolider vos connaissances
- utilisation de l'allocation dynamique de mémoire pour les résultats
- utilisation des directives de compilation

## exemples d'exécution



## évolutions

- Découper le sous-réseau en entrée en un nombre arbitraire de sous-réseaux. Pour chacun d'entre eux, donner le nombre de machines que chacun pourra héberger
- Passer les données en argument du programme: 
    - mon_programme 192.168.3.0/24 2
