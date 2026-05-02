#include <pattern.h>

delta *compute_delta_matrix(char *pattern, uint8_t lenght) {

    delta *matrix = calloc(26, sizeof(delta));
    int8_t i, lps = 0, ascii_letter = 97;

    for (ascii_letter = 97; ascii_letter <= 122; ascii_letter++) {
        matrix[ascii_letter - 97].letter = ascii_letter;
        matrix[ascii_letter - 97].values = calloc(lenght, sizeof(uint8_t));
    }    

    uint8_t pos = pattern[0] - 97;
    matrix[pos].values[0] = 1;

    for (i = 1; i < lenght; i++) {
        for (ascii_letter = 97; ascii_letter <= 122; ascii_letter++) {
            matrix[ascii_letter - 97].values[i] = matrix[ascii_letter - 97].values[lps]; 
        }

        pos = pattern[i] - 97;
        matrix[pos].values[i] = i + 1;

        if (i < lenght) {
            lps = matrix[lps].values[pos];
        }
    }


    // for (i = 0; i < lenght; i++) {
    //     uint8_t pos = pattern[i] - 97;
    //     matrix[pos].values[i] = i + 1;
    // }

    // for (ascii_letter = 97; ascii_letter <= 122; ascii_letter++) {
    //     printf("\n%c: ", matrix[ascii_letter-97].letter);
    //     for (i = 0; i < lenght; i++) {
    //         printf("\t%hhu", matrix[ascii_letter-97].values[i]);
    //     }      
    // }   

    return matrix;
}

int32_t search_pattern(char *pattern, char *text, uint8_t pattern_lenght, uint32_t text_lenght) {
    delta *dmatrix = compute_delta_matrix(pattern, pattern_lenght);
    
    int32_t i, j = 0;

}