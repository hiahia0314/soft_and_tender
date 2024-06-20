# #从平台库导入YOLO类
# from ultralytics import YOLO
# #从模型文件构建model
# model = YOLO("yolov8n.pt")
# #对某张图片进行预测
# results = model.predict("12.png")
# 打印识别结果
import os
imgpath="./12.png"

import subprocess
child = subprocess.Popen('dir',shell=True)
