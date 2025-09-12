import cv2
import numpy as np
import os
from picamera2 import Picamera2

# Set the Qt platform plugin
os.environ["QT_QPA_PLATFORM"] = "xcb"

picam2 = Picamera2()
picam2.configure(picam2.create_preview_configuration(main={"format": 'XRGB8888', "size": (640, 480)}))
picam2.start()


# Initialize face detection model
face_cascade = cv2.CascadeClassifier(cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

while True:
    # frame = cv2.imread('test.jpg')
    frame = picam2.capture_array()
    frame2 = frame.copy()

    # Convert the captured frame to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Detect faces in the grayscale image
    faces = face_cascade.detectMultiScale(gray, 1.1, 4)
        
    for (x, y, w, h) in faces:
        # Draw a rectangle around each detected face
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)
        box_kernel = np.ones((15, 15), np.float32) / (15 * 15)
        lp_kernel = np.array([
			[0,  0,  -1, -1, -1,  0,  0],
			[0, -1,  -3, -3, -3, -1,  0],
			[-1,-3,   0,  7,  0, -3, -1],
			[-1,-3,   7, 24,  7, -3, -1],
			[-1,-3,   0,  7,  0, -3, -1],
			[0, -1,  -3, -3, -3, -1,  0],
			[0,  0,  -1, -1, -1,  0,  0],
		], dtype=np.float32)

        frame[y:y + h, x:x + w] = cv2.filter2D(frame[y:y + h, x:x + w], -1, box_kernel)
        frame2[y:y + h, x:x + w] = cv2.filter2D(frame[y:y + h, x:x + w], -1, lp_kernel)

    # Display the processed video frame
    cv2.imshow("Face Detection_box_kernel", frame)
    cv2.imshow("Face Detection with LP_kernel", frame2)

    # Press 'q' to exit the loop and close the window
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cv2.destroyAllWindows()
