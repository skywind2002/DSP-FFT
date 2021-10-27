#include <iostream>
#include <random>
#include <fstream>
#include <math.h>
#include "2BaseDIT-FFT.h"
#include "2BaseDIF-FFT.h"
#include "DFT.h"
#include <ctime>
using namespace std;

int main()
{
  default_random_engine e;
  uniform_real_distribution<double> u(-1,1); //初始化随机数引擎
  complex *a, *b, *c;
  int range = 14;                                        //测试长短，在1~range内的蝶形级数都会被运行并且比较
  double TimeofDIT[100], TimeofDIF[100], TimeofDFT[100]; //存储运行时间的矩阵
  int r, len, i;
  bool flag = 1;
  for (r = 1; r <= range; r++)
  {
    len = 1 << r;
    a = new complex[len];
    b = new complex[len];
    c = new complex[len];
    for (i = 0; i < len; i++)
    {
      a[i] = complex(i, 0);
      b[i] = a[i];
      c[i] = a[i];
    }
    clock_t StartDFT = clock();
    DFT(a, len, -1);
    clock_t EndDFT = clock();
    TimeofDFT[r] = (double)(EndDFT - StartDFT) / CLOCKS_PER_SEC;

    clock_t StartDIT = clock();
    DIT_FFT(b, len, -1);
    clock_t EndDIT = clock();
    TimeofDIT[r] = (double)(EndDIT - StartDIT) / CLOCKS_PER_SEC;

    clock_t StartDIF = clock();
    DIF_FFT(c, len, -1);
    clock_t EndDIF = clock();
    TimeofDIF[r] = (double)(EndDIF - StartDIT) / CLOCKS_PER_SEC;

    cout << TimeofDFT[r] << " " << TimeofDIT[r] << " " << TimeofDIT[r] << endl;

    delete[] a;
    delete[] b;
    delete[] c;
  }

  ofstream file;
  file.open("data.txt");
  for (i = 1; i <= range; i++)
    file << TimeofDFT[i] << " " << TimeofDIT[i] << " " << TimeofDIT[i] << endl;
  file.close();
  return 0;
}
