import cv2
import numpy as np

# Function to identify red color in an image
def detect_red_color(image):
    # Convert the image from BGR to HSV color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Define the range of red color in HSV
    lower_red = np.array([0, 100, 100])
    upper_red = np.array([10, 255, 255])

    # Create a mask for red color
    mask = cv2.inRange(hsv, lower_red, upper_red)

    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(image, image, mask=mask)

    return res

# Open a video capture device (change 0 to your camera index if multiple cameras are available)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()  # Capture frame-by-frame

    # Detect red color in the frame
    red_objects = detect_red_color(frame)

    # Display the original and red-colored objects side by side
    cv2.imshow('Original', frame)
    cv2.imshow('Red Objects', red_objects)

    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit the loop
        break

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()
