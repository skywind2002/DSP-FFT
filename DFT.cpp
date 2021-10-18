#define PI 3.1415926545
#define MAX 100000
#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;

int main()
{
  int N, a[MAX];
  complex *x = new complex[MAX];
  complex *X = new complex[MAX];
  int n, k;
  cout << "Please input the DFT Sequence length:\n";
  cin >> N;
  cout << "Please input the sequence:\n";
  for (n = 0; n < N; n++)
  {
    cin >> a[n];
    x[n] = complex(a[n], 0);
  }

  cout << "Begin time->freq DFT transform...\n";
  for (k = 0; k < N; k++)
  {
    complex sum; //预备DFT右边式子的求和
    for (n = 0; n < N; n++)
      sum += x[n] * complex(cos(-2 * PI * n * k / N), sin(-2 * PI * n * k / N));
    X[k] = sum;
  }

  for (k = 0; k < n; k++)
    cout << X[k] << endl;
  system("pause");
  return 0;
}