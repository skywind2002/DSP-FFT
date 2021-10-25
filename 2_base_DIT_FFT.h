// 通用基2FFT程序 采用DIT的形式
//已经打包成DIT_FFT void函数，输入数组指针，长度和指示正反的变量就行,
#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;

int reverse(int n, int num) //按位数num翻转数字n
{
  int ans = 0;
  for (int i = 0; i < num; i++)
  {
    ans += (n % 2) * pow(2, num - i - 1);
    n /= 2;
  }
  return ans;
}

void DIT_FFT(complex *Input, int len, int sign) //DIT-FFT函数,变换+输出 -1-IDFT 1-DFT
{
  int i, j, k;
  int dist, shifting;
  if (pow(2, int(log2(len))) != len)
  {
    cout << "2-base DFT cannot deal with this sequence!\n";
    exit(0);
  }                  //首先排除变换点数非2的幂次的情况,下面开始真正的FFT
  int r = log2(len); //蝶形迭代级数

  complex *W, *X2, *X, *result;

  W = new complex[len / 2];
  X2 = new complex[len];     //预先分配中转寄存器
  result = new complex[len]; //结果寄存器

  for (i = 0; i < len / 2; i++)
  {
    W[i] = complex(cos(sign * i * PI * 2 / len), sin(sign * i * PI * 2 / len)); //计算旋转因子
  }

  for (k = 0; k < r; k++) //进行r级计算
  {
    for (j = 0; j < 1 << k; j++) //每一级有(1<<k)组蝶形运算
    {
      dist = (1 << (r - k));         //蝶形之间两个点的距离*2，也是相邻组蝶形之间的距离
      for (i = 0; i < dist / 2; i++) //每组中蝶形运算的次数
      {
        shifting = j * dist; //计算蝶形偏移量
        X2[i + shifting] = Input[i + shifting] + Input[i + shifting + dist / 2] * W[reverse(j, r - 1)];
        X2[i + shifting + dist / 2] = Input[i + shifting] - Input[i + shifting + dist / 2] * W[reverse(j, r - 1)]; //乘以旋转因子
      }
    }
    X = Input;
    Input = X2;
    X2 = X;
  }

  for (i = 0; i < len; i++) //倒位序重新排列
  {
    int p = 0;
    for (j = 0; j < r; j++)
    {
      if (i & (1 << j))
        p += 1 << (r - j - 1);
    }
    if (sign == 1)
      Input[p] /= complex(len,0);
    cout << Input[p] << endl;
  }
}
