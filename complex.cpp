#include <iostream>
#include <math.h>
using namespace std;

class complex
{
private:
  double r;
  double i;

public:
  complex() : r(0), i(0) {}
  complex(double r, double i) : r(r), i(i) {}
  complex(complex &c) : r(c.r), i(c.i) {}
  ~complex() {}

  friend ostream &operator<<(ostream &output, complex &c);
  friend istream &operator>>(ostream &input, complex &c);
};

ostream &operator<<(ostream &output, complex &c)
{
  output << c.r << '+' << c.i << 'j' << endl;
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

int main()
{
  return 0;
}