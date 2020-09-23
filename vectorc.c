#include <stdio.h>
#include <stdlib.h>
#include "vectorc.h"

void vec_slice_double(double *all_vec, double *sliced_vec, int start, int end)
{
    for(int i = 0; i <= (end-start); i++)
        sliced_vec[i] = all_vec[start+i];
}

void vec_slice_int(int *all_vec, int *sliced_vec, int start, int end)
{
    for(int i = 0; i <= (end-start); i++)
        sliced_vec[i] = all_vec[start+i];
}

void vec_concatenate_double(double *vec_1, int len_1, double *vec_2, int len_2, double *c_vec)
{
    for(int i = 0; i < len_1; i++)
        c_vec[i] = vec_1[i];
    for(int i = 0; i < len_2; i++)
        c_vec[len_1 + i] = vec_2[i];
}

void vec_concatenate_int(int *vec_1, int len_1, int *vec_2, int len_2, int *c_vec)
{
    for(int i = 0; i < len_1; i++)
        c_vec[i] = vec_1[i];
    for(int i = 0; i < len_2; i++)
        c_vec[len_1 + i] = vec_2[i];
}

double vec_max_double(double *vec, int len)
{
    double M = vec[0];
    for(int i = 1; i < len; i++)
        if(vec[i] > M)
            M = vec[i];

    return M;
}

int vec_max_int(int *vec, int len)
{
    int M = vec[0];
    for(int i = 1; i < len; i++)
        if(vec[i] > M)
            M = vec[i];

    return M;
}

double vec_min_double(double *vec, int len)
{
    double m = vec[0];
    for(int i = 1; i < len; i++)
        if(vec[i] < m)
            m = vec[i];

    return m;
}

int vec_min_int(int *vec, int len)
{
    int m = vec[0];
    for(int i = 1; i < len; i++)
        if(vec[i] < m)
            m = vec[i];

    return m;
}

int vec_find_double(double *vec, int len, double val)
{
    int idx = -1;
    for(int i = 0; i < (int)(len / 2); i++)
    {
        if(vec[i] == val)
        {
            idx = i;
            break;
        }
        if(vec[(int)(len / 2) + i] == val)
        {
            idx = (int)(len / 2) + i;
            break;
        }
    }
    if(((len % 2) != 0) && (idx == -1))
        if(vec[len - 1] == val)
            idx = len - 1;

    return idx;
}

int vec_find_int(int *vec, int len, int val)
{
    int idx = -1;
    for(int i = 0; i < (int)(len / 2); i++)
    {
        if(vec[i] == val)
        {
            idx = i;
            break;
        }
        if(vec[(int)(len / 2) + i] == val)
        {
            idx = (int)(len / 2) + i;
            break;
        }
    }
    if(((len % 2) != 0) && (idx == -1))
        if(vec[len - 1] == val)
            idx = len - 1;

    return idx;
}

void vec_insert_double(double *vec, int size, double elem, int pos)
{
    if(pos < 0)
    {
        fprintf(stderr, "Position of the new element cannot be negative.\n");
        return;
    }
    if(pos > size)
    {
        fprintf(stderr, "Position of the new element can exceed vector size at least by one.\n");
        return;
    }

    vec = realloc(vec, (size + 1) * sizeof(double));
    if(pos != size)
    {
        for(int i = size-1; i >= pos ; i--)
            vec[i + 1] = vec[i];
    }
    vec[pos] = elem;
}

void vec_insert_int(int *vec, int size, int elem, int pos)
{
    if(pos < 0)
    {
        fprintf(stderr, "Position of the new element cannot be negative.\n");
        return;
    }
    if(pos > size)
    {
        fprintf(stderr, "Position of the new element can exceed vector size at least by one.\n");
        return;
    }

    vec = realloc(vec, (size + 1) * sizeof(int));
    if(pos != size)
    {
        for(int i = size-1; i >= pos ; i--)
            vec[i + 1] = vec[i];
    }
    vec[pos] = elem;
}

void vec_delete_double(double *vec, int size, int pos)
{
    if(pos < 0)
    {
        fprintf(stderr, "Position cannot be negative.\n");
        return;
    }
    if(pos >= size)
    {
        fprintf(stderr, "Position cannot exceed vector size.\n");
        return;
    }

    double last = vec[size - 1];
    vec = realloc(vec, (size - 1) * sizeof(double));
    if(pos != (size - 1))
    {
        for(int i = pos+1; i < size-1; i++)
            vec[i - 1] = vec[i];
        vec[size - 2] = last;
    }
}

void vec_delete_int(int *vec, int size, int pos)
{
    if(pos < 0)
    {
        fprintf(stderr, "Position cannot be negative.\n");
        return;
    }
    if(pos >= size)
    {
        fprintf(stderr, "Position cannot exceed vector size.\n");
        return;
    }

    int last = vec[size - 1];
    vec = realloc(vec, (size - 1) * sizeof(int));
    if(pos != (size - 1))
    {
        for(int i = pos+1; i < size-1; i++)
            vec[i - 1] = vec[i];
        vec[size - 2] = last;
    }
}


