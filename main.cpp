#include <iostream>
#include <random>
#include <math.h>
#include "2_base_DIT_FFT.h"
#include "2_base_DIF_FFT.h"
#include "DFT.h"
#include <ctime>
using namespace std;

int main()
{
  default_random_engine e;
  uniform_real_distribution<double> u(-5, 5);
  complex *a, *b, *c;
  int r = 10; //蝶形级数，用于控制序列长短
  int len = 1 << r;
  int i;
  a = new complex[len];
  b = new complex[len];
  c = new complex[len];
  clock_t start_DFT = clock();
  DFT(a, len, -1);
  clock_t end_DFT = clock();
  cout << "DFT Running Time:" << (double)(end_DFT - start_DFT) / CLOCKS_PER_SEC << "s" << endl;

  clock_t start_DIT_FFT = clock();
  DIT_FFT(b, len, -1);
  clock_t end_DIT_FFT = clock();
  cout << "DIT_FFT Running Time:" << (double)(end_DIT_FFT - start_DIT_FFT) / CLOCKS_PER_SEC << "s" << endl;

  clock_t start_DIF_FFT = clock();
  DIF_FFT(c, len, -1);
  clock_t end_DIF_FFT = clock();
  cout << "DIF_FFT Running Time:" << (double)(end_DIF_FFT - start_DIT_FFT) / CLOCKS_PER_SEC << "s" << endl;

  bool flag = 1;
  for (i = 0; i < len; i++)
  {
    if (a[i] != b[i] || a[i] != c[i] || b[i] != c[i])
      flag = 0;
  }

  if (flag == 1)
    cout << "Three methods are fit!\n";
  else
    cout << "Three methods are not fit!\n";

  delete[] a;
  delete[] b;
  delete[] c;
  return 0;
}
