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


    // 轉灰階
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);

    // 一般 Histogram 等化
    Mat equalized;
    equalizeHist(gray, equalized);

    // CLAHE（限制對比度的進階版）
    Ptr<CLAHE> clahe = createCLAHE(2.0, Size(8, 8));
    Mat clahe_result;
    clahe->apply(gray, clahe_result);

    // 顯示
    imshow("Original Gray", gray);
    imshow("Equalized", equalized);
    imshow("CLAHE", clahe_result);

    waitKey(0);
    return 0;
}