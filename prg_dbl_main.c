#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10000000
#define pi 3.14159265358979323846
double angle = (2 * pi) / N;

int main() {
  double *arr = (double *)malloc(sizeof(double) * N);
  double sum;
  sum = 0;
#pragma acc data create(arr[:N]) copyin(angle) copy(sum) # for gpu
  {
#pragma acc kernels
    {
      for (int i = 0; i < N; i++) {
        arr[i] = sin(angle * i);
      }
    }
#pragma acc kernels
    {
      for (int i = 0; i < N; i++) {
        sum += arr[i];
      }
    }
  }
  printf("%.17g\n", sum);
  free(arr);
  return 0;
}
