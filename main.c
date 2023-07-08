#include "Matrix.h"

int main() {

    Matrix M = matrix_init(3, 3);
    matrix_fill(M, 3);
    print_matrix(M, "Matrix 1");
    printf("Rows: %zu\n", M->rows);
    Matrix row1 = get_row(M, 1);
    print_matrix(row1, "Row 1 of Matrix 1");

    return 0;
}