figure(1)
subplot(2,1,1);
fileExp= fopen('BaboonDcY.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);
subplot(2,1,2);
fileExp= fopen('BaboonCodeDcY.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);


figure(2)
subplot(2,1,1);
fileExp= fopen('BaboonDcCb.txt','r');
C = fscanf(fileExp, '%f');
hist(C,80);
subplot(2,1,2);
fileExp= fopen('BaboonCodeDcCb.txt','r');
D = fscanf(fileExp, '%f');
hist(D,80);


figure(3)
subplot(2,1,1);
fileExp= fopen('BaboonDcCr.txt','r');
A = fscanf(fileExp, '%f');
hist(A,80);
subplot(2,1,2); 
fileExp= fopen('BaboonCodeDcCr.txt','r');
B = fscanf(fileExp, '%f');
hist(B,80);