#ifndef SUBNET_ERROR_H
#define SUBNET_ERROR_H

// Déclaration des codes d'erreur
typedef enum {
    ERROR_NONE,
    ERROR_NETADDR,
    ERROR_NUMBER_SUBNET,
    ERROR_IPADDR,
    ERROR_UNDEF_NETADDR,
    ERROR_UNDEF_NUMBER_SUBNET,
    ERROR_UNDEF_TEST_FILE,
    ERROR_UNKNOWN_OPTION,
    ERROR_ARGUMENT_EXCESS,
} ErrorCode;

// Messages d'erreur
#define ERROR_MSG_NONE "Aucune erreur."
#define ERROR_MSG_NETADDR "Erreur adresse réseau"
#define ERROR_MSG_NUMBER_SUBNET "Erreur nombre sous-réseau"
#define ERROR_MSG_IPADDR "Erreur adresse IP"
#define ERROR_MSG_UNDEF_NETADDR "Erreur adresse réseau non définie"
#define ERROR_MSG_UNDEF_NUMBER_SUBNET "Erreur nombre sous-réseau non défini"
#define ERROR_MSG_UNDEF_TEST_FILE "Erreur nom du fichier de test non défini"
#define ERROR_MSG_UNKNOWN_OPTION "Unknown option"
#define ERROR_MSG_ARGUMENT_EXCESS "Error excess argument"

// Prototypes
void exit_error(ErrorCode code);

#endif /* ERROR_H */
