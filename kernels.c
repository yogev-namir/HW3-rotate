/********************************************************
 * Kernels to be optimized
 ********************************************************/

#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "yogev&tomer",              /* Team name */

    "Yogev Namir",     /* First member full name */
    "yogev.namir@campus.technion.ac.il",  /* First member email address */

    "Tomer Grinberg",                   /* Second member full name (leave blank if none) */
    "grtomer@campus.technion.ac.il"                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{

    for (register int i = 0; i < dim; i++)
        for (register int j = 0; j < dim; j+=16){
            dst[RIDX(dim-1-i, j, dim)] = src[RIDX(j, i, dim)];
            dst[RIDX(dim-1-i, j+1, dim)] = src[RIDX(j+1, i, dim)];
            dst[RIDX(dim-1-i, j+2, dim)] = src[RIDX(j+2, i, dim)];
            dst[RIDX(dim-1-i, j+3, dim)] = src[RIDX(j+3, i, dim)];
            dst[RIDX(dim-1-i, j+4, dim)] = src[RIDX(j+4, i, dim)];
            dst[RIDX(dim-1-i, j+5, dim)] = src[RIDX(j+5, i, dim)];
            dst[RIDX(dim-1-i, j+6, dim)] = src[RIDX(j+6, i, dim)];
            dst[RIDX(dim-1-i, j+7, dim)] = src[RIDX(j+7, i, dim)];
            dst[RIDX(dim-1-i, j+8, dim)] = src[RIDX(j+8, i, dim)];
            dst[RIDX(dim-1-i, j+9, dim)] = src[RIDX(j+9, i, dim)];
            dst[RIDX(dim-1-i, j+10, dim)] = src[RIDX(j+10, i, dim)];
            dst[RIDX(dim-1-i, j+11, dim)] = src[RIDX(j+11, i, dim)];
            dst[RIDX(dim-1-i, j+12, dim)] = src[RIDX(j+12, i, dim)];
            dst[RIDX(dim-1-i, j+13, dim)] = src[RIDX(j+13, i, dim)];
            dst[RIDX(dim-1-i, j+14, dim)] = src[RIDX(j+14, i, dim)];
            dst[RIDX(dim-1-i, j+15, dim)] = src[RIDX(j+15, i, dim)];
        }

}
char rotate_descr_2[] = "rotate_2: Current working version";
void rotate_2(int dim, pixel *src, pixel *dst) {

    for (register int i=0; i < dim; i++) {
        register int a = dim - 1 - i;
        for (register int j=0; j < dim; j += 16) {
            dst[RIDX(a, j, dim)] = src[RIDX(j, i, dim)];
            dst[RIDX(a, j + 1, dim)] = src[RIDX(j + 1, i, dim)];
            dst[RIDX(a, j + 2, dim)] = src[RIDX(j + 2, i, dim)];
            dst[RIDX(a, j + 3, dim)] = src[RIDX(j + 3, i, dim)];
            dst[RIDX(a, j + 4, dim)] = src[RIDX(j + 4, i, dim)];
            dst[RIDX(a, j + 5, dim)] = src[RIDX(j + 5, i, dim)];
            dst[RIDX(a, j + 6, dim)] = src[RIDX(j + 6, i, dim)];
            dst[RIDX(a, j + 7, dim)] = src[RIDX(j + 7, i, dim)];
            dst[RIDX(a, j + 8, dim)] = src[RIDX(j + 8, i, dim)];
            dst[RIDX(a, j + 9, dim)] = src[RIDX(j + 9, i, dim)];
            dst[RIDX(a, j + 10, dim)] = src[RIDX(j + 10, i, dim)];
            dst[RIDX(a, j + 11, dim)] = src[RIDX(j + 11, i, dim)];
            dst[RIDX(a, j + 12, dim)] = src[RIDX(j + 12, i, dim)];
            dst[RIDX(a, j + 13, dim)] = src[RIDX(j + 13, i, dim)];
            dst[RIDX(a, j + 14, dim)] = src[RIDX(j + 14, i, dim)];
            dst[RIDX(a, j + 15, dim)] = src[RIDX(j + 15, i, dim)];

        }
    }
}
char rotate_descr_3[] = "rotate_3: Current working version";
void rotate_3(int dim, pixel *src, pixel *dst ){

    register int i, j;

    for (i = 0; i < dim; i++)
        for (j = 0; j < dim; j++){
            dst[RIDX(dim-1-i, j, dim)].red = src[RIDX(j, i, dim)].red;
            dst[RIDX(dim-1-i, j, dim)].green = src[RIDX(j, i, dim)].green;
            dst[RIDX(dim-1-i, j, dim)].blue = src[RIDX(j, i, dim)].blue;
        }
}
char rotate_descr_4[] = "rotate_4: Current working version";
void rotate_4(int dim, pixel *src, pixel *dst) {

    for (register int i=0; i < dim; i++) {
        register int a = dim - 1 - i;
        for (register int j=0; j < dim; j += 8) {
            dst[RIDX(a, j, dim)] = src[RIDX(j, i, dim)];
            dst[RIDX(a, j + 1, dim)] = src[RIDX(j + 1, i, dim)];
            dst[RIDX(a, j + 2, dim)] = src[RIDX(j + 2, i, dim)];
            dst[RIDX(a, j + 3, dim)] = src[RIDX(j + 3, i, dim)];
            dst[RIDX(a, j + 4, dim)] = src[RIDX(j + 4, i, dim)];
            dst[RIDX(a, j + 5, dim)] = src[RIDX(j + 5, i, dim)];
            dst[RIDX(a, j + 6, dim)] = src[RIDX(j + 6, i, dim)];
            dst[RIDX(a, j + 7, dim)] = src[RIDX(j + 7, i, dim)];
        }
    }
}
/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);
    add_rotate_function(&rotate_2, rotate_descr_2);
    add_rotate_function(&rotate_3, rotate_descr_3);
    add_rotate_function(&rotate_4, rotate_descr_4);
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	    accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	for (j = 0; j < dim; j++)
	    dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}


