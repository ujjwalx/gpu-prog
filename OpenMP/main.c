#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include "omp.h"

// #define RAND_MAX 10
#define BILLION 1E9

void print(double *a){
  for (int i=0;i<10;i++){
    printf("%f,",a[i]);
  }

}

void multimult(double *a, double *b, int len, int steps)
{
  double c;
  for (int t=0; t < steps; t++)
  {
    for (int i = 0; i < len; i++)
    {
      c = a[i] * b[i];
      a[i] = c * (double) t;
    }
  }
}

void multimult_OMP(double *a, double *b, int len, int steps)
{
  double c;
  int i = 0;
  for (int t=0; t < steps; t++)
  {
    # pragma omp parallel for shared(t,len,a,b) private(i,c)
    for (i = 0; i < len; i++)
    {
      c = a[i] * b[i];
      a[i] = c * (double) t;
    }
  }
}

void main(int argc, char** argv){

// Random Number Generator Seed
srand(time(NULL));

// For clock_gettime functionality
struct timespec requestStart, requestEnd;

// Length of A and B integer arrays

if (argc < 3){
  printf("\n Invalid Parameter Specification. Exiting! \n");
  exit(2);
}

// Test Parameters
int LEN = atoi(argv[1]);
int NUM_THREADS = atoi(argv[2]);
int STEPS = atoi(argv[3]);

// Set Number of OMP NUM_THREADS
omp_set_num_threads(NUM_THREADS);

// Display Test Parameters
printf("LEN = %d \n",LEN);
printf("NUM_THREADS = %d \n",NUM_THREADS);
printf("STEPS = %d \n",STEPS);

double * a;
double * b;
double random_value;

a = malloc (LEN * sizeof(double));
if (a == NULL) exit (1);
b = (double*) malloc (LEN * sizeof(double));

for (int n=0; n<LEN; n++)
{
  random_value = (double)rand()/RAND_MAX*10.0-1.0;//float in range -1 to 1
  a[n] = random_value;
  //printf("%f----",array1[n]);
}

// Call function and time it.

// Calculate time taken by Sequential request
clock_gettime(CLOCK_REALTIME, &requestStart);
multimult(a,b,LEN,STEPS);
clock_gettime(CLOCK_REALTIME, &requestEnd);

double accum = ( requestEnd.tv_sec - requestStart.tv_sec )
  + ( requestEnd.tv_nsec - requestStart.tv_nsec )
  / BILLION;
printf( "%lf\n", accum );

// Time taken by Parallel request
clock_gettime(CLOCK_REALTIME, &requestStart);
multimult_OMP(a,b,LEN,STEPS);
clock_gettime(CLOCK_REALTIME, &requestEnd);

double accum_OMP = ( requestEnd.tv_sec - requestStart.tv_sec )
  + ( requestEnd.tv_nsec - requestStart.tv_nsec )
  / BILLION;
printf( "%lf\n", accum_OMP );

free(a);
free(b);

}
