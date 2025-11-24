    #include <opencv2/opencv.hpp>
    #include <iostream>

    int main() {
        // Open the default camera (usually index 0)
        cv::VideoCapture cap(0);

        // Check if the camera opened successfully
        if (!cap.isOpened()) {
            std::cerr << "Error: Could not open camera." << std::endl;
            return -1;
        }

        cv::Mat frame; // Mat object to store camera frames

        while (true) {
            cap >> frame; // Read a new frame from the camera

            // Check if the frame was successfully read
            if (frame.empty()) {
                std::cerr << "Error: Could not read frame." << std::endl;
                break;
            }
            
            // Display the frame in a window named "Camera Feed"
            // -- this shows a camera in a mirrored fashion directly from the frame
            // cv::imshow("Camera Feed Mirrored", frame);

            // Flip the frame horizontally to un-mirror it like it does above
            cv::Mat normal_view_frame;
            cv::flip(frame, normal_view_frame, 1);
            cv::imshow("Camera Feed Unmirrored", normal_view_frame);
            

            // Wait for 30 milliseconds and check for key press
            // 'q' key to exit the loop
            if (cv::waitKey(30) == 'q') {
                break;
            }
        }

        // Release the camera and destroy all windows
        cap.release();
        cv::destroyAllWindows();

        return 0;
    }