#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// double fRand(double fMin, double fMax)
// {
//     double f = (double)rand() / RAND_MAX;
//     return fMin + f * (fMax - fMin);
// }
//
//
// void main(){
//
// srand(time(0));
// double* a;
// double* b;
// double k;
//
// double fmin=1;
// double fmax=10;
//
//  for(int i=0;i<10;i++){
//    //k = fRand(fmin,fmax);
//    k = (double)rand();
//    printf("%d,",&k);
//
//  }
//
//
// }

//
// int main()
// {
//     double random_value;
//
//     srand(time(NULL));
//
//     for (int i=0; i<10; i++){
//     random_value = (double)rand()/RAND_MAX*10.0-1.0;//float in range -1 to 1
//     printf ( "%f\n", random_value);
// }
//     return 0;
// }

void main(){

int *pv = (int*) malloc(5 * sizeof(int));
for(int i=0; i<5; i++) {
    pv[i] = i+1;
}


for (int i=0; i<5; i++){

  printf("%d",pv[i]);

}


}
