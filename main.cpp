#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat addGaussianNoise(Mat img, double variance) {
    Mat result;
    img.convertTo(result, CV_64F);  // 先轉成 64F

    // 建立和 img 相同大小和通道數的噪聲
    Mat noise(img.size(), CV_64F);
    if (img.channels() == 3) {
        Mat noise_3ch;
        randn(noise, 0, sqrt(variance) * 255);
        vector<Mat> channels = {noise, noise, noise};
        merge(channels, noise_3ch);
        result += noise_3ch;
    } else {
        randn(noise, 0, sqrt(variance) * 255);
        result += noise;
    }

    cv::threshold(result, result, 0, 0, THRESH_TOZERO);
    cv::threshold(result, result, 255, 255, THRESH_TRUNC);
    result.convertTo(result, CV_8U);
    return result;
}

int main() {

    Mat img = imread("C:\\Users\\user\\Desktop\\IMG_2024.jpg");
    if (img.empty()){
        std::cout << "Could not read the image" << std::endl;
        return -1;
    }

    Mat resized;
    resize(img, resized, Size(), 0.2, 0.2); // 不要直接 in-place，先縮放到暫存再賦值回 img
    img = resized;

    Mat noisy = addGaussianNoise(img, 0.01); // 添加高斯噪声，方差为0.01

    Mat mean_filtered,gaussian_blured,median_filtered;
    blur(noisy, mean_filtered, Size(5, 5)); // 均值滤波
    GaussianBlur(noisy, gaussian_blured, Size(7, 7), 4); // 高斯滤波
    medianBlur(noisy, median_filtered, 7); // 中值滤波

    cout << "Noisy PSNR: " << PSNR(img, noisy) << " dB" << endl;
    cout << "Mean Filter PSNR: " << PSNR(img, mean_filtered) << " dB" << endl;
    cout << "Gaussian Blur PSNR: " << PSNR(img, gaussian_blured) << " dB" << endl;
    cout << "Median Filter PSNR: " << PSNR(img, median_filtered) << " dB" << endl;  

    imshow("Original Image", img);
    imshow("Noisy Image", noisy);
    imshow("Mean Filtered Image", mean_filtered);
    imshow("Gaussian Blurred Image", gaussian_blured);
    imshow("Median Filtered Image", median_filtered);
    waitKey(0);
    return 0;

}