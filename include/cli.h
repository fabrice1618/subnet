#ifndef CLI_H
#define CLI_H

#include <stdbool.h>

#include "ip.h"

#define PROGRAM_VERSION     "0.1"

bool get_adresse_reseau_from_stdin(struct net_address *adresse_reseau);
bool get_adresse_reseau_from_str(struct net_address *adresse_reseau, char* chaine);
bool get_nombre_sous_reseau_from_stdin( int *n_subnet);
void print_ip_address(struct ip_address adresse_ip);
void print_net_address(struct net_address adresse_reseau);
void display_help( char *program_name);
void display_version( char *program_name);
void display_licence( char *program_name);

#endif