#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// La firma può essere lunga 10^6 caratteri 

typedef struct {
    char letter;
    uint32_t *values;
} delta;

delta *compute_delta_matrix(char *pattern, uint8_t lenght);

#endif