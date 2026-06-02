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

    //邊緣偵測
    Mat Edge ;
    Canny (img , Edge , 50 , 150 );

    //定義kernel
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3 ));

    //eRosion
    Mat Erosion ;
    erode (Edge , Erosion ,kernel);

    //Diation 
    Mat Dilation ;
    dilate (Edge , Dilation , kernel);

    // Opening 開運算
    Mat opened;
    morphologyEx( Edge, opened, MORPH_OPEN, kernel);

    // Closing 閉運算
    Mat closed;
    morphologyEx(Edge, closed, MORPH_CLOSE, kernel);
    
    imshow("Original Image", img);
    imshow("Edge Detection", Edge);
    imshow("Erosion", Erosion);
    imshow("Dilation", Dilation);
    imshow("Opened", opened);
    imshow("Closed", closed);

    waitKey(0); 

    return 0;

}