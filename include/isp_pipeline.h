#pragma once 
#include <opencv2/opencv.hpp>
#include <libraw/libraw.h>
#include "modules/black_level.h"
#include "modules/demosaic.h"
#include "modules/noise_reduction.h"
#include "modules/white_balance.h"

class ISPPipeline {
    public:
        ISPPipeline();

        cv::Mat process(const std::string& raw_file);

    private:
        Blacklevel black_level_;
        Demosaic demosaic_;
        NoiseReduction noise_reduction_;
        WhiteBalance white_balance_;
};