#ifndef UTILS_H
#define UTILS_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    uint32_t val;
    uint32_t count;
    struct node *next;
} node_t;

void push_end(node_t *head, uint32_t val);
void push_head(node_t *head, uint32_t val);
void ordered_insert(node_t *head, uint32_t val);
void print_list(node_t *head);

#endif 