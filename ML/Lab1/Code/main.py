from PIL import Image

import os

import cv2


def delete_files_in_folder(folder_path):
    for filename in os.listdir(folder_path):
        file_path = os.path.join(folder_path, filename)
        try:
            if os.path.isfile(file_path):
                os.remove(file_path)
        except Exception as e:
            print(f'Ошибка при удалении файла {file_path}. {e}')


# 1111111111111111111111111111111111111111111
str_roman_num = 'I';
count = 13
delete_files_in_folder('res')
delete_files_in_folder('imageRotate')

for i in range(1, 14):
    im = Image.open(str_roman_num + '-' + str(i) + '.png')
    im.save('imageRotate/' + str_roman_num + '-' + str(i) + '.png', quality=95)
    im_rotate = im.rotate(5, expand=True, fillcolor='white')
    str_j = str(5)
    im_rotate.save('imageRotate/' + str_roman_num + '-' + str(count) + '.png', quality=95)
    count = count + 1
    for j in range(8, 21, 4):
        im_rotate = im.rotate(j, expand=True, fillcolor='white')
        str_j = str(j)
        im_rotate.save('imageRotate/' + str_roman_num + '-' + str(count) + '.png', quality=95)
        count = count + 1
    # im_rotate = im.rotate(-5, expand=True, fillcolor='white')
    # str_j = str(-5)
    # im_rotate.save('imageRotate/' + str_roman_num + '-'+str(count) + '.png', quality=95)
    # count = count + 1
    for j in range(-8, -21, -4):
        im_rotate = im.rotate(j, expand=True, fillcolor='white')
        str_j = str(j)
        im_rotate.save('imageRotate/' + str_roman_num + '-' + str(count) + '.png', quality=95)
        count = count + 1

    im.close()

# 1111111111111111111111111111111111111111111


# 22222222222222222222222222222222222222222222

# str_roman_num='Cvinculum'

delete_files_in_folder('res')

for i in range(1, 120):
    img = Image.open('imageRotate/' + str_roman_num + '-' + str(i) + '.png')
    # пропорциональное изменение картинки
    img.thumbnail(size=(28, 28))
    img.save('res/' + str_roman_num + '-' + str(i) + '.png', quality=95)

    img.close()

# 22222222222222222222222222222222222222222222


# 33333333333333333333333333333333

# str_roman_num='Cvinculum'

delete_files_in_folder('imageblack')

for i in range(1, 101):
    image = cv2.imread('res/' + str_roman_num + '-' + str(i) + '.png')

    # convert image to grayscale
    image_grayscale = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    # convert image to black and white
    thresh, image_black = cv2.threshold(image_grayscale, 170, 255, cv2.THRESH_BINARY)

    cv2.imwrite('imageblack/' + str_roman_num + '-' + str(i) + '.bmp', image_black)
# 33333333333333333333333333333333
