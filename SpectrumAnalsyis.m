clear all;
clc;
fs = 1000;
Ts = 1 / fs;
N = 1024;
load("FreqData.txt");
plot(FreqData);
title("s(t)的FFT频谱")
xlabel("n")
ylabel("abs(FFT(s))")