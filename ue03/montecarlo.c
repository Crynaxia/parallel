/* Program to compute Pi using Monte Carlo methods */
/* sequential version copied from https://www.dartmouth.edu/~rc/classes/soft_dev/C_simple_ex.html*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <omp.h>
#define SEED 35791246

int main(int argc, char **argv)
{
   int niter = 0;
   niter = atoi(argv[1]);

   if (argc != 2 || niter == 0)
   {
      printf("Usage %s <number of iterations>\n", argv[0]);
   }

   double x, y;
   int i, count = 0; /* # of points in the 1st quadrant of unit circle */
   double z;
   double pi;

   /* initialize random numbers */
   srand(SEED);
   count = 0;

   double start_time = omp_get_wtime();
   for (i = 0; i < niter; i++)
   {
      x = (double)rand() / RAND_MAX;
      y = (double)rand() / RAND_MAX;
      z = x * x + y * y;
      if (z <= 1)
         count++;
   }
   pi = (double)count / niter * 4;
   double end_time = omp_get_wtime();
   printf("time: %2.2f seconds\n", end_time - start_time);
   printf("# of trials= %d , estimate of pi is %.16f \n", niter, pi);

   return EXIT_SUCCESS;
}
