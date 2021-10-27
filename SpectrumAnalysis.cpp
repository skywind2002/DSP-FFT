// 对信号 s(t)=0.8*sin(2*pi*103t)+sin(2*pi*107t)+0.1*sin(2*pi*115t)进行频谱分析

#include <iostream>
#include <math.h>
#include <fstream>
#include "2BaseDIT-FFT.h"
#include "2BaseDIF-FFT.h"
#include "DFT.h"
using namespace std;

int main()
{
  int i;
  double fs = 1000; //采样频率1kHz
  double Ts = 1 / fs;
  int N = 1024; //采样点数为1024点
  complex *s;   //变换数组
  s = new complex[N];
  double *Abs = new double[N];
  for (i = 0; i < N; i++)
  {
    s[i] = complex(0.8 * sin(2 * PI * 103 * i * Ts) + sin(2 * PI * 107 * i * Ts) + 0.1 * sin(2 * PI * 115 * i * Ts), 0); //生成采样序列
    //窗函数 TODO，目前是矩形窗
  }

  DIT_FFT(s, N, -1);
  for (i = 0; i < N; i++)
    Abs[i] = s[i].mod(); //取模长，准备绘制FFT图

  ofstream file;
  file.open("FreqData.txt");
  for (i = 1; i <= N; i++)
    file << Abs[i] << endl;
  file.close();

  return 0;
}