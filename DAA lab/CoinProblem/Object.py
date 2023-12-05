


import cv2
import numpy as np

# Initialize the webcam
cap = cv2.VideoCapture(0)

# Define the range of colors to track (e.g., green)
# lower_color = np.array([35, 100, 100])
# upper_color = np.array([85, 255, 255])
# for yellow
lower_color = np.array([20, 100, 100])   
upper_color = np.array([30, 255, 255]) 
#black
# lower_color = np.array([0, 0, 0])
# upper_color = np.array([180, 30, 30])
while True:
    # Read a frame from the webcam
    ret, frame = cap.read()

    if not ret:
        break

    # Convert the frame to the HSV color space
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Create a mask to identify the color within the specified range
    color_mask = cv2.inRange(hsv_frame, lower_color, upper_color)

    # Find contours in the mask
    contours, _ = cv2.findContours(color_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

    # Draw bounding rectangles around the detected objects
    for contour in contours:
        x, y, w, h = cv2.boundingRect(contour)
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # Display the frame with tracking
    cv2.imshow("Object Tracking", frame)

    # Break the loop when 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the webcam and close OpenCV windows
cap.release()
cv2.destroyAllWindows()
