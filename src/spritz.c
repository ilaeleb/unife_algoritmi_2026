#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <stdint.h>


#include <utils.h>
#include <sort.h>

// #define INPUT_FILE "input_output/input_spritz.txt"
// #define OUTPUT_FILE "input_output/output_spritz.txt"

// #define INPUT_FILE "input_output/input_spritz_small.txt"
// #define OUTPUT_FILE "input_output/output_spritz_small.txt"

#define INPUT_FILE "input_output/input_spritz_big.txt"
#define OUTPUT_FILE "input_output/output_spritz_big.txt"

// #define INPUT_FILE "input.txt"
// #define OUTPUT_FILE "output.txt"

void merge_sort(long double *data, uint32_t start, uint32_t end);
void double_merge_sort(long double *master, long double *child, uint32_t start, uint32_t end);

int main() {

    LARGE_INTEGER start, end, freq, t_sort_start, t_sort_end, t_diff_start, t_diff_end;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);

    FILE *input = fopen(INPUT_FILE, "r");

    if (input == NULL) {
        printf("File not found.\n");
        return -1;
    }

    uint32_t n_bars, n_radii; // 1 - 10e5 

    fscanf(input, "%u %u", &n_bars, &n_radii);

    long double *data = malloc(n_bars * sizeof(long double));

    uint32_t i;
    int32_t x, y, z;

    for (i = 0; i < n_bars; i++) {
        fscanf(input, "%d %d %d", &x, &y, &z);
        data[i] = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    }

    merge_sort(data, 0, n_bars - 1);

    FILE *output = fopen(OUTPUT_FILE, "w");

    long double *radii = malloc(n_radii * sizeof(long double));
    long double *position = malloc(n_radii * sizeof(long double));
    long double *count = malloc(n_radii * sizeof(long double));
    
    for (i = 0; i < n_radii; i++) {
        fscanf(input, "%Lf", &radii[i]);
        position[i] = (double)i;
    }

    double_merge_sort(radii, position, 0, n_radii - 1);

    uint32_t c = 0, j = 0; 

    for (i = 0; i < n_radii; i++) {
        for ( ; j < n_bars; j++) {
            if (data[j] <= radii[i]) {
                c += 1;
            } else break;  
        }
        count[i] = c;
    } 

    double_merge_sort(position, count, 0, n_radii - 1);

    for (i = 0; i < n_radii; i++) {
        fprintf(output, "%.0Lf\n", count[i]);
    }

    QueryPerformanceCounter(&end);
    double time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Tempo esecuzione: %.6f sec\n", time);    

    free(data);
    fclose(input);
    fclose(output);
}

