/*********************
**  Mandelbrot fractal
** clang -Xpreprocessor -fopenmp -lomp -o Mandelbrot Mandelbrot.c
** by Dan Garcia <ddgarcia@cs.berkeley.edu>
** Modified for this class by Justin Yokota and Chenyu Shi
**********************/

#include <stdio.h>
#include <stdlib.h>
#include "ComplexNumber.h"
#include "Mandelbrot.h"
#include <sys/types.h>

/*
This function returns the number of iterations before the initial point >= the threshold.
If the threshold is not exceeded after maxiters, the function returns 0.
*/
u_int64_t MandelbrotIterations(u_int64_t maxiters, ComplexNumber * point, double threshold)
{
  ComplexNumber* temp;
  ComplexNumber* product;
  temp = newComplexNumber(0, 0);
  for(int i=1; i<=maxiters; i++){
  	product = ComplexProduct(temp, temp);
	free(temp);
	temp = ComplexSum(point, product);
	free(product);
	if(ComplexAbs(temp)>threshold){
		return i;
	}
  }
  freeComplexNumber(temp);
  return 0;
}

/*
This function calculates the Mandelbrot plot and stores the result in output.
The number of pixels in the image is resolution * 2 + 1 in one row/column. It's a square image.
Scale is the the distance between center and the top pixel in one dimension.
*/
void Mandelbrot(double threshold, u_int64_t max_iterations, ComplexNumber* center, double scale, u_int64_t resolution, u_int64_t * output){
    double init_real = Re(center)-scale;
    double init_imagine = Im(center)+scale;
    double delta = scale/resolution;
    ComplexNumber* point;
    int size = resolution*2+1;
    for(int i=0; i<size; i++){
    	for(int j=0; j<size; j++){
		point = newComplexNumber(init_real+delta*j, init_imagine-delta*i);
		*(output+i*size+j) = MandelbrotIterations(max_iterations, point, threshold);
		free(point);
	}
    }
}


