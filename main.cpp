#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

    Mat img = imread("C:\\Users\\user\\Desktop\\IMG_2024.jpg");
    if (img.empty()){
        std::cout << "Could not read the image" << std::endl;
        return -1;
    }

    Mat resized;
    resize(img, resized, Size(), 0.2, 0.2); // 不要直接 in-place，先縮放到暫存再賦值回 img
    img = resized;

    // BGR → HSV
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);

    // BGR → YUV
    Mat yuv;
    cvtColor(img, yuv, COLOR_BGR2YUV);

    // 顯示
    imshow("Original BGR", img);
    imshow("HSV", hsv);
    imshow("YUV", yuv);

    // 印出同一個像素在不同色彩空間的值
    Vec3b px_bgr = img.at<Vec3b>(100, 100);
    Vec3b px_hsv = hsv.at<Vec3b>(100, 100);
    Vec3b px_yuv = yuv.at<Vec3b>(100, 100);

    cout << "BGR: " << (int)px_bgr[0] << " " << (int)px_bgr[1] << " " << (int)px_bgr[2] << endl;
    cout << "HSV: " << (int)px_hsv[0] << " " << (int)px_hsv[1] << " " << (int)px_hsv[2] << endl;
    cout << "YUV: " << (int)px_yuv[0] << " " << (int)px_yuv[1] << " " << (int)px_yuv[2] << endl;

    waitKey(0);
    return 0;
}