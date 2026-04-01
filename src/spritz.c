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

    int n_bars, n_radii;

    fscanf(input, "%d %d", &n_bars, &n_radii);

    if (n_bars == 0) {
        return -1;
    }

    int i, j = 0, k = 0;
    int32_t x, y, z;    

    fscanf(input, "%lld %lld %lld", &x, &y, &z);
    int32_t distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

    node_t * bars_list = NULL;
    bars_list = (node_t *) malloc(sizeof(node_t));

    if (bars_list == NULL) {
        return -1;
    }

    bars_list->val = distance;
    bars_list->count = 1;

    for (i = 1; i < n_bars; i++) {
        x = y = z = 0;
        fscanf(input, "%lld %lld %lld", &x, &y, &z);
        distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        ordered_insert(bars_list, distance);
    }

    print_list(bars_list);

    FILE *output = fopen("output.txt", "w");;

    free(bars_list);
    fclose(input);
    fclose(output);
}

