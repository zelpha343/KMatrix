#include "Matrix.h"

#define matrix_get(M, row, column) M->elements[(row-1)*M->columns + (column-1)]

Matrix matrix_init(size_t rows, size_t columns) {
    Matrix m = malloc(2 * sizeof(size_t) + sizeof(float) * rows * columns);
    m->rows = rows;
    m->columns = columns;
    return m;
}

void change_element(Matrix M, size_t row, size_t column, float x) {
    matrix_get(M, row, column) = x;
}

void print_matrix(Matrix M, char *name) {
    printf("%s = [ \n", name);
    for (size_t i = 1; i <= M->rows; i++){
        for (size_t j = 1; j <= M->columns; j++) {
            printf("%.3f ", matrix_get(M, i, j));
        }
        printf("\n");
    }
    printf("]\n");
}

void matrix_fill(Matrix M, float x) {
    for (size_t i = 1; i <= M->rows; i++){
        for (size_t j = 1; j <= M->columns; j++) {
            matrix_get(M, i, j) = x;
        }
    }
}

void matrix_add(Matrix target, Matrix a, Matrix b) {
    assert(target->rows == a->rows);
    assert(target->columns == a->columns);
    assert(target->rows == b->rows);
    assert(target->columns == b->columns);

    for (size_t i = 1; i <= target->rows; i++){
        for (size_t j = 1; j <= target->columns; j++) {
            matrix_get(target, i, j) = matrix_get(a, i, j) + matrix_get(b, i, j);
        }
    }

}

void matrix_scale(Matrix M, float scalar) {
    for (size_t i = 1; i <= M->rows; i++) {
        for (size_t j = 1; j <= M->columns; j++) {
            matrix_get(M, i, j) *= scalar;
        }
    }
}

void matrix_randomize(Matrix M) {
    for (size_t i = 1; i <= M->rows; i++) {
        for (size_t j = 1; j <= M->columns; j++) {
            matrix_get(M, i, j) = rand();
        }
    }
}

Matrix get_row(Matrix M, size_t row) {
    Matrix return_row = matrix_init(1, M->columns);
    for (size_t i = 1; i <= return_row->columns; i++) {
        matrix_get(return_row, 1, i) = matrix_get(M, row, i);
    }
    return return_row;
}

Matrix get_column(Matrix M, size_t column) {
    Matrix return_column = matrix_init(M->rows, 1);
    for (size_t i = 1; i <= return_column->columns; i++) {
        matrix_get(return_column, i, 1) = matrix_get(M, i, column);
    }
    return return_column;
}

void matrix_multiply(Matrix target, Matrix a, Matrix b) {
    for (size_t i = 1; i <= target->rows; i++) {
        for (size_t j = 1; j <= target->columns; j++) {
            matrix_get(target, i, j) = 0;
            for (size_t k = 1; k <= a->columns; k++){
                matrix_get(target, i, j) += (matrix_get(a, i, k) + matrix_get(b, k, j));
            }
        }
    }
}

void matrix_multiply_element_wise(Matrix target, Matrix a, Matrix b) {
    for (size_t i = 1; i <= target->rows; i++) {
        for (size_t j = 1; j <= target->columns; j++) {
            matrix_get(target, i, j) = matrix_get(a, i, j) * matrix_get(b, i, j);
        }
    }
}