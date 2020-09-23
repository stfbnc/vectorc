#include <stdio.h>
#include <stdlib.h>
#include "vectorc.h"

int main()
{
    int a_len = 10;
    int b_len = 5;
    double a_elems[] = {-12.0, -34.0, 1.0, 2.0, 7.0, 3.0, 4.0, -3.0, 5.0, 1.0};
    double b_elems[] = {-1.0, -3.0, 1.0, 5.0, 31.0};
    double *a = (double *)malloc(a_len * sizeof(double));
    double *b = (double *)malloc(b_len * sizeof(double));
    for(int i = 0; i < a_len; i++)
        a[i] = a_elems[i];
    for(int i = 0; i < b_len; i++)
        b[i] = b_elems[i];

    fprintf(stderr, "max = %lf\n", vec_max_double(a, a_len));
    fprintf(stderr, "\n");
    fprintf(stderr, "min = %lf\n", vec_min_double(a, a_len));
    fprintf(stderr, "\n");
    fprintf(stderr, "element %lf found at position %d\n", a[4], vec_find_double(a, a_len, a[4]));
    fprintf(stderr, "\n");
    fprintf(stderr, "element %lf found at position %d\n", 12.0, vec_find_double(a, a_len, 12.0));
    fprintf(stderr, "\n");
    fprintf(stderr, "element %lf found at position %d\n", b[4], vec_find_double(b, b_len, b[4]));
    fprintf(stderr, "\n");
    fprintf(stderr, "element %lf found at position %d\n", 12.0, vec_find_double(b, b_len, 12.0));
    fprintf(stderr, "\n");

    double c[a_len + b_len];
    vec_concatenate_double(a, a_len, b, b_len, c);
    for(int i = 0; i < (a_len + b_len); i++)
        fprintf(stderr, "element %d --> %lf\n", i, c[i]);
    fprintf(stderr, "\n");

    double d[3];
    vec_slice_double(a, d, 2, 4);
    for(int i = 0; i < 3; i++)
        fprintf(stderr, "element %d --> %lf\n", i, d[i]);
    fprintf(stderr, "\n");

    vec_insert_double(b, b_len, 101.0, 0);
    for(int i = 0; i < (b_len + 1); i++)
        fprintf(stderr, "element %d --> %lf\n", i, b[i]);
    fprintf(stderr, "\n");

    vec_delete_double(a, a_len, 0);
    for(int i = 0; i < (a_len - 1); i++)
        fprintf(stderr, "element %d --> %lf\n", i, a[i]);
    fprintf(stderr, "\n");

    exit(0);
}
