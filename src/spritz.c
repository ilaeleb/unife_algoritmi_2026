#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include <utils.h>

int main() {
    FILE *input = fopen("input.txt", "r");

    if (input == NULL) {
        printf("File not found.\n");
        return -1;
    }

    int32_t n_bars, n_radii;

    fscanf(input, "%d %d", &n_bars, &n_radii);

    if (n_bars == 0) {
        return -1;
    }

    int32_t x, y, z;    

    fscanf(input, "%d %d %d", &x, &y, &z);
    long double distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

    node_t * bars_list = NULL;
    bars_list = (node_t *) malloc(sizeof(node_t));

    if (bars_list == NULL) {
        return -1;
    }

    bars_list->val = distance;
    bars_list->count = 1;
    bars_list->next = NULL;

    int i;
    for (i = 1; i < n_bars; i++) {
        x = y = z = 0;
        fscanf(input, "%d %d %d", &x, &y, &z);
        distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        ordered_insert(bars_list, distance);
    }

    FILE *output = fopen("output.txt", "w");;

    int j;
    for (j = 0; j < n_radii; j++) {
        node_t * current = bars_list;
        int32_t radius, count;

        fscanf(input, "%d", &radius);
        
        count = 0;
        while (current != NULL && current->val <= radius) {
            
            count += current->count;
            current = current->next;
        }   
        fprintf(output, "%d\n", count);
        current = bars_list;
    }

    free(bars_list);
    fclose(input);
    fclose(output);
}

