#include "system.h"
#include "counter.h"
#include "../../fonts/font5x7_1.h"
#include "tinygl.h"
#include "pio.h"
#include "game_initialise.h"
#include "pacer.h"
#include "objects.h"


#include <stdint.h>
#include <stdlib.h>

#define SEED 2000

void game_initialise_init(uint16_t pacer_rate, uint16_t num_obstacles)
{
    system_init ();
    counter_init();
    pacer_init (pacer_rate); //Refresh rate of 500Hz
    tinygl_init (pacer_rate); //Setup for score display
    tinygl_font_set (&font5x7_1);
    srand(SEED);
    game_initialise_random(num_obstacles);
    game_initialse_set_vars();
    
}

void game_initialse_set_vars(void)
{
    score = 0;
    current_column = 0;
    to_copy = false;
    timeout = false;
    timeout_counter = 0;
}

void game_initialise_random(uint16_t num_obstacles)
{
    random_number = rand() % num_obstacles;
}

void game_initialise_set_display(uint16_t num_rows)
{
    for (uint8_t i = 0; i < num_rows; i++) {
        if (i < num_rows) {
            pio_config_set(cols[i], PIO_OUTPUT_HIGH);
        }
        pio_config_set(rows[i], PIO_OUTPUT_HIGH);
    }
}