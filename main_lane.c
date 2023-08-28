#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    VideoCapture cap("adas.mp4"); // Replace with video path or camera index
    if (!cap.isOpened()) {
        printf("Error opening video feed.\n");
        return -1;
    }

    namedWindow("Lane Detection", WINDOW_NORMAL);
    resizeWindow("Lane Detection", 800, 600);

    while (true) {
        Mat frame;
        cap >> frame;

        if (frame.empty())
            break;

        // Convert frame to grayscale
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Apply Gaussian blur
        GaussianBlur(gray, gray, Size(5, 5), 0);

        // Apply Canny edge detection
        Mat edges;
        Canny(gray, edges, 50, 150);

        // Apply region of interest mask
        Mat mask = Mat::zeros(edges.size(), edges.type());
        Point pts[4] = {
            Point(100, frame.rows),
            Point(300, 200),
            Point(500, 200),
            Point(frame.cols - 100, frame.rows)
        };
        fillConvexPoly(mask, pts, 4, Scalar(255, 255, 255));
        bitwise_and(edges, mask, edges);

        // Apply Hough Line Transform
        std::vector<Vec2f> lines;
        HoughLines(edges, lines, 1, CV_PI / 180, 100);

        // Draw detected lines on the frame
        Mat lineFrame = frame.clone();
        for (size_t i = 0; i < lines.size(); i++) {
            float rho = lines[i][0], theta = lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a * rho, y0 = b * rho;
            pt1.x = cvRound(x0 + 1000 * (-b));
            pt1.y = cvRound(y0 + 1000 * (a));
            pt2.x = cvRound(x0 - 1000 * (-b));
            pt2.y = cvRound(y0 - 1000 * (a));
            line(lineFrame, pt1, pt2, Scalar(0, 0, 255), 2);
        }

        imshow("Lane Detection", lineFrame);

        if (waitKey(1) == 27) // Exit on Esc key press
            break;
    }

    cap.release();
    destroyAllWindows();
    
    return 0;
}

