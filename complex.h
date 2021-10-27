#define PI 3.1415926545
#define MIN 1e-3
#include <iostream>
#include <math.h>
#include <iomanip>
#pragma once
using namespace std;

class complex
{
private:
  double r;
  double i;

public:
  complex() : r(0), i(0) {}
  complex(double r, double i) : r(r), i(i) {}
  complex(const complex &c) : r(c.r), i(c.i) {}
  ~complex() {}

  //运算符重载
  complex &operator=(const complex &c); //赋值
  friend const complex operator+(const complex &c1, const complex &c2);
  friend const complex operator-(const complex &c1, const complex &c2);
  friend const complex operator*(const complex &c1, const complex &c2);
  friend const complex operator/(const complex &c1, const complex &c2);
  const complex operator^(const int x); //四则运算与乘方

  complex operator+=(const complex &c);
  complex operator-=(const complex &c);
  complex operator*=(const complex &c);
  complex operator/=(const complex &c);
  complex operator^=(const int x); //带等于号的四则运算与乘方

  friend const bool operator==(const complex &c1, const complex &c2);
  friend const bool operator!=(const complex &c1, const complex &c2);

  friend ostream &operator<<(ostream &output, const complex &c);
  friend istream &operator>>(ostream &input, complex &c); //重构输入输出

  double mod()
  {
    return sqrt(r * r + i * i);
  }
  double angle()
  {
    return atan2(i, r);
  } //模长与辐角，辐角是弧度制
};

complex &complex::operator=(const complex &c)
{
  r = c.r;
  i = c.i;
  return *this;
}

const complex operator+(const complex &c1, const complex &c2)
{
  return complex(c1.r + c2.r, c1.i + c2.i);
}

const complex operator-(const complex &c1, const complex &c2)
{
  return complex(c1.r - c2.r, c1.i - c2.i);
}

const complex operator*(const complex &c1, const complex &c2)
{
  return complex(c1.r * c2.r - c1.i * c2.i, c1.i * c2.r + c1.r * c2.i);
}

complex complex::operator+=(const complex &c)
{
  complex t = *this + c;
  *this = t;
  return *this;
}

complex complex::operator-=(const complex &c)
{
  complex t = *this - c;
  *this = t;
  return *this;
}

complex complex::operator*=(const complex &c)
{
  complex t = *this * c;
  *this = t;
  return *this;
}

complex complex::operator/=(const complex &c)
{
  complex t = *this / c;
  *this = t;
  return *this;
}

complex complex::operator^=(const int x)
{
  complex t = *this ^ x;
  *this = t;
  return *this;
}

const complex complex::operator^(const int x)
{
  for (int i = 0; i < x - 1; i++)
    (*this) *= (*this);
  return *this;
}

const complex operator/(const complex &c1, const complex &c2)
{
  complex t1;
  t1 = complex(c1.r, c1.i) * complex(c2.r, -c2.i);
  double frac = c2.r * c2.r + c2.i * c2.i;
  return complex(t1.r / frac, t1.i / frac);
}

const bool operator==(const complex &c1, const complex &c2)
{
  if (abs(c1.r - c2.r) < MIN && abs(c1.i - c2.i) < MIN)
    return 1;
  else
    return 0;
}

const bool operator!=(const complex &c1, const complex &c2)
{
  if (abs(c1.r - c2.r) < MIN && abs(c1.i - c2.i) < MIN)
    return 0;
  else
    return 1;
}

ostream &operator<<(ostream &output, const complex &c)
{
  if (abs(c.i) > MIN)
  {
    if (abs(c.r) > MIN)
    {
      if (c.i > 0)
        output << c.r << '+' << c.i << 'j';
      else
        output << c.r << c.i << 'j';
    }
    else
      output << c.i << 'j';
  }
  else
  {
    if (abs(c.r) > MIN)
      output << c.r;
    else
      output << 0;
  }
  //注意小量忽略
  return output;
}

istream &operator>>(istream &input, complex &c)
{
  double re, im;
  input >> re >> im;
  if (!input)
    c = complex(0, 0);
  else
    c = complex(re, im);
  return input;
}

