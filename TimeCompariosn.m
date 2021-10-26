range=14;
r=[1:range];
n=2.^r;
load("data.txt");
TimeofDFT=data(:,1);
TimeofDIT=data(:,2);
TimeofDIF=data(:,3);

figure;

plot(n,TimeofDFT,'-om');
hold on;
plot(n,TimeofDIT,'-og');
plot(n,TimeofDIF,'-ob');
title("Time Comparsion of FFT & DFT");
xlabel("n");
ylabel("Time/s");
legend("FFT","DIT-FFT","DIF-FFT");



