#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct {
    char letter;
    uint8_t *values;
} delta;

delta *compute_delta_matrix(char *pattern, uint8_t lenght);
void print_indexes(char *pattern, char *text, uint8_t pattern_lenght, uint32_t text_lenght);
int32_t search_pattern(char *pattern, char *text, uint8_t pattern_lenght, uint32_t text_lenght, int32_t *index);
void print_matrix(delta *matrix, uint8_t lenght);

#endif