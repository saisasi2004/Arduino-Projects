import cv2
import mediapipe as mp
import serial

# Initialize hand tracking module
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()

# Initialize serial communication with Arduino
ser = serial.Serial('COM7', 9600)  # Change 'COM5' to the port where your Arduino is connected

def count_fingers_landmarks(hand_landmarks):
    # Implement your logic to count fingers based on hand landmarks
    # For simplicity, you can start with counting fingertips (landmarks[3], landmarks[7], landmarks[11], landmarks[15], landmarks[19])
    # You may need to adjust these indices based on the actual landmarks detected
    return [1 if hand_landmarks.landmark[i].y < hand_landmarks.landmark[i - 1].y else 0 for i in [3, 7, 11, 15, 19]]

# Open webcam
cap = cv2.VideoCapture(0)

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    # Convert the BGR image to RGB
    rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

    # Process the frame to find hands
    results = hands.process(rgb_frame)

    if results.multi_hand_landmarks:
        for hand_landmarks in results.multi_hand_landmarks:
            # Count fingers
            finger_states = count_fingers_landmarks(hand_landmarks)

            # Send the finger states to Arduino
            ser.write(','.join(map(str, finger_states)).encode())

            # Draw landmarks on the image
            mp.solutions.drawing_utils.draw_landmarks(frame, hand_landmarks, mp_hands.HAND_CONNECTIONS)

    cv2.imshow('Hand Tracking', frame)

    if cv2.waitKey(1) & 0xFF == 27:  # Press 'Esc' to exit
        break

cap.release()
cv2.destroyAllWindows()
