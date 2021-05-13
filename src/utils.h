#include "fh.h"

int rnd (unsigned int max);
void delete_nampla (struct nampla_data	*nampla);
int life_support_needed (struct species_data *species, struct planet_data *home, struct planet_data *colony);
void log_message (char *message_filename);
void get_location_data ();
void get_species_data ();
void log_string (char *string);
void log_int (int value);
void log_char (char c);
void log_long (long value);
void log_string (char *string);
char *ship_name (struct ship_data *ship);
int undistorted (int distorted_species_number);
int agrep_score (char *correct_string, char *unknown_string);
int distorted (int species_number);
void save_species_data ();
void free_species_data ();
void delete_ship (struct ship_data *ship);
int check_population (struct nampla_data *nampla);
char *commas (long value);
int star_visited (int x, int y, int z);