#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// LINKED LISTS

typedef struct node {
    long double val;
    long int count;
    struct node *next;
} node_t;

void push_end(node_t *head, long double val);
void push_head(node_t *head, long double val);
void ordered_insert(node_t *head, long double val);
void print_list(node_t *head);

// ARRAYS

void print_array(long double *array, uint32_t size);

#endif 