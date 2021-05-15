#define THIS_IS_MAIN

#include "fh.h"
#include "get_gal.h"


struct galaxy_data galaxy;

int main(argc, argv)

int argc;

char *argv[];

{
    /* Check for valid command line. */
    if (argc != 1) {
        fprintf(stderr, "\n\tUsage: TurnNumber\n\n");
        exit(0);
    }

    /* Get galaxy data. */
    get_galaxy_data();

    /* Print the current turn number. */
    printf("%d\n", galaxy.turn_number);

    exit(0);
}
