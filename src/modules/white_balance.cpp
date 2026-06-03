#include "modules/white_balance.h"
#include <iostream>

using namespace cv;
using namespace std;

WhiteBalance::WhiteBalance() {
    // 初始化白平衡模組
}

Mat WhiteBalance::process(const Mat& input, float r_gain, float g_gain, float b_gain) {

    cout << "White Balance gains -R " << r_gain;

    Mat result;
    input.convertTo(result , CV_32F);

    for (int y = 0 ; y < result.rows ; y++){
        for (int x = 0 ; x < result.cols ; x++){
            float val = result.at<float>(y,x);
            if (y % 2 == 0 && x % 2 == 0)
            val *= r_gain;
            else if (y % 2 == 1 && x % 2 == 1)
            val *= b_gain;
            else 
            val *= g_gain;

            result.at <float>(y,x) = val ;
        }
    }
    
    threshold (result , result , 65535 , 65535 ,THRESH_TRUNC);
    result.convertTo(result , CV_16UC1);
    
    return input.clone();
}