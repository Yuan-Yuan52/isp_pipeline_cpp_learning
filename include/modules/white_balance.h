#pragma once
#include <opencv2/opencv.hpp>

class WhiteBalance {
public:
    WhiteBalance();
    cv::Mat process(const cv::Mat& input, float r_gain, float g_gain, float b_gain);
};