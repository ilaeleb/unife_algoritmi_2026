#include <pattern.h>

delta *compute_delta_matrix(char *pattern, uint8_t lenght) {

    delta *matrix = malloc(26 * sizeof(delta));
    int8_t i, ascii_letter = 97;

    for (ascii_letter = 97; ascii_letter <= 122; ascii_letter++) {
        matrix->letter = ascii_letter;
        matrix->values = malloc(lenght * sizeof(uint32_t ));
        i++;
    }    

    for (i = 0; i < lenght; i++) {

    }

    return matrix;
}