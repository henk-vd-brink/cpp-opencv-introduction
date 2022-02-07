#include <iostream>
#include <stdio.h>

#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include "Detectors/FaceDetector.hpp"

int main()
{
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::cout << "Hello CMake." << std::endl;

    cv::VideoCapture video_capture(0);
    FaceDetector face_detector;

    while (1)
    {
        if (!video_capture.isOpened())
        {
            std::cout << "Video Capture Failed" << std::endl;
            break;
        }

        cv::Mat frame;
        video_capture >> frame;

        auto rectangles = face_detector.detect_face_rectangles(frame);
        cv::Scalar color(0, 105, 205);
        for (const auto &r : rectangles)
        {
            cv::rectangle(frame, r, color, 4);
        }

        cv::namedWindow("Video", cv::WINDOW_AUTOSIZE);
        cv::imshow("Video", frame);

        const int esc_key = 27;
        if (cv::waitKey(10) == esc_key)
        {
            std::cout << "Video Capture Aborted" << std::endl;
            break;
        }
    }

    cv::destroyAllWindows();
    video_capture.release();

    return 0;
}