digitDatasetPath = fullfile('D:\Studies\ML\Lab3\ph');
imds = imageDatastore(digitDatasetPath, ...
'IncludeSubfolders',true, ...
'LabelSource','foldernames');
%]создание хранилища (imageDataStore)
%[
figure
numImages = 200;
perm = randperm(numImages, 20);
for i = 1:20
subplot(4, 5, i);
imshow(imds.Files{perm(i)});
end

[imdsTrain,imdsValidation] = splitEachLabel(imds,0.75,'randomize');
imageSize = [300 300 3];
layers = [
imageInputLayer(imageSize)% вх слой (размер вх данных, кол-во каналов цвета)

averagePooling2dLayer(2, 'Stride', 2) %усреднение пулинг - подвыборка для уменьш пространственных размеров вх данных
%размер 2*2, шаг 2


convolution2dLayer(5,128,'Padding','same') %слой свертки
%сверточная операция к вх данным с пом фильтров
%кол-во, размер фильтров, шаг по умолчанию 1
%заполнение (пад) сейм - размер вх = разм вых
batchNormalizationLayer%нормализация
reluLayer%функция активации

convolution2dLayer(2,64,'Padding','same') % Настройте параметры по необходимости
batchNormalizationLayer
reluLayer

dropoutLayer(0.35) % Добавлен слой Dropout

fullyConnectedLayer(10) %полносвязный слой
softmaxLayer%слой активации
classificationLayer];%слой классификации
%] арх нейросети
%[параметры обучения
options = trainingOptions('sgdm', ...%градиент спуск
'MaxEpochs',15, ... % Задаем количество эпох обучения
...
'InitialLearnRate', 0.0001,...%скорость обучения
'ValidationData',imdsValidation, ...
'Verbose',false, ... %- подробная инфа по каждой эпохе
'ValidationFrequency',5, ... - проверка каждые 15 эпох
'Plots','training-progress'); %Вывод графиков
%]
% При необходимости выполняем аугментацию
%[аугментация
imageAugmenter = ...
imageDataAugmenter('RandRotation',[-5,5], ... - поворот от -5 до 5 градусов
'RandXTranslation',[-2,2],'RandYTranslation',[-2,2]); % - сдвиг по осям X Y от -2 до 2 пикселей
augimds = augmentedImageDatastore(imageSize,imds, 'DataAugmentation',imageAugmenter);
% создание объекта хранилища аугментированных данных
% ауг - новые модели, получаемые от трансформации к исх изобр
%]
% Обучаем сеть
net = trainNetwork(augimds,layers,options);
% Рассчитываем метрики обучения (оценка точности)
YPred = classify(net,imdsValidation);
YValidation = imdsValidation.Labels;
accuracy = sum(YPred == YValidation)/numel(YValidation);