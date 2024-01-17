from PIL import Image, ImageDraw
import os
import pandas as pd

def main():
    tree = list(os.walk('D:\\Clear_Dataset'))
    # tree = list(os.walk('D:\\Studies\\ML\\Lab1\\Clear_Dataset'))
    table = {'tag': []}
    for i in range(0, 784):
        table[i] = []

    for i in tree[1:]:
        for j in i[2]:
            table['tag'].append(j[:j.rfind('-')])
            img = Image.open(i[0] + '\\' + j)
            padding = int((img.size[0] - 28) / 2)
            width = img.size[0]
            height = img.size[1]
            img = img.crop((padding, padding, width - padding, height - padding))
            pix = img.load()
            lenght = 0
            for h in range(height - padding * 2):
                for w in range(width - padding * 2):
                    r, g, b = pix[(h, w)]
                    if r + g + b > 0:
                        table[lenght].append(0)
                    else:
                        table[lenght].append(1)
                    lenght += 1

    df = pd.DataFrame(table)
    # df.to_excel('D:\\Dataset_rqzmetka.xlsx')
    df.to_excel('D:\\Studies\\ML\\Lab1\\Dataset_numbers\\Dataset.xlsx')

if __name__ == '__main__':
    main()