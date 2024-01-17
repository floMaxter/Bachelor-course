fileExp= fopen('2.2.1.7.LaplaceOperatorImage.txt','r');
A = fscanf(fileExp, '%f');
figure(1)
hist(A,80);


fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,000000.txt','r');
B = fscanf(fileExp, '%f');
figure(2)
hist(B,80);

fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,100000.txt','r');
C = fscanf(fileExp, '%f');
figure(3)
hist(C,80);

fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,200000.txt','r');
D = fscanf(fileExp, '%f');
figure(4)
hist(D,80);


fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,300000.txt','r');
E = fscanf(fileExp, '%f');
figure(5)
hist(E,80);

fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,400000.txt','r');
F = fscanf(fileExp, '%f');
figure(6)
hist(F,80);

fileExp= fopen('2.2.1.7.LaplaceOperatorImage1,500000.txt','r');
G = fscanf(fileExp, '%f');
figure(7)
hist(G,80);