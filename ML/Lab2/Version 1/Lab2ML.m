My_picturies = imageDatastore('D:\Studies\ML\Lab2\Pictures_numbers\');
imgs = readall(My_picturies);
perm = randperm(numel(My_picturies.Files), 20);
for i=1:20
 subplot(4,5,i);
 imshow(imgs{perm(i)});
end


% Очищаем рабочую область MATLAB и
% устанавливаем палитру в градациях серого цвета
close all, clear all  clc;
warning off;
clf;
figure(gcf);
colormap(gray)
echo on

% Прогружаем картинки
% =========================
digits = 10; % количество разных цифр
N = 2; % Количество картинок, забираемых из папки "InitPic\"
imVert = 28; % Разрешение каждой картинки по вертикали
imHorz = 28; % Разрешение каждой картинки по горизонтали
pictures = 255*ones(imVert*imHorz, N); % Инициализируем массив для всех распознаваемых картинокtargets = zeros(N, digits); % Обнуляем массив эталонов

for i=1:digits
 targets(((i-1)*10+1):(i*10), i) = 1;
end

for i=1:N
 % Загрузка распознаваемых картинок
 pic = double(imread(strcat('D:\Studies\ML\Lab2\Pictures_numbers\', num2str(i)),'png'));

 assert(size(pic,1) == imVert && size(pic,2) == imHorz);
 % Преобразование двумерной картинки в одномерный массив (по строкам)
 vecP = reshape(pic, imHorz*imVert, []);
 % Сохранение полученного массива в общую матрицу распознаваемых картинок
 pictures(:,i) = vecP;
end

alphabet = pictures; % Дублируем наши картинки
[R,Q] = size(alphabet);
[S2,Q] = size(targets);

% =================================
[alphabet_pp,meanA,stdA] = prestd(alphabet);
P = alphabet_pp;
T = targets;

% Выводим исходные картинки
figure(1)
subplot(211)
colormap hot
imagesc(alphabet)
xlabel('letter #'); ylabel('Входной вектор');
subplot(212)
imagesc(targets)
xlabel('letter #'); ylabel('Выходной вектор');

% Выведем цифры в матричной форме
figure(2)
title('Изображения без шума')
for i = 1:N
 subplot(N/5,5,i)
 letter = reshape(alphabet(:,i), imHorz, imVert);
 colormap(1 - gray);
 imagesc(letter')
 axis off;
end

% Определяем входные данные для сети NNFF
% =========================================
P = pictures; % тренировочные данные
T = targets'; % эталонные данные
% Определение архитектуры сети
% ====================
% Сеть будет иметь 10 нейронов в скрытом слое
S1 = 10;
net = newff(minmax(P),[S1],{'softmax'},'trainscg');
net = init(net);

% Тренировка нейронной сети
% ==================
net.performFcn = 'crossentropy'; % Кросс-энтропия
net.trainParam.goal = 0; % Сумма квадрата ошибки.
net.trainParam.show = 20; % Частота появления прогресса (в эпохе)
net.trainParam.epochs = 1000; % Максимальное количество эпох.
net.trainParam.min_grad = 1e-6;
net.trainParam.max_fail = 6;
net.trainParam.sigma = 5e-5;
net.trainParam.lambda = 5e-7;

[net,tr] = train(net,P,T); % Обучение сети
O = sim(net,P); % Тестирование сети
C = full(compet(O))

Error = sse(C-T)/(2*Q) % Вычисление ошибки распознавания

figure
imagesc(O)

figure
imagesc(C)

% Корректировка весов слоя
%=====================================
net.IW{1,1} = 1e-3*randn(S1,R);
net.b{1} = 1e-3*randn(S1,1);
[net,tr] = train(net,P,T);% Дообучение с новыми значениями весов

O = sim(net,P);% Тестирование сети
C = full(compet(O));
Error = sse(C-T)/(2*Q) % Вычисление ошибки распознавания


figure
imagesc(O)
figure
imagesc(C)

[net,tr] = train(net,P,T);

figure(3)
title('Рабочая выборка цифр')
for i = 1:10
 subplot(2,5,i)
 k=(i-1)*10+1;
 letter = reshape(alphabet(:,k), imHorz, imVert);
 colormap(1 - gray);
 imagesc(letter')
 axis off;
end

% использование своей сети
for i=1:digits
OO (:,i) = sim(net,P(:,(i-1)*10+1));
end
figure
imagesc(OO)

% Отобразим матрицу весов (ее можно сохранить и использоать в своих проектах как предобученную 
net.IW {:}