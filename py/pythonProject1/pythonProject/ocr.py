import cv2
from paddleocr import PPStructure,draw_structure_result,save_structure_res
import os
os.environ["KMP_DUPLICATE_LIB_OK"]="TRUE" # key
table_engine = PPStructure(show_log=True)

import os

is_exists = os.listdir('./img')#读取图片文件位置
print(is_exists)
for i in is_exists:
    img_path = 'img/'+i
    img = cv2.imread(img_path)
    result = table_engine(img)
    print(result)
    save_structure_res(result, './', 'ex01')#存放位置
    print(i)

