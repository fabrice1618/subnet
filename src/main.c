#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <libgen.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#include "cli.h"
#include "test.h"
#include "decoupage.h"
#include "subnet_error.h"

#define FILENAME_LEN_MAX    50

int main(int argc, char* argv[]) 
{
    char program_name[FILENAME_LEN_MAX+1];
    bool option_help = false;
    bool option_version = false;
    bool option_licence = false;
    char* test_file = NULL;
    bool mode_interactive = false;

    // Gestion des options longues
    struct option long_options[] = {
        {"num_subnets", required_argument, 0, 'n'},
        {"test", required_argument, 0, 't'},
        {"interactive", no_argument, 0, 'i'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"licence", no_argument, 0, 'l'},
        {0, 0, 0, 0}
    };
    int opt;

    struct net_address adresse_reseau;
    int n_subnet;

    assert(strlen(basename(argv[0])) <= FILENAME_LEN_MAX);
    strcpy(program_name, basename(argv[0]));

    set_net_address( &adresse_reseau, 0, 0, 0, 0, 0 );
    n_subnet = 0;

    // Analyse des arguments et options de la ligne de commande
    while ((opt = getopt_long(argc, argv, "n:t:ihvl", long_options, NULL)) != -1 ) {
        
        switch (opt) {
            case 'n':
                n_subnet = atoi(optarg);
                if (n_subnet < 1) {
                    exit_error(ERROR_NUMBER_SUBNET);
                }
                break;
            case 'i':
                mode_interactive = true;
                break;
            case 't':
                test_file = optarg;
                break;
            case 'h':
                option_help = true;
                break;
            case 'v':
                option_version = true;
                break;
            case 'l':
                option_licence = true;
                break;
            case '?':
                // getopt renvoie ici, si un paramètre obligatoire est manquant
                // dans ce cas optopt contient le code de l'option
                // où le paramètre est manquant
                
                if (optopt == 't') {
                    // le nom du fichier de test est manquant
                    exit_error(ERROR_UNDEF_TEST_FILE);
                }
                if (optopt == 'n') {
                    // le nombre de sous-réseaux est manquant
                    exit_error(ERROR_UNDEF_NUMBER_SUBNET);
                }

                // Option inconnue
//                printf("Unknown option: %c\n", optopt);
                exit_error(ERROR_UNKNOWN_OPTION);
                break;
            default:
//                printf("Unknown option: %c\n", opt);
                exit_error(ERROR_UNKNOWN_OPTION);
                break;
        }
    }

    // ** execution des actions
    // Partie 1: Version, License ou aide
    if (option_version) 
        display_version(program_name);

    if (option_licence) 
        display_licence(program_name);

    if (option_help || argc == 1) 
        display_help(program_name);

    // Si une des options de la partie 1 est executée
    // Quitter le programme sans erreur
    if (option_help || option_licence || option_version) 
        return EXIT_SUCCESS;

    // Partie 2 : Test de l'application avec fichier json
    if (test_file) {
        run_test(test_file);
        return EXIT_SUCCESS;
    }

    // Partie 3 : Récupération de l'argument adresse (il reste un argument a traiter)
    // Déterminer les valeurs de l'adresse réseau
    if (optind + 1 < argc) {
        exit_error(ERROR_ARGUMENT_EXCESS);
    } 

    if (optind < argc) {
        if (! get_adresse_reseau_from_str(&adresse_reseau, argv[optind])) {
            exit_error(ERROR_NETADDR);
        }
    } 

    // Saisie interactive sur stdin
    // Demander les valeurs pas encore initialisées par ligne de commande
    if (mode_interactive) {
        printf("Entering interactive mode\n");

        if (null_net_address( adresse_reseau )) {
            if (! get_adresse_reseau_from_stdin(&adresse_reseau) ) {
                exit_error(ERROR_UNDEF_NETADDR);
            }
        }

        if (n_subnet == 0) {
            if (get_nombre_sous_reseau_from_stdin(&n_subnet)) {
                exit_error(ERROR_UNDEF_NUMBER_SUBNET);
            }
        }
    } 

    decoupage_sous_reseau(adresse_reseau, n_subnet);

    return EXIT_SUCCESS;
}


