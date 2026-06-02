#pragma once
#include <opencv2/opencv.hpp>

class NoiseReduction {
    public:
        NoiseReduction();
        cv::Mat process(const cv::Mat& input);
};