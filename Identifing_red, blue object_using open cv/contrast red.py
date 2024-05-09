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

    # Perform morphological operations to enhance the mask
    kernel = np.ones((5, 5), np.uint8)
    mask = cv2.erode(mask, kernel, iterations=1)
    mask = cv2.dilate(mask, kernel, iterations=2)

    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(image, image, mask=mask)

    return mask, res

# Open a video capture device (change 0 to your camera index if multiple cameras are available)
cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()  # Capture frame-by-frame

    # Detect red color in the frame
    mask, red_objects = detect_red_color(frame)

    # Find contours around red objects
    contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw square box and label around detected red objects
    for contour in contours:
        area = cv2.contourArea(contour)
        if area > 1000:  # Set a threshold for minimum area to filter out small detections
            x, y, w, h = cv2.boundingRect(contour)
            cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
            cv2.putText(frame, 'Red Color Detected', (x, y - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

    # Display the video feed with boxes and labels
    cv2.imshow('Red Objects Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit the loop
        break

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()
