#ifndef IP_H
#define IP_H

#include <stdbool.h>

#define BYTE_RANGE(x) (x >= 0 && x <= 255)
#define CIDR_RANGE(x) (x >= 0 && x <= 30)

struct ip_address {
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
};

struct net_address {
    struct ip_address ip_address;
    unsigned char cidr;
};

// Prototypes

void set_ip_address(
    struct ip_address *ip_address,
    int octet1, 
    int octet2, 
    int octet3, 
    int octet4
    );

void set_net_address( 
    struct net_address *net_address,
    int octet1, 
    int octet2, 
    int octet3, 
    int octet4,
    int cidr
    );

bool null_net_address( struct net_address net_address );
bool puissance2(int nombre);
unsigned int cidr2int(unsigned char cidr);
bool subnet_valid(struct net_address adresse_reseau);
bool private_subnet(struct net_address adresse_reseau);


#endif