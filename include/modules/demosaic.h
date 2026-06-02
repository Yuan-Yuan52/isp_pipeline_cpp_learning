#pragma once 
#include <opencv2/opencv.hpp>

class Demosaic {
    public : 
        Demosaic();
        cv::Mat process(const cv::Mat& input);
};