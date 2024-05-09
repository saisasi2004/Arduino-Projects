import cv2
import numpy as np
import serial
import time


arduino = serial.Serial('COM5', 9600)
time.sleep(2)


def detect_red_color(image):
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower_red = np.array([0, 100, 100])
    upper_red = np.array([10, 255, 255])
    mask = cv2.inRange(hsv, lower_red, upper_red)
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.erode(mask, kernel, iterations=1)
    mask = cv2.dilate(mask, kernel, iterations=2)
    res = cv2.bitwise_and(image, image, mask=mask)
    return mask, res


cap = cv2.VideoCapture(0)

while True:

    mask, red_objects = detect_red_color(frame)

    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        area = cv2.contourArea(contour)
            x, y, w, h = cv2.boundingRect(contour)
            posX = int((x + w / 2) * 180 / frame.shape[1])  # Map X position to servo range (0-180)
            posY = int((y + h / 2) * 180 / frame.shape[0])  # Map Y position to servo range (0-180)
            arduino.write(f"{posX} {posY}\n".encode())

    cv2.imshow('Red Objects Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
