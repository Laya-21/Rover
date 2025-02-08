import cv2
import numpy as np


def adaptive_thresholding(frame):
    """
    Apply adaptive thresholding to improve segmentation in varying lighting conditions.
    Args:
        frame: Input image (BGR).
    Returns:
        adaptive_thresh: Grayscale image after adaptive thresholding.
    """
    # Convert to grayscale
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Apply adaptive thresholding
    adaptive_thresh = cv2.adaptiveThreshold(
        gray,
        255,
        cv2.ADAPTIVE_THRESH_MEAN_C,  # Adaptive mean thresholding
        cv2.THRESH_BINARY,
        11,  # Block size for local region
        2  # Constant subtracted from the mean (C parameter)
    )

    return adaptive_thresh


def color_based_terrain_detection(frame):
    """
    Detect terrain types based on color in the HSV color space with adaptive thresholding.
    Args:
        frame: Input image (BGR).
    Returns:
        terrain_overlay: Image with terrain types highlighted.
    """
    # Convert the image to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Define color ranges for different terrains (in HSV)
    # Green: grass, Brown: soil, Blue: water
    lower_green = np.array([25, 52, 72])
    upper_green = np.array([102, 255, 255])
    green_mask = cv2.inRange(hsv, lower_green, upper_green)

    lower_brown = np.array([10, 50, 50])
    upper_brown = np.array([25, 255, 255])
    brown_mask = cv2.inRange(hsv, lower_brown, upper_brown)

    lower_blue = np.array([100, 50, 50])
    upper_blue = np.array([140, 255, 255])
    blue_mask = cv2.inRange(hsv, lower_blue, upper_blue)

    # Apply adaptive thresholding to the masks to handle different lighting conditions
    green_mask = cv2.bitwise_and(green_mask, adaptive_thresholding(frame))
    brown_mask = cv2.bitwise_and(brown_mask, adaptive_thresholding(frame))
    blue_mask = cv2.bitwise_and(blue_mask, adaptive_thresholding(frame))

    # Combine masks for all terrain types
    combined_mask = cv2.bitwise_or(green_mask, brown_mask)
    combined_mask = cv2.bitwise_or(combined_mask, blue_mask)

    # Create an overlay with color-coded terrain regions
    terrain_overlay = cv2.bitwise_and(frame, frame, mask=combined_mask)

    return terrain_overlay, combined_mask


# Main program
if __name__ == "__main__":
    cap = cv2.VideoCapture(0)  # Use a webcam (replace 0 with video file path if needed)

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Detect terrain types
        terrain_overlay, terrain_mask = color_based_terrain_detection(frame)

        # Display the original frame, mask, and terrain overlay
        cv2.imshow("Original Frame", frame)
        cv2.imshow("Terrain Mask", terrain_mask)
        cv2.imshow("Terrain Overlay", terrain_overlay)

        # Exit on pressing 'q'
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()