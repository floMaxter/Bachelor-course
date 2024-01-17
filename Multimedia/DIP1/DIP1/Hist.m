figure(1)
fileExp= fopen('14B1.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);

figure(2)
fileExp= fopen('14R1.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);



figure(3)
fileExp= fopen('14G1.txt','r');
C = fscanf(fileExp, '%f');
hist(C,80);


figure(4)
fileExp= fopen('14Y1.txt','r');
D = fscanf(fileExp, '%f');
hist(D,80);


figure(5)
fileExp= fopen('14Cb1.txt','r');
A = fscanf(fileExp, '%f');
hist(A,80);


figure(6)
fileExp= fopen('14Cr1.txt','r');
B = fscanf(fileExp, '%f');
hist(B,80);