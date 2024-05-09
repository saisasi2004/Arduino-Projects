import cv2
import numpy as np

# Function to identify blue color in an image
def detect_blue_color(image):
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
    lower_blue = np.array([100, 100, 100])
    upper_blue = np.array([150, 255, 255])
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.erode(mask, kernel, iterations=1)
    mask = cv2.dilate(mask, kernel, iterations=2)
    res = cv2.bitwise_and(image, image, mask=mask)
    return mask, res

# Open a video capture device (change 0 to your camera index if multiple cameras are available)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()  # Capture frame-by-frame

    # Detect blue color in the frame
    mask, blue_objects = detect_blue_color(frame)

    # Display the video feed with blue objects
    cv2.imshow('Original', frame)
    cv2.imshow('Blue Objects Detection', blue_objects)

    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit the loop
        break

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()
