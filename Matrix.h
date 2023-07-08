#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    size_t rows;
    size_t columns;
    float elements[];
} *Matrix;


Matrix matrix_init(size_t rows, size_t columns);
void change_element(Matrix M, size_t row, size_t column, float new_value);
void print_matrix(Matrix M, char *name);
void matrix_fill(Matrix M, float x);
void matrix_add(Matrix target, Matrix a, Matrix b);
void matrix_scale(Matrix M, float scalar);
void matrix_randomize(Matrix M);
Matrix get_row(Matrix M, size_t row);
Matrix get_column(Matrix M, size_t column);
void matrix_multiply(Matrix target, Matrix a, Matrix b);
void matrix_multiply_element_wise(Matrix target, Matrix a, Matrix b);
