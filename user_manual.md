# Nom du programme : subnet

## Description

subnet est un programme en ligne de commande qui permet de générer les sous-réseaux d'une adresse réseau donnée à partir d'un nombre de sous-réseau indiqué. Les sous-réseaux ont tous la même taille.

Plusieurs modes de fonctionnement sont disponibles:
- mode interactif: l'utilisateur saisit les information nécessaires
- mode ligne de commande: les information sont fournies dans la ligne de commannde
- mode test: les informations sont fournies dans un fichier json contenant aussi les résultats attendus

## Syntaxe

```bash
subnet [OPTION].... [adresse_reseau]
```

Options :

    * adresse_reseau 
        L'adresse réseau à traiter. L'adresse est facultative pour les modes test, interactif, aide et version

    -n, --num_subnets=[+]NUM
        Spécifie le nombre de sous-réseaux dans lesquels diviser l'adresse réseau.

    -i, --interactive
        Les informations adresse réseau et nombre de sous-réseaux sont fournies par l'utilisateur sur l'entrée standard

    -t, --test=[+]test__nn__.json
        Active le mode de test et effectue des tests sur les sous-réseaux à partir du fichier spécifié.

    -h, --help  
        Affiche l'aide et les informations sur l'utilisation du programme.

    -v, --version
        Affiche le numéro de version et quitte

    -l, --licence
        Affiche la license et quitte


## Exemples d'utilisation

Diviser l'adresse réseau 192.168.0.0 avec le masque 255.255.255.0 en 4 sous-réseaux :
```bash
subnet -n 4 192.168.0.0/24
```

Activer le mode de test à partir du fichier test01.json :
```bash
subnet -t=test01.json
```

Utilisation interactive pour saisir le nombre de sous-réseaux et l'adresse réseau 
```bash
subnet -i
```

## TODO
- écrire la documentation au format man