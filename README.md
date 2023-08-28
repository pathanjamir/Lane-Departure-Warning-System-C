# Lane-Departure-Warning-System-C
This repository contains a Lane Departure Warning System implemented in C using computer vision techniques. The system utilizes image processing to detect lane markings in a simulated camera feed and provides warnings if the vehicle deviates from the center of the lane.

Project Overview:

The Lane Departure Warning System is designed to simulate a basic Advanced Driver Assistance System (ADAS) feature using the C programming language. The system processes camera frames using OpenCV and detects lane markings, helping users understand how such systems work at a fundamental level.

Key Features:

Simulated camera input stream for testing lane departure scenarios.
Lane detection using color thresholding and edge detection.
Calculation of lateral offset from the center of the lane.
Warning generation if the lateral offset exceeds a defined threshold.
User interface to visualize the camera feed, lane markings, and warnings.
Getting Started:

Clone this repository to your local machine.
Set up the required dependencies, including OpenCV.
Compile and run the C code to simulate the Lane Departure Warning System.
Follow the on-screen instructions to observe lane detection and warning generation.
Repository Structure:

src/: Contains the C source code files.
samples/: Includes sample camera frames for testing.
README.md: Detailed instructions on setting up and running the system.
LICENSE: The license under which this project is shared.
Future Improvements:

Integrate with a real camera feed for real-world testing.
Explore more advanced lane detection techniques.
Enhance the user interface for better visualization.
Incorporate additional ADAS features, such as collision detection.
Contributing:

Contributions are welcome! Feel free to open issues or submit pull requests for any improvements or fixes.

License:

This project is not licensed. 

Acknowledgments:

This project is inspired by the need to understand and experiment with ADAS concepts.
The use of OpenCV greatly simplifies image processing tasks.
Disclaimer:

This Lane Departure Warning System is for educational purposes only and is not intended for real-world use. Always prioritize safety when driving.

