import cv2
import numpy as np
import pandas as pd
import csv

# Variable to be Changed and Threshold Process if needed as per image
FILE_NAME = "nirajan.png"
scale_percent = 50 # percent of original size
contour_number = 0

im = cv2.imread("./img/" + FILE_NAME)
#resizing the image
width = int(im.shape[1] * scale_percent / 100)
height = int(im.shape[0] * scale_percent / 100)
dim = (width, height)
im = cv2.resize(im, dim, interpolation = cv2.INTER_AREA)

imgray = cv2.cvtColor(im, cv2.COLOR_BGR2GRAY)
imgray = cv2.GaussianBlur(imgray, (5, 5), 0)
cv2.imshow("Blurred Image", imgray)
ret,thresh = cv2.threshold(imgray, 20, 255, cv2.THRESH_BINARY_INV)
cv2.imshow("Threshold Image", thresh)

# In OpenCV, finding Contours is like finding white object from black background
contours, hierarchy = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
img = cv2.drawContours(im, contours, -1, (0, 255, 0), 3)
cv2.imshow("Contour Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()

# Writing to the csv file
X = []
Y = []
data = []
header = ['x', 'y']
print("No. of contours : ", len(contours))
for contour in contours[contour_number]:
    for x, y in contour:
        data.append([x, y])

with open("./csv/" + FILE_NAME.split(".")[0] + ".csv", "w", encoding='UTF8') as f:
    writer = csv.writer(f)

    writer.writerow(header)
    for row in data:
        writer.writerow(row)

