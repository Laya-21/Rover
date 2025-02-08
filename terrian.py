import cv2
import numpy as np

def color_based_shadow_detection(frame, brightness_threshold=50, saturation_threshold=50):
    """
    Detect shadows using HSV color space.
    Args:
        frame: Input image (BGR).
        brightness_threshold: Threshold for low brightness (V channel).
        saturation_threshold: Minimum saturation (S channel) for shadow detection.
    Returns:
        shadow_mask: Binary mask highlighting shadow regions.
    """
    # Convert the image to HSV color space
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    h, s, v = cv2.split(hsv)

    # Detect shadows: low brightness and moderate saturation
    shadow_mask = cv2.inRange(v, 0, brightness_threshold)  # Low brightness
    shadow_mask = cv2.bitwise_and(shadow_mask, shadow_mask, mask=(s > saturation_threshold).astype(np.uint8) * 255)

    return shadow_mask

# Main program
if _name_ == "_main_":
    cap = cv2.VideoCapture(0)  # Use a webcam (replace 0 with a video file path if needed)

    while True:
        ret, frame = cap.read()
        if not ret:
            break

        # Detect shadows
        shadow_mask = color_based_shadow_detection(frame)

        # Create an overlay highlighting shadow regions
        shadow_overlay = cv2.cvtColor(shadow_mask, cv2.COLOR_GRAY2BGR)  # Convert mask to 3-channel
        overlay = cv2.addWeighted(frame, 0.8, shadow_overlay, 0.4, 0)  # Blend original and shadow mask

        # Display the results
        cv2.imshow("Original Frame", frame)
        cv2.imshow("Shadow Mask", shadow_mask)
        cv2.imshow("Shadow Overlay", overlay)

        # Exit on pressing 'q'
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()