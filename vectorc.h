#ifndef VECTORC
#define VECTORC

extern void vec_slice_double(double *all_vec, double *sliced_vec, int start, int end);
extern void vec_concatenate_double(double *vec_1, int len_1, double *vec_2, int len_2, double *c_vec);
extern double vec_max_double(double *vec, int len);
extern double vec_min_double(double *vec, int len);
extern int vec_find_double(double *vec, int len, double val);
extern void vec_insert_double(double *vec, int size, double elem, int pos);
extern void vec_delete_double(double *vec, int size, int pos);

extern void vec_slice_int(int *all_vec, int *sliced_vec, int start, int end);
extern void vec_concatenate_int(int *vec_1, int len_1, int *vec_2, int len_2, int *c_vec);
extern int vec_max_int(int *vec, int len);
extern int vec_min_int(int *vec, int len);
extern int vec_find_int(int *vec, int len, int val);
extern void vec_insert_int(int *vec, int size, int elem, int pos);
extern void vec_delete_int(int *vec, int size, int pos);

#endif
