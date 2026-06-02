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
    resize(img , img , Size(640,480));

    //色彩轉換
    Mat gray , hsv ;
    cvtColor(img ,gray,COLOR_BGR2GRAY);
    cvtColor(img ,hsv,COLOR_BGR2HSV);

    //濾波
    Mat blurred , denoised ; 
    GaussianBlur(gray , blurred , Size(5,5) , 1.5);
    bilateralFilter(img , denoised , 9 , 75 , 75 );

    //邊緣偵測
    Mat edges ;
    Canny (gray , edges , 50 , 150);

    //存檔
    imwrite("output_gray.jpg" , gray);
    imwrite("output_hsv.jpg" , hsv);
    imwrite("output_denoised.jpg" , denoised);
    
    imshow("Original Image" , img);
    imshow("Gray Image" , gray);
    imshow("Gaussian Blurred Image" , blurred);
    imshow("Bilateral Filtered Image" , denoised);
    imshow("Canny Edges" , edges);
    waitKey(0); 

    return 0;

}