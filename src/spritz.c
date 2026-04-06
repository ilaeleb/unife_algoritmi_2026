#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <stdint.h>

#include <utils.h>
#include <sort.h>

// #define INPUT_FILE "input_output/input_spritz.txt"
// #define OUTPUT_FILE "input_output/output_spritz.txt"

#define INPUT_FILE "input_output/input_spritz_small.txt"
#define OUTPUT_FILE "input_output/output_spritz_small.txt"

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

    uint16_t n_bars, n_radii; // 1 - 10e5 

    fscanf(input, "%hu %hu", &n_bars, &n_radii);

    long double *data = malloc(n_bars * sizeof(long double));
    printf("bars = %hu radii = %hu\n", n_bars, n_radii);

    uint32_t i, x, y, z;

    for (i = 0; i < n_bars; i++) {
        fscanf(input, "%u %u %u", &x, &y, &z);
        data[i] = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    }

    print_array(data, n_bars);
    //insertion_sort(data, 0, n_bars - 1);
    merge_sort(data, 0, n_bars - 1);

    FILE *output = fopen(OUTPUT_FILE, "w");

    uint32_t j, r, count;

    print_array(data, n_bars);
    for (i = 0; i < n_radii; i++) {
        fscanf(input, "%u", &r);
        count = 0;
        for (j = 0; j < n_bars; j++) {
            printf("data[%u] = %.2Lf radius = %u\n", j, data[j], r);
            if (data[j] > r) {
                break;
            }
            count += 1;
        }
        fprintf(output, "%u\n", count);
        r = 0;
    }

    free(data);
    fclose(input);
    fclose(output);

    QueryPerformanceCounter(&end);
    double time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Tempo esecuzione: %.6f sec\n", time);    
}

