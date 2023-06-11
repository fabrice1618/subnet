#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "subnet_error.h"

void exit_error(ErrorCode code) 
{
    assert(code >= ERROR_NONE && code <= ERROR_ARGUMENT_EXCESS );

    const char* errorMessages[] = {
        ERROR_MSG_NONE,
        ERROR_MSG_NETADDR,
        ERROR_MSG_NUMBER_SUBNET,
        ERROR_MSG_IPADDR,
        ERROR_MSG_UNDEF_NETADDR,
        ERROR_MSG_UNDEF_NUMBER_SUBNET,
        ERROR_MSG_UNDEF_TEST_FILE,
        ERROR_MSG_UNKNOWN_OPTION,
        ERROR_MSG_ARGUMENT_EXCESS
    };

    fprintf(stderr, "Erreur: %s\n", errorMessages[code]);
    exit(code);
}
