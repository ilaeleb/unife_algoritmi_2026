#include <x86intrin.h> 
#include <stdio.h>
#include <stdint.h>
#include "pattern.h"

#define INPUT_FILE "input_output/input_firma_big.txt"
#define OUTPUT_FILE "input_output/output_firma_big.txt"

// #define INPUT_FILE "input_output/input_firma_small.txt"
// #define OUTPUT_FILE "input_output/output_firma_small.txt"

// #define INPUT_FILE "input_output/input_firma_prof.txt"
// #define OUTPUT_FILE "input_output/output_firma_prof.txt"

// #define INPUT_FILE "input.txt"
// #define OUTPUT_FILE "output.txt"

int main() {

    uint64_t start, end;
    start = __rdtsc(); 

    FILE *input = fopen(INPUT_FILE, "r");
    FILE *output = fopen(OUTPUT_FILE, "w");

    if (input == NULL) {
        printf("File not found.\n");
        return -1;
    }

    uint32_t virus_lenght;
    uint16_t n_query; 
    fscanf(input, "%u %hu", &virus_lenght, &n_query);

    char *virus = malloc(virus_lenght * sizeof(char));
    fscanf(input, "%s", virus);

    uint8_t pattern_lenght;
    char *pattern = malloc(20 * sizeof(char));;
    int16_t i, *count = malloc(n_query * sizeof(int16_t));
    int32_t *index = malloc(1 * sizeof(int32_t));

    for (i = 0; i < n_query; i++) {
        fscanf(input, "%hhu %s", &pattern_lenght, pattern);
        count[i] = search_pattern(pattern, virus, pattern_lenght, virus_lenght, index);
        fprintf(output, "%d\n", *index);
    }

    for (i = 0; i < n_query; i++) {
        fprintf(output, "%hd\n", count[i]);
    }

    fclose(input);
    fclose(output);
    free(index);

    end = __rdtsc();   
    double cpu_hz = 2.4e9;   // 2.4 GHz

    uint64_t cycles = end - start;      
    double time_sec = cycles / cpu_hz;

    printf("\nTempo: %.9f sec\n", time_sec);
}