#include "fh.h"
#include "do_neutral.h"
#include "parse.h"
#include "get_spnam.h"
#include "utils.h"

extern int   abbr_type, g_spec_number;
extern char  input_line[256], g_spec_name[32];
extern FILE *log_file;
extern struct species_data *species;

void do_NEUTRAL_command() {
    int i, array_index, bit_number;

    long bit_mask;


    /* See if declaration is for all species. */
    if (get_value()) {
        bit_mask = 0;
        for (i = 0; i < NUM_CONTACT_WORDS; i++) {
            species->enemy[i] = bit_mask;       /* Clear all enemy bits. */
            species->ally[i]  = bit_mask;       /* Clear all ally bits. */
        }
    }else {
        /* Get name of species. */
        if (!get_species_name()) {
            fprintf(log_file, "!!! Order ignored:\n");
            fprintf(log_file, "!!! %s", input_line);
            fprintf(log_file, "!!! Invalid or missing argument in NEUTRAL command.\n");
            return;
        }

        /* Get array index and bit mask. */
        array_index = (g_spec_number - 1) / 32;
        bit_number  = (g_spec_number - 1) % 32;
        bit_mask    = 1 << bit_number;

        /* Clear the appropriate bit. */
        species->enemy[array_index] &= ~bit_mask; /* Clear enemy bit. */
        species->ally[array_index]  &= ~bit_mask; /* Clear ally bit. */
    }

    /* Log the result. */
    log_string("    Neutrality was declared towards ");
    if (bit_mask == 0) {
        log_string("ALL species");
    }else{
        log_string("SP ");
        log_string(g_spec_name);
    }
    log_string(".\n");
}
