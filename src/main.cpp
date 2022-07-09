#include <opencv2/opencv.hpp>
#include "../function/color_recognition.hpp"
#include "../function/PID.hpp"
#include <iostream>
int main()
{
    cv::VideoCapture cap;
    cv::Mat img, img_two, result_img;
    cv::Point2f photo_center;
    cap.open(0, cv::CAP_V4L2);
    if (cap.isOpened())
    {
        cv::namedWindow("Video");
    }
    else
    {
        std::cout << "failed" << std::endl;
        return 1;
    }
    while (1)
    {
        int key_value = cv::waitKey(1);
        if (key_value == 27)
        {
            break;
        }
        cap >> img;
        result_img=img.clone();
        color::color_Range(img, img_two, color::red);
        color::color_center(img_two, result_img, photo_center);
        imshow("Video", result_img);
    }
    cv::destroyAllWindows(); //破坏窗口
    cap.release();           //释放内存
    return 0;
}