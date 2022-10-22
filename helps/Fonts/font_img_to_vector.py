import cv2 as cv
import numpy as np
from collections import Counter

for i in "fmtz":
    img = cv.imread("./"+i+".png")
    print("\tdrawableMatrix[\'" + i.upper() + "\'] = {")
    img2 = cv.resize(img, (20, 25))
    gray_image = cv.cvtColor(img2, cv.COLOR_BGR2GRAY)
    # cv.imshow("img", gray_image)
    # cv.waitKey(0)

    for elems in gray_image:
        print("\t\t{", end="")
        for elem in elems:
            if elem > 200:
                print(0, end=", ")
            else:
                print(1, end=", ")
        print("},")

    print("\t\t} ")
    print()