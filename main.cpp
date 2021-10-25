#include <iostream>
#include <math.h>
#include "2_base_DIT_FFT.h"
#include "2_base_DIF_FFT.h"
#include "DFT.h"
using namespace std;

int main()
{
  complex *a;
  a = new complex[8];
  for (int i = 0; i < 8; i++)
    a[i] = complex(i, 0);
  DIT_FFT(a, 8, -1);
  for (int i = 0; i < 8; i++)
    a[i] = complex(i, 0);
  DIF_FFT(a, 8, -1);
  for (int i = 0; i < 8; i++)
    a[i] = complex(i, 0);
  DFT(a, 8, -1);
  delete[] a;
  return 0;
}
