clear all;
clc;
range=14;
r=[1:range];
n=2.^r;
load("TimeData.txt");
TimeofDFT=TimeData(:,1);
TimeofDIT=TimeData(:,2);
TimeofDIF=TimeData(:,3);

figure;

plot(n,TimeofDFT,'-om');
hold on;
plot(n,TimeofDIT,'-og');
plot(n,TimeofDIF,'-ob');
title("Time Comparsion of FFT & DFT");
xlabel("n");
ylabel("Time/s");
legend("DFT","DIT-FFT","DIF-FFT");



