#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <stdint.h>


#include <utils.h>
#include <sort.h>

#define INPUT_FILE "input_output/input_sete.txt"
#define OUTPUT_FILE "input_output/output_sete.txt"

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

    // n_virus 50-10e6 , n_query 5-10e3
    uint8_t virus_lenght, n_query; 
    fscanf(input, "%hhu %hhu", &virus_lenght, &n_query);

    char *virus = malloc(virus_lenght * sizeof(char));
    fscanf(input, "%s", virus);

    int8_t i;
    uint8_t substring_lenght;
    char *substring = malloc(substring_lenght * sizeof(char));; 

    for (i = 0; i < n_query; i++) {
        fscanf(input, "%hhu %s", &substring_lenght, substring);
        //printf("%u %s\n", substring_lenght, substring);


    }

    int8_t characters;

    free(virus);
    free(substring);
    fclose(input);

    QueryPerformanceCounter(&end);
    double time = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
    printf("Tempo esecuzione: %.6f sec\n", time); 
}