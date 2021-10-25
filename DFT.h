#define PI 3.1415926545
#define MAX 100000
#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;

void DFT(complex *x,int len,int sign)
{
  int n, k;
  complex *X=new complex[len];

  for (k = 0; k < len; k++)
  {
    complex sum; //预备DFT/IDFT右边式子的求和
    for (n = 0; n < len; n++)
    {
      sum += x[n] * (sign==-1 ? complex(cos(2 * PI * n * k / len), -sin(2 * PI * n * k / len)) : complex(cos(2 * PI * n * k / len), sin(2 * PI * n * k / len)));
    }
    X[k] = sum;
  }

  for (k = 0; k < n; k++)
    cout << (sign == -1 ? X[k] : X[k] / complex(len, 0)) << endl; //IDFT要除以N

  delete[] X;
}
