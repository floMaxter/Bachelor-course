figure(1)
subplot(2,1,1);
fileExp= fopen('LenaDcY.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);
subplot(2,1,2);
fileExp= fopen('LenaCodeDcY.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);


figure(2)
subplot(2,1,1);
fileExp= fopen('LenaDcCb.txt','r');
C = fscanf(fileExp, '%f');
hist(C,80);
subplot(2,1,2);
fileExp= fopen('LenaCodeDcCb.txt','r');
D = fscanf(fileExp, '%f');
hist(D,80);


figure(3)
subplot(2,1,1);
fileExp= fopen('LenaDcCr.txt','r');
A = fscanf(fileExp, '%f');
hist(A,80);
subplot(2,1,2); 
fileExp= fopen('LenaCodeDcCr.txt','r');
B = fscanf(fileExp, '%f');
hist(B,80);