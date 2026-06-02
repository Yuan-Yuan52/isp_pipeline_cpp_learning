#include "modules/white_balance.h"
#include <iostream>

using namespace cv;

WhiteBalance::WhiteBalance() {
    // 初始化白平衡模組
}

Mat WhiteBalance::process(const Mat& input, float r_gain, float g_gain, float b_gain) {

    return input.clone();
}