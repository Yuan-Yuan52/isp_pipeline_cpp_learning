#pragma once 
#include <opencv2/opencv.hpp>

class Blacklevel {
    public:
        Blacklevel();
        cv::Mat process (const cv::Mat& input , int black_level);
};  
