#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
    // 建立一張 300x300 的黑色圖片
    Mat img = Mat::zeros(300, 300, CV_8UC3);

    // 畫一個白色矩形
    rectangle(img, Point(50, 50), Point(250, 250), Scalar(255, 255, 255), 2);

    // 顯示圖片
    imshow("Test", img);
    waitKey(0);

    return 0;
}