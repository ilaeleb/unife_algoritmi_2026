#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(long double *data, uint32_t start, uint32_t end);
void merge_sort(long double *data, uint32_t start, uint32_t end);
void double_merge_sort(long double *master, long double *child, uint32_t start, uint32_t end);

#endif