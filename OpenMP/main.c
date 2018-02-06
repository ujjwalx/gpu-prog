#include<stdio.h>
#include <stdlib.h>
#include<time.h>

// #define RAND_MIN 1
// #define RAND_MAX 10

void test(double *a){
  printf("I was called");
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
      //a[i] = c * (double) t;
    }
  }
}

void main(){

srand(time(NULL));

int LEN = 10;

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

//test(array2);
multimult(a,b,LEN,1);
test(a);
// printf("Dealloc Complete");

}
