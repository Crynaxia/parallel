/* Program to compute Pi using Monte Carlo methods */
/* sequential version copied from https://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#define SEED 35791246

int main(int argc, char** argv)
{
   
   int niter=0;
   
   int count=0; /* # of points in the 1st quadrant of unit circle */
   double pi = 0;
   double z = 0;
   double x,y = 0;

   niter = atoi(argv[1]);

   /* initialize random numbers */
   srand(SEED);
   #pragma omp parallel private(x,y,z)
   {
   #pragma omp for reduction(+:count)
   for (int i=0; i<niter; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      z = x*x+y*y;
      if (z<=1) {         
            count++;
         }
      }
   }
   pi=(double)count/niter*4;
   printf("# of trials= %d , estimate of pi is %.16f \n",niter,pi);

   return EXIT_SUCCESS;
}