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

# Function to identify blue color in an image
def detect_blue_color(image):
    # Convert the image from BGR to HSV color space
    hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Define the range of blue color in HSV
    lower_blue = np.array([100, 100, 100])
    upper_blue = np.array([150, 255, 255])

    # Create a mask for blue color
    mask = cv2.inRange(hsv, lower_blue, upper_blue)

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
    mask_red, red_objects = detect_red_color(frame)

    # Find contours around red objects
    contours_red, _ = cv2.findContours(mask_red, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw square box and label around detected red objects
    for contour_red in contours_red:
        area_red = cv2.contourArea(contour_red)
        if area_red > 1000:  # Set a threshold for minimum area to filter out small detections
            x_red, y_red, w_red, h_red = cv2.boundingRect(contour_red)
            cv2.rectangle(frame, (x_red, y_red), (x_red + w_red, y_red + h_red), (0, 0, 255), 2)
            cv2.putText(frame, 'Red Color Detected', (x_red, y_red - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 255), 2)

    # Detect blue color in the frame
    mask_blue, blue_objects = detect_blue_color(frame)

    # Find contours around blue objects
    contours_blue, _ = cv2.findContours(mask_blue, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw square box and label around detected blue objects
    for contour_blue in contours_blue:
        area_blue = cv2.contourArea(contour_blue)
        if area_blue > 1000:  # Set a threshold for minimum area to filter out small detections
            x_blue, y_blue, w_blue, h_blue = cv2.boundingRect(contour_blue)
            cv2.rectangle(frame, (x_blue, y_blue), (x_blue + w_blue, y_blue + h_blue), (255, 0, 0), 2)
            cv2.putText(frame, 'Blue Color Detected', (x_blue, y_blue - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)

    # Display the video feed with boxes and labels
    cv2.imshow('Object Detection', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to exit the loop
        break

# Release the capture and close all windows
cap.release()
cv2.destroyAllWindows()
