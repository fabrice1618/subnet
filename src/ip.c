#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "ip.h"
#include "cli.h"
#include "subnet_error.h"

unsigned int ip2int(struct ip_address ip_address)
{
    int result = 0;

    result |= ip_address.byte1 << 24;
    result |= ip_address.byte1 << 16;
    result |= ip_address.byte1 << 8;
    result |= ip_address.byte4;

    return result;
}

void set_ip_address(
    struct ip_address *ip_address,
    int octet1, 
    int octet2, 
    int octet3, 
    int octet4
    )
{

    if (! (BYTE_RANGE(octet1) && BYTE_RANGE(octet2) && BYTE_RANGE(octet3) && BYTE_RANGE(octet4) ) )
        exit_error(ERROR_IPADDR);

    ip_address->byte1 = octet1;
    ip_address->byte2 = octet2;
    ip_address->byte3 = octet3;
    ip_address->byte4 = octet4;

}

void set_net_address(
    struct net_address *net_address,
    int octet1, 
    int octet2, 
    int octet3, 
    int octet4,
    int cidr
    )
{

    if (!CIDR_RANGE(cidr))
        exit_error(ERROR_NETADDR);

    set_ip_address( &net_address->ip_address, octet1, octet2, octet3, octet4 );

    net_address->cidr = cidr;

}

bool null_net_address( struct net_address net_address )
{
    return 
        net_address.ip_address.byte1 == 0 &&
        net_address.ip_address.byte2 == 0 &&
        net_address.ip_address.byte3 == 0 &&
        net_address.ip_address.byte4 == 0 &&
        net_address.cidr == 0;
}


// Vérifier si le nombre est une puissance de 2
bool puissance2(int nombre)
{      
    return ((nombre & (nombre - 1)) == 0);
}

unsigned int cidr2int(unsigned char cidr)
{
    return (0xFFFFFFFF << (32 - cidr));
}

bool subnet_valid(struct net_address adresse_reseau)
{
    unsigned int masque = cidr2int(adresse_reseau.cidr);
    unsigned int ipaddr = ip2int(adresse_reseau.ip_address);

    if (ipaddr & (~masque) )
        // Il existe des bits à 1 dans la partie à 0 du masque
        exit_error(ERROR_NETADDR);

    return true;
}

bool private_subnet(struct net_address adresse_reseau)
{
    printf("private_subnet ");
    print_net_address(adresse_reseau);

    return true;
}
