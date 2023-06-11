#include <stdio.h>
//#include <stdlib.h>

#include "ip.h"
#include "cli.h"
#include "subnet_error.h"

void decoupage_sous_reseau(struct net_address adresse_reseau, int nombre_sous_reseaux) 
{
    printf("\nDécoupage en sous-réseaux\n");
    print_net_address(adresse_reseau);
    printf("\nNombre de sous-réseaux : %d\n", nombre_sous_reseaux);

    if (nombre_sous_reseaux == 0) {
        exit_error(ERROR_UNDEF_NUMBER_SUBNET);
    }

    if (null_net_address( adresse_reseau )) {
        exit_error(ERROR_UNDEF_NETADDR);
    }

    if (subnet_valid(adresse_reseau) ) {
        printf("Réseau valide\n");
    }
    if (private_subnet(adresse_reseau)) {
        printf("Réseau privé\n");
    }

}
