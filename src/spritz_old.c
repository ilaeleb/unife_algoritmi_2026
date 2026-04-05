#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#include <utils.h>

// #define INPUT_FILE "input_output/input.txt"
// #define OUTPUT_FILE "input_output/output.txt"

// #define INPUT_FILE "input.txt"
// #define OUTPUT_FILE "output.txt"

int main() {

    LARGE_INTEGER start, end, freq, t_sort_start, t_sort_end, t_diff_start, t_diff_end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    FILE *input = fopen(INPUT_FILE, "r");

    if (input == NULL) {
        printf("File not found.\n");
        return -1;
    }

    long int n_bars, n_radii;

    fscanf(input, "%ld %ld", &n_bars, &n_radii);

    if (n_bars == 0) {
        return -1;
    }

    long int x, y, z;    

    fscanf(input, "%ld %ld %ld", &x, &y, &z);
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
        fscanf(input, "%ld %ld %ld", &x, &y, &z);
        distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        ordered_insert(bars_list, distance);
    }

    FILE *output = fopen(OUTPUT_FILE, "w");;

    int j;
    for (j = 0; j < n_radii; j++) {
        node_t * current = bars_list;
        long int radius, count;

        fscanf(input, "%ld", &radius);
        
        count = 0;
        while (current != NULL && current->val <= radius) {
            
            count += current->count;
            current = current->next;
        }   
        fprintf(output, "%ld\n", count);
        current = bars_list;
    }

    free(bars_list);
    fclose(input);
    fclose(output);

    QueryPerformanceCounter(&end);
    double time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Tempo esecuzione: %.6f sec\n", time);    
}

