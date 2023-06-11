#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ip.h"
#include "cli.h"
#include "subnet_error.h"

bool get_adresse_reseau_from_stdin(struct net_address *adresse_reseau) 
{
    int octet1, octet2, octet3, octet4;
    int cidr;
    int n_val;
    
    printf("Entrez l'adresse réseau en notation CIDR (format : x.x.x.x/cidr) : ");
    n_val = scanf("%d.%d.%d.%d/%d", &octet1, &octet2, &octet3, &octet4, &cidr); 
    while (getchar() != '\n'); // vider le buffer d'entrée

    if ( n_val != 5 )
        exit_error(ERROR_NETADDR);

    set_net_address( adresse_reseau, octet1, octet2, octet3, octet4, cidr );

    return true;
}

bool get_adresse_reseau_from_str(struct net_address *adresse_reseau, char* chaine)
{
    int octet1, octet2, octet3, octet4;
    int cidr;
    int n_val;
    
    n_val = sscanf(chaine, "%d.%d.%d.%d/%d", &octet1, &octet2, &octet3, &octet4, &cidr); 

    if ( n_val != 5 )
        exit_error(ERROR_NETADDR);

    set_net_address( adresse_reseau, octet1, octet2, octet3, octet4, cidr );

    return true;
}

bool get_nombre_sous_reseau_from_stdin( int *n_subnet)
{
    unsigned int nombre_sous_reseaux;

    printf("Entrez le nombre de sous-réseaux : ");
    scanf("%ud", &nombre_sous_reseaux);

    if ( nombre_sous_reseaux <= 1 || !puissance2(nombre_sous_reseaux) )
        exit_error(ERROR_NUMBER_SUBNET);

    *n_subnet = nombre_sous_reseaux;
    return true;
}

void print_ip_address(struct ip_address adresse_ip)
{

    printf( "%d.%d.%d.%d", adresse_ip.byte1, adresse_ip.byte2, adresse_ip.byte3, adresse_ip.byte4 );

}

void print_net_address(struct net_address adresse_reseau)
{

    printf(
        "%d.%d.%d.%d/%d", 
        adresse_reseau.ip_address.byte1,
        adresse_reseau.ip_address.byte2,
        adresse_reseau.ip_address.byte3,
        adresse_reseau.ip_address.byte4,
        adresse_reseau.cidr
        );

}

void display_help(char *program_name) 
{
    printf("Usage: %s [-n num_subnets] [-t test_file] [-i] [-h] [-v] [adresse_reseau]\n", program_name);
    printf("Options:\n");
    printf("  -n, --num_subnets=num   Specify the number of subnets to divide\n");
    printf("  -t  --test[=test_file]  Enable test mode using the specified file\n");
    printf("  -i, --interactive       Enable interactive mode\n");
    printf("  -h, --help              Display this help message\n");
    printf("  -v, --version           Display the version number\n");
    printf("  -l, --licence           Display the licence\n");
}

void display_version(char *program_name)
{
    static bool printed = false;

    if (!printed) {
        printf("%s version:%s\n", program_name, PROGRAM_VERSION);
        printed = true;
    }    
}

void display_licence(char *program_name)
{
    display_version(program_name);

    printf("Copyright © 2023 fabrice1618\n");
    printf("License GPLv3+ : GNU GPL version 3 ou ultérieure <https://www.gnu.org/licenses/gpl.fr.html>\n");
    printf("Ceci est un logiciel libre. Vous êtes libre de le modifier et de le redistribuer.\n");
    printf("Ce logiciel n'est accompagné d'ABSOLUMENT AUCUNE GARANTIE, dans les limites permises par la loi.\n");

}
