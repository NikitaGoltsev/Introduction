#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10000000
#define pi 3.14159265358979323846
const double angle = (2 * pi) / N;
int main() {
  float *arr = (float *)malloc(sizeof(float) * N);
  float sum;
  sum = 0;
#pragma acc data create(arr[:N]) copyin(angle) copy(sum)
  {
#pragma acc kernels
    {
      for (int i = 0; i < N; i++) {
        arr[i] = sinf(angle * i);
      }
    }
#pragma acc kernels
    {
      for (int i = 0; i < N; i++) {
        sum += arr[i];
      }
    }
  }
  printf("%.9g\n", sum);
  free(arr);
  return 0;
}
