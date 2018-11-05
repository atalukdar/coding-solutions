import cv2
import numpy as np
import os
import PIL


vidcap = cv2.VideoCapture('yoyo.mp4')
success,image = vidcap.read()
count = 0
success = True

while success:
    success,image = vidcap.read()
    cv2.imwrite("frame%d.jpg" % count, image)   
    count += 1

#extracting frames from a video

from PIL import ImageFont
from PIL import Image
from PIL import ImageDraw

countvar=0
font = ImageFont.truetype("/usr/share/fonts/dejavu/DejaVuSans.ttf", 25)
img = Image.new("RGBA", (200,200), (120,20,20))

for countvar in range (len(count)):
    draw = ImageDraw.Draw(img)
    draw.text((0,0), "This is a test", (255,255,0), font=font)
    draw = ImageDraw.Draw(img)
    img.save("countvar.jpg")
    countvar+=1
    #writing on all the images

def frames_to_video(inputpath,outputpath,fps):
    image_array = []
    files = [f for f in os.listdir(inputpath) if isfile(join(inputpath, f))]
    files.sort(key = lambda x: int(x[5:-4]))

for i in range(len(files)):
    img = cv2.imread(inputpath + files[i])
    size =  (img.shape[1],img.shape[0])
    img = cv2.resize(img,size)
    image_array.append(img)
    fourcc = cv2.VideoWriter_fourcc('D', 'I', 'V', 'X')
    out = cv2.VideoWriter(outputpath,fourcc, fps, size)

for i in range(len(image_array)):
    out.write(image_array[i])
    out.release()
    inputpath = 'folder path'
    outpath =  'video file path/video.mp4'
    fps = 30
    frames_to_video(inputpath,outpath,fps)
    #converting frames to VideoWriter
 
