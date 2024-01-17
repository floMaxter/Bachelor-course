figure(1)
subplot(2,3,1);
fileExp= fopen('2.3.1.3OriginalBefore.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);
subplot(2,3,2);
fileExp= fopen('2.3.3.GammaTransformOriginalAfter0,100000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,3);
fileExp= fopen('2.3.3.GammaTransformOriginalAfter0,500000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,4);
fileExp= fopen('2.3.3.GammaTransformOriginalAfter1,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,5);
fileExp= fopen('2.3.3.GammaTransformOriginalAfter2,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,6);
fileExp= fopen('2.3.3.GammaTransformOriginalAfter8,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);


figure(2)
subplot(2,3,1);
fileExp= fopen('2.3.1.3LightImageBefore.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);
subplot(2,3,2);
fileExp= fopen('2.3.3.GammaTransformLightAfter0,100000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,3);
fileExp= fopen('2.3.3.GammaTransformLightAfter0,500000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,4);
fileExp= fopen('2.3.3.GammaTransformLightAfter1,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,5);
fileExp= fopen('2.3.3.GammaTransformLightAfter2,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,6);
fileExp= fopen('2.3.3.GammaTransformLightAfter8,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);



figure(3)
subplot(2,3,1);
fileExp= fopen('2.3.1.3DarkImageBefore.txt','r');
E = fscanf(fileExp, '%f');
hist(E,80);
subplot(2,3,2);
fileExp= fopen('2.3.3.GammaTransformDarkAfter0,100000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,3);
fileExp= fopen('2.3.3.GammaTransformDarkAfter0,500000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,4);
fileExp= fopen('2.3.3.GammaTransformDarkAfter1,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,5);
fileExp= fopen('2.3.3.GammaTransformDarkAfter2,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);
subplot(2,3,6);
fileExp= fopen('2.3.3.GammaTransformDarkAfter8,000000.txt','r');
F = fscanf(fileExp, '%f');
hist(F,80);





